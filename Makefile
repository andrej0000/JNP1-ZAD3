CXX = g++
CXX_FLAGS = -Wall -std=c++11

ifeq ($(debug),1)
	CXX_FLAGS += -DDEBUG
else
	CXX_FLAGS += -O2
endif

all: main

sejf.o: sejf.h sejf.cc kontroler.h
	$(CXX) $(CXX_FLAGS) sejf.cc -c -o sejf.o

kontroler.o: sejf.h kontroler.h kontroler.cc
	$(CXX) $(CXX_FLAGS) kontroler.cc -c -o kontroler.o

main.o: main.cc
	$(CXX) $(CXX_FLAGS) main.cc -c -o main.o

main: sejf.o kontroler.o main.o
	$(CXX) $(CXX_FLAGS) main.o kontroler.o sejf.o -o main
clean:
	rm -rf main *.o
