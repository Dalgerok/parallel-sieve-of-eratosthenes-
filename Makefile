CXX = g++
CPPFLAGS = -fopenmp

SOURCES = misc.cpp soe.cpp soe_odd_only.cpp soe_odd_only_blockwise.cpp soe_odd_only_blockwise_sqrt.cpp main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $@

.cpp.o: *.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean