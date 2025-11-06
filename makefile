bookStore: book.o store.o menu.o
	g++ -o test menu.o store.o book.o

menu.o: menu.cpp store.h
	g++ -c menu.cpp

store.o: store.cpp store.h
	g++ -c store.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

make clean: 
	rm -f *.o test 