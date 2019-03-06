test: test.o
	g++ -o $@ $< `pkg-config --libs aruco`
movie: movie.o
	g++ -o $@ $< `pkg-config --libs aruco`
.cpp.o:
	g++ -o $@ -c $< `pkg-config --cflags aruco`
