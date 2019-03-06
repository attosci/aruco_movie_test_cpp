main: main.o
	g++ -o $@ $< `pkg-config --libs aruco`
.cpp.o:
	g++ -o $@ -c $< `pkg-config --cflags aruco`
