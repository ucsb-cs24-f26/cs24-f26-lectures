CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# === TWO PROGRAMS ===
# 1. listdemo       - CustomList (all in one file) with no constructor, then a shallow copy
#                     (Demo 1 and Demo 2: crash, diagnose, fix live)
# 2. complex_bigfour - the Big Four on Complex (no heap)

LIST_TARGET = listdemo
LIST_SOURCE = list_demo.cpp

COMPLEX_TARGET = complex_bigfour

all: $(LIST_TARGET) $(COMPLEX_TARGET)

$(LIST_TARGET): $(LIST_SOURCE)
	$(CXX) $(CXXFLAGS) -o $(LIST_TARGET) $(LIST_SOURCE)

$(COMPLEX_TARGET): complex_bigfour.cpp
	$(CXX) $(CXXFLAGS) -o $(COMPLEX_TARGET) complex_bigfour.cpp

clean:
	rm -f $(LIST_TARGET) $(COMPLEX_TARGET)

run-list: $(LIST_TARGET)
	./$(LIST_TARGET)

run-complex: $(COMPLEX_TARGET)
	./$(COMPLEX_TARGET)

.PHONY: all clean run-list run-complex
