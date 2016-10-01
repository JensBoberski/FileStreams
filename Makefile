CC=g++
CFLAGS=-c -Wall -Werror
LDFLAGS=
LIBDIR=.
LIBS=-lfilestreams
all: libfilestreams.so

filestreams.o: filestreams.cc filestreams.hh
	${CC} ${CFLAGS} -fpic filestreams.cc

libfilestreams.so: filestreams.o
	g++ -shared -o libfilestreams.so filestreams.o

clean:
	rm *o


test: test.o libfilestreams.so
	${CC} test.o -o test ${LIBS} -L${LIBDIR}

test.o: test.cc filestreams.hh
	${CC} ${CFLAGS} test.cc

run_test: test
	$(shell ./test)
	cat test*.dat
	rm test*.dat test.o test

