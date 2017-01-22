proc external {input} {
	set inversions 0
	set length [llength $input]
	for {set i 0} {$i<$length} {incr i} {
		for {set j [expr $i+1]} {$j<$length} {incr j} {
			if {[lindex $input $i]>[lindex $input $j]} {
				incr inversions
			}
		}
	}
	if {($inversions%2)==0} {
		return "$inversions  чёт"
	} else {
		return "$inversions  нечёт"
	}
}
source variants.tcl