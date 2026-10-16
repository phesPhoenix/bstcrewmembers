bst: main.o BST.o
	g++ main.o BST.o -o bst

main.o: main.cpp BST.h
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

clean:
	rm -f *.o bst
