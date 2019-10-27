CXX = g++
CXXFLAGS = -Wall -g -g0

my_array: my_array.h my_array.cpp
	$(CXX) $(CXXFLAGS) -c my_array.cpp
test0.o: test0.cpp
	$(CXX) $(CXXFLAGS) -c test0.cpp
test1.o: test1.cpp
	$(CXX) $(CXXFLAGS) -c test1.cpp

test0: test0.o my_array.o
	$(CXX) $(CXXFLAGS) -o test0 test0.o my_array.o
test1: test1.o my_array.o
	$(CXX) $(CXXFLAGS) -o test1 test1.o my_array.o
clean:
	rm -f *.o test0 test1
