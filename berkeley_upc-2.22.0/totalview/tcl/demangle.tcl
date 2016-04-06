

global demangled_type_strings;

proc get_array_dim {dim} {
    set dim [string range $dim 1 [string length $dim]];
    set has_threads [split $dim "H"];
    set dim "\[$dim\]";
    if {[llength $has_threads] > 1} then {
	    set len [string length $dim];
	    set first  [string range $dim 0 [expr $len - 3]];
	    set dim "$first*THREADS\]";
    }
    db_puts "DIMENSION $dim";
    return $dim;
}

proc is_array_descriptor {desc} {
    
    #for the time being this ignores K/r/V qualifiers  
    if {[string index $desc 0] == "A"} {
	return "1";
    } else {
	return "0";
    }

}


proc  BMN_demangle {tid mangled_name {demangled_name ""} {is_array 0}} {
   
    global demangled_type_strings;
    
    set prefix_name $demangled_name;
    
    db_puts "CALL $tid $mangled_name $demangled_name";
    set ll  [llength [array names demangled_type_strings $tid]];
    if { $ll == 1 && $tid != "0"} {
	db_puts "FOUND $demangled_type_strings($tid)";
	return $demangled_type_strings($tid);
    }
    
    if {[string range  $mangled_name 0 5]== "__BMN_" } {
	# top level call, strip BMN
	set first [expr 6];
    } else {
	set first [expr 0];
    }
    if { [string index $mangled_name $first] == "r" } {
	set first [expr $first+1];
	set demangled_name "restrict $demangled_name";
    }

   if { [string index $mangled_name $first] == "V" } {
	set demangled_name "volatile $demangled_name";
	set first [expr $first+1];
    }

    if { [string index $mangled_name $first] == "K" } {
	set first [expr $first+1];
	set demangled_name "const $demangled_name";
    }

    if { [string index $mangled_name $first] == "R" } {
	set first [expr $first+1];
	set tname [split [string range $mangled_name $first [string length $mangled_name]] "_"];
	set tname [lindex $tname 0];
	set first [expr $first + [expr [string length $tname] + 1]];

		    
	set temp [BMN_demangle 0 [string range $mangled_name $first [string length $mangled_name]]  ""];
	
	set result "$temp  shared \[$tname\]";
	if {$tid != "0"} {
	    set demangled_type_strings($tid) $result;
	}
	return  $result;
    }
    
    
     if { [string index $mangled_name $first] == "S" } {
	set first [expr $first+1];
	set tname [split [string range $mangled_name $first [string length $mangled_name]] "_"];
	set tname [lindex $tname 0];
	set first [expr $first + [expr [string length $tname] + 1]];

# can't handle strict yet. Uncomment this when we can
#	set demangled_name "strict shared \[$tname\] $demangled_name";
	 set temp [BMN_demangle 0 [string range $mangled_name $first [string length $mangled_name]]  ""];
	set result "$temp  shared \[$tname\]";
	if {$tid != "0"} {
	    set demangled_type_strings($tid) $result;
	}
	return  $result;
	
	
	
    }
    
    if { [string index $mangled_name $first] == "P" } {
	set first [expr $first+1];
	set tname [string range $mangled_name $first [string length $mangled_name]];
	set result "[BMN_demangle 0 $tname " "] \*";

	
	if {$tid  != "0"} {
	    set demangled_type_strings($tid) $result;
	}
	return $result;
    }

    if { [string index $mangled_name $first] == "A" } {
	set mangled_name [string range $mangled_name $first [string length $mangled_name]];
	set first [expr 0];
	set lst [split $mangled_name "_"];
	set dim [lindex $lst 0];
	set next [string length $dim];
	set rest [string range $mangled_name [expr $next+1] [string length $mangled_name]];
	set dim [get_array_dim $dim];
	set dim "($dim";
	#extract the other dimensions
	while {[is_array_descriptor $rest] == "1"} {
	    set lst [split $rest "_"];
	    set new_dim [lindex $lst 0];
	    set next [string length $new_dim];
	    set rest [string range $rest  [expr $next+1] [string length $rest]];
	    set new_dim [get_array_dim $new_dim];
	    set dim "$dim $new_dim";
	}
	set dim "$dim)";
	set name [BMN_demangle 0 $rest "" $is_array];
	set result "$name $dim";
	if {$tid != "0"} {
	    set demangled_type_strings($tid) $result;
	}
	return $result;
    }
    
    if { [string index $mangled_name $first] == "N" } {
	
	set first [expr $first+1];
	set tname [string range $mangled_name $first [string length $mangled_name]];
	regexp {(^[0-9]+)} $tname nlen;
	set tlen [string length $mangled_name];
	set tname [string range $mangled_name [expr $tlen-$nlen] $tlen];
	set demangled_name "struct $tname $demangled_name";
    }
    
    
    #by now I should have only basic types.
    if { [string index $mangled_name $first] == "w" } then {
	set demangled_name "wchar_t $demangled_name";
    } elseif { [string index $mangled_name $first] == "b" } then {
	set demangled_name "bool $demangled_name";
    } elseif { [string index $mangled_name $first] == "c" } then {
	set demangled_name "char $demangled_name";
    } elseif { [string index $mangled_name $first] == "a" } then {
	set demangled_name "signed char $demangled_name";
    } elseif { [string index $mangled_name $first] == "h" } then {
	set demangled_name "unsigned char  $demangled_name";
    } elseif { [string index $mangled_name $first] == "s" } then {
	set demangled_name "short $demangled_name";
    } elseif { [string index $mangled_name $first] == "t" } then {
	set demangled_name "unsigned short $demangled_name";
    } elseif { [string index $mangled_name $first] == "i" } then {
	set demangled_name "int $demangled_name";
    } elseif { [string index $mangled_name $first] == "j" } then {
	set demangled_name "unsigned int $demangled_name";
    } elseif { [string index $mangled_name $first] == "l" } then {
	set demangled_name "long $demangled_name";
    } elseif { [string index $mangled_name $first] == "m" } then {
	set demangled_name "unsigned long $demangled_name";
    } elseif { [string index $mangled_name $first] == "x" } then {
	set demangled_name "long long  $demangled_name";
    } elseif { [string index $mangled_name $first] == "y" } then {
	set demangled_name "unsigned long long $demangled_name";
    } elseif { [string index $mangled_name $first] == "f" } then {
	set demangled_name "float $demangled_name";
    } elseif { [string index $mangled_name $first] == "d" } then {
	set demangled_name "double $demangled_name";
    } elseif { [string index $mangled_name $first] == "e" } then {
	set demangled_name "long double $demangled_name";
    } elseif { [string index $mangled_name $first] == "v" } then {
	set demangled_name "void $demangled_name";
    } elseif { [string index $mangled_name $first] == "n" } then {
	set demangled_name "__int128 $demangled_name";
    } elseif { [string index $mangled_name $first] == "g" } then {
	set demangled_name "__float128  $demangled_name";
    } else {
	set demangled_name "UNRECOGNIZED_BASE [string index $mangled_name $first] $demangled_name";
    }
    

    if {$prefix_name == ""} {
	    set demangled_type_strings($tid) $demangled_name;
    }
    return $demangled_name;

}  
