//store header file

#include<iostream>
#include "book.h"

class Store{
    
    public: 
    Store(double cash = 0.0);
    ~Store();
    
    void insertBook(const char* title, const char* author, double price, char genre);
    bool removeBook(const char* title);                                 //only looks though titles to remove from array

    int findBookIndex(const char* id, char SellOrFind) const;           //finds where the book is in the array with title or author
    void displayInventory(char type = 'N') const;                       //displays entire inventory on 'N' or genre (with the letter of genre)
    void displayBook(int indexNum) const;                               //displays on book at a time
    void sort(char option);


    private: 
    double cashInRegister;
    Book* bookInventory;
    int maxSize, totalBooks;
    void adjustArray(int indexNum);                                     //array clean up for removing books
    void resizeList(int alteration);                                    //reallocation of space to sum of current maxSize and parameter
};