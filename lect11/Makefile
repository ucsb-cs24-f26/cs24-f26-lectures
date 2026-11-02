CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

.PHONY: all clean

all: iptracking

iptracking: iptracking.cpp hashtable.h
	$(CXX) $(CXXFLAGS) iptracking.cpp -o iptracking

clean:
	rm -f iptracking