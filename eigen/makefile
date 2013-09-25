all: myEigenFunctions.o matrixtest.o
	g++ -lpthread -ldl -o a.out myEigenFunctions.o matrixtest.o
	rm -rf *.o 

myEigenFunctions.o:
	g++ -g -c myEigenFunctions.cpp -o myEigenFunctions.o

matrixtest.o:
	g++ -g -c matrixtest.cpp -o matrixtest.o

