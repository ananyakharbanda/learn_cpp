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

pure_virtual: pure_virtual.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

virtual_functions: virtual_destructor.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

shapes: shapes.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

prac_shared: prac_shared_ptr.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

shared: my_shared_ptr.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

test_ptr: test_ptr.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

iterators: iterators.cpp;
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	rm -f a.out raii_file vector unique_ptr animal pure_virtual virtual_functions shapes prac_shared shared test_ptr iterators

all: raii_file vector unique_ptr animal pure_virtual virtual_functions shapes shared prac_shared test_ptr iterators
