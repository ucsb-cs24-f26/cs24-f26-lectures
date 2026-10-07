CXX = g++
# -O2 on purpose: the timing lab should reflect real library speed.
# For LLDB, run `make debug` (-O0 -g) instead.
CXXFLAGS = -std=c++11 -Wall -O2

TARGET = stl_tour
LAB = timing_lab

all: $(TARGET) $(LAB)

$(LAB): timing_lab.cpp
	$(CXX) $(CXXFLAGS) -o $(LAB) timing_lab.cpp

$(TARGET): stl_tour.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) stl_tour.cpp

debug: stl_tour.cpp
	$(CXX) -std=c++11 -Wall -g -O0 -o $(TARGET) stl_tour.cpp

clean:
	rm -rf $(TARGET) $(LAB) $(TARGET).dSYM $(LAB).dSYM

run: $(TARGET)
	./$(TARGET)

.PHONY: all debug clean run
