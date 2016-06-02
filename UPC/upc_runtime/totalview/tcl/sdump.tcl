
#------------------------------------------------------
proc sdump_one_worker {image_id fhandle} {
    if {[string length $fhandle] == 0} {
	TV::scope dump $image_id
    } else {
	capture -f $fhandle TV::scope dump $image_id
    }
}

#------------------------------------------------------
proc sdump_list_worker {image_id_list file} {
    set f {}
    if {[string length $file] != 0} {
	if [catch {set f [open $file w]}] {
	    error "Open for $file failed"
        }
    }
    foreach image_id $image_id_list {
	sdump_one_worker $image_id $f
    }
    if {[string length $f] != 0} {
	close $f
    }
}

#------------------------------------------------------
proc sdumpin {search_name_regexp {file {}}} {
    sdump_list_worker [soin $search_name_regexp] $file
}

#------------------------------------------------------
proc sdump {{file {}}} {
    sdump_list_worker [lindex [TV::process get [TV::focus_processes] image_ids] 0] $file
}

#------------------------------------------------------
proc sgrepin {search_name_regexp args} {
    sdumpin $search_name_regexp "| sh -c \"grep $args > /dev/tty\""
}

#------------------------------------------------------
proc segrepin {search_name_regexp args} {
    sdumpin $search_name_regexp "| sh -c \"egrep $args > /dev/tty\""
}

#------------------------------------------------------
proc sgrep {args} {
    sdump "| sh -c \"grep $args > /dev/tty\""
}

#------------------------------------------------------
proc segrep {args} {
    sdump "| sh -c \"egrep $args > /dev/tty\""
}

#------------------------------------------------------
# get the id for an image name
#
proc soin {search_name_regexp} {
    set images [TV::symbol get [TV::process get [TV::focus_processes] image_ids] base_name id]
    foreach image $images {
        set image_name [lindex $image 0]
        if [regexp $search_name_regexp $image_name] {
            return [lindex $image 1]
        }
    }
    return ""
}
