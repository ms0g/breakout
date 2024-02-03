all:
	MAKE.EXE clean
	TCC.EXE -c -ovga.obj vga.cpp
	TCC.EXE -c -ogame.obj game.cpp
	TCC.EXE -c -okeyboard.obj keyboard.cpp
	TCC.EXE main.cpp vga.obj game.obj keyboard.obj
clean:
	DEL MAIN.EXE
	DEL main.obj
	DEL vga.obj
	DEL game.obj
	DEL keyboard.obj
	
