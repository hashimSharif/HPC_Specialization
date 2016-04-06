
global real_name;
global start_line;
global end_line;
global bupc_file;

proc sort_lines_by_address {line1 line2} {
    set loc1 [TV::symbol get $line1 location]
    set loc2 [TV::symbol get $line2 location]

    set addr1 [split $loc1];
    set addr1 [lindex $addr1 1];
    set addr1 [string range $addr1 0 [expr [string length $addr1] - 2]];

    set addr2 [split $loc2];
    set addr2 [lindex $addr2 1];
    set addr2 [string range $addr2 0 [expr [string length $addr2] - 2]];

    return [expr [expr $addr1 - $addr2] ];
}

proc  resolve_BLN {old_name} {    
    global real_name;
    global start_line;
    global end_line;

    # tale __BLN__ out
    set old_name [string range $old_name [expr 8]  [string length $old_name]];
    set nl [split $old_name "_"];
    set real_len [lindex $nl 0];
    set start [expr [string length $real_len] + 1];
    set real_name [string range $old_name [expr $start] [expr [expr $start + [expr $real_len]] - 1]];

    #take the length out
    set old_name [string range $old_name [expr [expr $start + [expr $real_len]] + 1] [string length $old_name]];
    set nl [split $old_name "_"];
    
    # the last two in the list are the start and ending lines
    set end_idx [expr [llength $nl] - 1]
    set start_idx [expr ($end_idx-1)]

    set start_line [lindex $nl $start_idx];
    set start_line [string range $start_line [expr 1] [string length $start_line]];
    set end_line [lindex $nl $end_idx];

    # for some reason the translator mangles initialization values giving them BLN names 
    # and appends the "_val" to the BLN name.
    #
    if {$end_line == "val"} {
      set end_line [lindex $nl [expr ($end_idx-1)]]
    }

    set end_line [string range $end_line [expr 1] [string length $end_line]];
}

proc find_line {file_id line direction scope_match} {
    
    set scope_match_name {};
    
    if {$scope_match != 0} {
	set scope_match_name [TV::symbol get $scope_match base_name]
    }
    db_puts "Looking for line: $line in scope: $scope_match_name"
    
    # which direction do we want to search for linenumbers.
    # By default forward but what the heck...allow both.
    #
    set cmp_op ">="
    if {$direction == "backward"} {
	set cmp_op "<="
    }

    # try for the exact line first
    set exact_line [TV::scope lookup $file_id by_properties kind linenumber linenumber "^$line"]
    if {$exact_line != {}} { 
	db_puts "Found exact line: $line"

        # if multiple lines, sort by address
	if { [expr [llength $exact_line] > 1] } {
	    set exact_line [lsort -command sort_lines_by_address $exact_line]
	}
	return $exact_line
    }

    # otherwise we need to search for the next nearest.
    #
    set all_lines  [TV::scope lookup $file_id by_properties kind linenumber]
    if {$all_lines == {}} { 
	db_puts "No linenumbers found for file: $file_id"
	return 0 
    }
    
    set lines {}
    foreach try_line $all_lines {
        set lineval [TV::symbol get $try_line linenumber]
	if {[expr $lineval $cmp_op $line]} {
	    lappend lines $lineval
	}
    }

    # sort the line numbers.
    #
    set line_numbers [lsort -integer $lines]
    foreach lineval $line_numbers {
	set try_line [TV::scope lookup $file_id by_properties kind linenumber linenumber "^$lineval"]	
	if {$try_line == {}} { 
	    # Huh??  We found it before.
	    db_puts "Can't find the linenumber again: $try_line"
	    continue;
	}
	
	# Do we want to match the scope?
	if {$scope_match != 0} {
	    set match_scope_owner [TV::symbol code_unit_by_soid $try_line]
	    
	    if {$match_scope_owner != $scope_match} {
		puts "Warning: Scope mismatch for line: $lineval"
	    }
	} 

	db_puts "Found line: $lineval"
	return $try_line
    }
    
    db_puts "Found NO linenumber for $line:"
    return 0;
}

proc replace_BLN {image_id file_id} {
       
    global real_name;
    global start_line;
    global end_line;
    global bupc_file;

    set var_list [TV::scope walk $image_id by_properties kind variable base_name "^__BLN__N.*$"];
    foreach var $var_list {
	set bname [TV::symbol get $var base_name];
        db_puts [format {%s %s} "\nBLN variable found: " $bname]
	resolve_BLN $bname;
        set file_name [TV::symbol get $file_id base_name]

	TV::symbol set $var base_name $real_name;

        # might need to fixup the loader symbol too.
	set loader_sym [TV::scope lookup $image_id by_properties kind loader_symbol loader_name $bname];

	if {$loader_sym != {}} {
	    set file_path [TV::symbol get $loader_sym  loader_file_path]
	    TV::symbol set $loader_sym loader_file_path $file_path
	    TV::symbol set $loader_sym loader_name $real_name
	}

        # last line is the end of the file.  Just leave this
        # alone.  The scope should already be correct.
        #
	if {$end_line == "L"} {
	    continue;
	}

	db_puts [format {%s %s} "renamed to:" $real_name]
        set save_line $start_line;
	set start_line [find_line $file_id $start_line forward 0];
        if {$start_line == 0} {
	    puts "Can't find line $save_line";
	    continue;
	}

	if { [expr [llength $start_line] > 1] } {
	    set start_line [lindex $start_line 0]
	}

	set start_loc [TV::symbol get $start_line location]
        set start_scope_owner [TV::symbol code_unit_by_soid $start_line]

        if {$start_scope_owner == {}} {
	    puts "Can't find code_unit for line $start_line"
	    continue
	}

	if { [expr [llength $start_scope_owner] > 1] } {
	    puts "Ambiguous code_units found: $start_scope_owner"
	    continue
	}

	set save_line $end_line

        # if the scope is a subroutine, we don't want to match
        # a line that is not in this scope.
        #
	set scope_kind [TV::symbol get $start_scope_owner kind]
	set match_scope $start_scope_owner
	if {$scope_kind != "subroutine"} {
	    set match_scope 0
	}

	set end_line [find_line $file_id $end_line forward $match_scope];
	if {$end_line == 0} {
	    puts "Can't find line $save_line";
	    continue;
	}

	if { [expr [llength $end_line] > 1] } {
	    set end_idx [expr [llength $end_line] - 1]
	    set end_line [lindex $end_line $end_idx]
	}
	set delta 0

        # if we had to search forward for the next line then
        # the scope should end before that line begins.
        #
	set end_line_number [TV::symbol get $end_line linenumber]
	if {$end_line_number != $save_line} {
	    set delta 1
	}

	set end_loc [TV::symbol get $end_line location]
	set ldas [split $start_loc];
	set ldas [lindex $ldas 1];
	set ldas [string range $ldas 0 [expr [string length $ldas] - 2]];
	
	set ldae [split $end_loc];
	set ldae [lindex $ldae 1];
	set ldae [string range $ldae 0 [expr [string length $ldae] - 2]];

	set new_len [expr [expr $ldae - $delta] - [expr $ldas] + 1];

	# Sanity check here.
	if { [expr $new_len] < 0} {
	    puts "Negative length calculated: for line $start_line thru $end_line"

	    # can't leave it like that...things will crash
	    set new_len 1;
	}

        set test_scope [TV::symbol code_unit_by_soid $start_line]
	set scope_len [TV::symbol get $test_scope length]

        # try to re-use a perfectly good block
        #
	if {$scope_len == $new_len} {
	    set new_block $test_scope
	} else {
	    set new_block [TV::scope create $start_scope_owner kind block location $start_loc length $new_len]
	}
	db_puts [format {%s %s %s} "BLOCK:" $new_block "at $start_loc length $new_len"]
	TV::symbol set $var scope_owner $new_block

	# turns out some statics get typedefs with mangled names.  We can delete these
	# and set the target_type to this typedefs type_index.
	#
	set typedef_list [TV::scope walk $image_id by_properties kind typedef base_name "^_type___BLN.*$"];
	foreach typedef $typedef_list {
	    set old_idx [TV::symbol get $typedef type_index];        
	    set targ_idx [TV::symbol get $typedef target_type_index]
	    set targ_type [TV::scope lookup $file_id by_path $targ_idx]
	    
	    if { $targ_type != {} } {
		TV::symbol delete $typedef
		TV::symbol set $targ_type type_index $old_idx
	    }
	}
    }
}

replace_BLN $image_id $file;
