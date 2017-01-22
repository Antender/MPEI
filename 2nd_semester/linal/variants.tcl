set input [read [set fid [open {input} r]]]
close $fid
set variant_counter 1
foreach variant $input {
	append output "$variant_counter) [external $variant]\n"
	incr variant_counter
}
puts [set fid [open {output} w]] $output
close $fid