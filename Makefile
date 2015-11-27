all:
	g++ -Wall -c danylib.cc
	ar rcs libdanylib.a danylib.o

install: all
	#make the directories they go in
	mkdir -p /usr/local/lib/danylib/
	mkdir -p /usr/local/include/danylib/

	#copy the files over
	cp  libdanylib.a /usr/local/lib/danylib/libdanylib.a
	cp danylib.hh /usr/local/include/danylib/danylib.hh
