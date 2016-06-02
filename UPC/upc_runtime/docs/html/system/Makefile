

runtime_spec: upcr.ps upcr.pdf

upcr.ps: upcr.txt
	enscript -B -f Courier8 -M Letter -o upcr.ps upcr.txt

upcr.pdf: upcr.ps
	ps2pdf upcr.ps
