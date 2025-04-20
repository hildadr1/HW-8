CXX = g++
CXXFLAGS = -Wall -g

myProgram: matrix.o myProgram.cpp
	$(CXX) $(CXXFLAGS) matrix.o myProgram.cpp -o myProgram

matrix.o: matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -c

run:
	./myProgram

val:
	valgrind ./myProgram

clean:
	rm *.o*
	rm *~
