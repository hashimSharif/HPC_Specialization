
source $env(UPC_TV_SCRIPT_HOME)/demangle.tcl


proc get_containing_file {symbol} {
    if {[TV::symbol get $symbol kind] == "image"} {
       return 0
    }
    while {[TV::symbol get $symbol kind] != "file"} {
	set symbol [TV::symbol get $symbol scope_owner]
    }    
    return $symbol
}


proc resolve_BMN_typedef {scope_id} {

    set typedef_list [TV::scope walk $scope_id by_properties kind typedef base_name "^__BMN_.*$" ];

    # Seems like with some compilers (Compaq) we don't set the base_name to be the BMN name 
    if {$typedef_list == {}} {
	set typedef_list [TV::scope walk $scope_id by_properties kind typedef external_name "^__BMN_.*$" ];	
    }

   foreach typedef_sym $typedef_list {
       set BMN_scope [TV::symbol get $typedef_sym scope_owner]

       # We need to set the language for the scope owners of the typedefs
       # I think were were just lucking out on linux-x86 in that all the
       # BMN typedefs were in the main UPC file which had the UPC language set
       # correctly.
       #
       set file_id [get_containing_file $BMN_scope]
       if {$file_id != "0"} {
          TV::symbol set $file_id language upc
	}

       set old_name [TV::type get $typedef_sym name]; 
       db_puts [format {%s %s} "\nMangled BMN: " $old_name]

       set old_idx [TV::symbol get $typedef_sym type_index];

       set new_name [BMN_demangle $typedef_sym $old_name ""];
       db_puts [format {%s %s} "Demangled BMN: " $new_name]

       set check_return [lindex $new_name 0];
       if {$check_return == "UNRECOGNIZED_BASE"} {
	    puts "mangled name not recognized: $old_name"
	    db_puts "mangled name not recognized: $old_name"
	    continue;
	}

       # delete the typedef 
       TV::symbol delete $typedef_sym;

       if { $new_name == "NOT YET" } {
	   puts [format {%s %s} "shared type not demangled: " $old_name]
	   continue;
       }

       set new_upc_type [TV::scope cast $BMN_scope $new_name]
       if {$new_upc_type == {}} {
	   puts [format {%s %s} "Unable to create shared type for: " $new_name]
	   continue;
       }

       db_puts [format {%s %s} "Find or Create Shared type: " $new_name]
       # set the new shared type_index to be the old type_def's index.
       TV::symbol set $new_upc_type type_index $old_idx
   }
}

resolve_BMN_typedef $image_id;

