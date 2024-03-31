all: compile link

compile:
	g++ -I"C:\\SFML-2.5.1\\include" -c *.cpp

link:
	g++ *.o -o ./exe/main -L"C:\\SFML-2.5.1\\lib" -lsfml-graphics -lsfml-window -lsfml-system
	exe/main


# mingw32-make -f Makefile