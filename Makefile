all:
	MAKE.EXE clean
	TCC.EXE -c -ovga.obj vga.cpp
	TCC.EXE main.cpp vga.obj
clean:
	DEL MAIN.EXE
	DEL main.obj
	DEL vga.obj
	
