all:
	g++ -I/usr/include/libxml2/ main.cpp -lmlpack -Wl,-rpath=/usr/local/lib
