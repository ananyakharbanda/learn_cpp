CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -g

.PHONY: all clean

raii_file: raii_file_wrapper.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

vector: my_vector.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

unique_ptr: my_unique_ptr.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

animal: inheritance.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	rm -f a.out raii_file vector unique_ptr animal

all: raii_file vector unique_ptr animal

