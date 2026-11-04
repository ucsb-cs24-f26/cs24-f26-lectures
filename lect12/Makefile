CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

.PHONY: all clean

all: traffic_activity

traffic_activity: traffic_activity.cpp
	$(CXX) $(CXXFLAGS) traffic_activity.cpp -o traffic_activity

clean:
	rm -f traffic_activity iptracking