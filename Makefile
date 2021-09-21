
windows: compile linkwin

linux: compile linklin


compile:
	g++ -I src/include -c main.cpp

linkwin:
	g++ main.o -o main.exe

linklin:
	g++ main.o -o main.out