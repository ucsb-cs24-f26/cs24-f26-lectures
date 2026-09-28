CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# === THREE PROGRAMS ===
# 1. flawedlist     - Poor version (Activity 1: students critique this)
# 2. demo         - Improved CustomList version, built live in class
# 3. complex_demo - Complex class, for the constructor iClicker sequence

POOR_TARGET = flawedlist
POOR_OBJECTS = main.o

IMPROVED_TARGET = demo
IMPROVED_SOURCES = demo.cpp CustomList.cpp
IMPROVED_OBJECTS = $(IMPROVED_SOURCES:.cpp=.o)
HEADERS = CustomList.h

COMPLEX_TARGET = complex_demo
COMPLEX_SOURCES = complex_demo.cpp Complex.cpp
COMPLEX_OBJECTS = $(COMPLEX_SOURCES:.cpp=.o)
COMPLEX_HEADERS = Complex.h

all: $(POOR_TARGET) $(IMPROVED_TARGET) $(COMPLEX_TARGET)

$(POOR_TARGET): $(POOR_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(POOR_TARGET) $(POOR_OBJECTS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

$(IMPROVED_TARGET): $(IMPROVED_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(IMPROVED_TARGET) $(IMPROVED_OBJECTS)

demo.o: demo.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c demo.cpp -o demo.o

CustomList.o: CustomList.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c CustomList.cpp -o CustomList.o

$(COMPLEX_TARGET): $(COMPLEX_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(COMPLEX_TARGET) $(COMPLEX_OBJECTS)

complex_demo.o: complex_demo.cpp $(COMPLEX_HEADERS)
	$(CXX) $(CXXFLAGS) -c complex_demo.cpp -o complex_demo.o

Complex.o: Complex.cpp $(COMPLEX_HEADERS)
	$(CXX) $(CXXFLAGS) -c Complex.cpp -o Complex.o

clean:
	rm -f $(POOR_OBJECTS) $(POOR_TARGET) $(IMPROVED_OBJECTS) $(IMPROVED_TARGET) $(COMPLEX_OBJECTS) $(COMPLEX_TARGET)

run-poor: $(POOR_TARGET)
	./$(POOR_TARGET)

run-demo: $(IMPROVED_TARGET)
	./$(IMPROVED_TARGET)

run-complex: $(COMPLEX_TARGET)
	./$(COMPLEX_TARGET)

valgrind-poor: $(POOR_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(POOR_TARGET)

valgrind-demo: $(IMPROVED_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(IMPROVED_TARGET)

# Leak detection tools don't work reliably on modern macOS, SSH to CSIL to run valgrind

.PHONY: all clean run-poor run-demo run-complex valgrind-poor valgrind-demo
