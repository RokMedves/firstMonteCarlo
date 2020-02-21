EXE=a.out
CC=g++
CFLAGS=-Wall -g

$(EXE): mc.o
	$(CC) $(CFLAGS) -o $(EXE)  mc.o mcintegrator.hpp

mc.o: mc.cpp
	$(CC) -c $(CFLAGS) mc.cpp mcintegrator.hpp
clean:
	rm *.o
	rm $(EXE)

cleanEmacs:
	clean
	rm *~
