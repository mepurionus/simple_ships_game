all: removeoldbuild compile link clean


compile:
	g++ -c main.cpp

link:
	g++ main.o -o main.exe
run: all
	main.exe

removeoldbuild:
	del *.exe
	del *.log

clean:
	del main.o