
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cctype>
#include "store.h"
#include "book.h"


using namespace std;

Store::Store(double cash) : maxSize(3), totalBooks(0)
{
    cashInRegister = cash ;
    bookInventory = new Book[maxSize];
}

Store::~Store()
{
    delete [] bookInventory;
}

void Store::insertBook(const char* title, const char* author, double price, char t)
{
    if(totalBooks == maxSize)   {   resizeList(3); }            //check for space
    
    
    t = toupper(t);                                             //set genre to enum
    Genre g;                                    
    if      (t == 'F')   {   g = FICTION;     }
    else if (t == 'M')   {   g = MYSTERY;     }
    else if (t == 'S')   {   g = SCIFI;       }
    else if (t == 'C')   {   g = COMPUTER;    }

    bookInventory[totalBooks].Set(title, author, g, price);     //create book
    totalBooks++;
}

bool Store::removeBook(const char* title)
{
    int indexNum = findBookIndex(title, 'S');                        //try to find book
    
    if(indexNum >= 0){                                          //adjust price and lower books up
        cashInRegister += bookInventory[indexNum].GetPrice();
        adjustArray(indexNum);
        return true;
    }

    return false;
}

void Store::displayInventory(char type) const
{
    if (type == 'N' && totalBooks == 0) {                       //if there are no books in TOTAL DISPLAY
        cout << "\nNo books currently in inventory\n";
        cout << "\nNumber of books: " << totalBooks << endl;
        cout << "Money in register: $ " << fixed << setprecision(2) <<cashInRegister << endl << endl;
        return;
    }
    

    if(type =='N'){                                             //complete TOTAL DISPLAY
        cout << '\n' << left << setw(30) << "**Title**" << setw(20) << "**Author**" 
        << setw(9) << "**Genre**" << "\t   " << setw(9) << "**Price**\n" << endl;
        for(int i = 0; i < totalBooks; ++i){
            bookInventory[i].Display();
        }
        cout << "\nNumber of books: " << totalBooks << endl;
        cout << "Money in register: $ " << fixed << setprecision(2) << cashInRegister << endl << endl;    
        return;
    }

    type = toupper(type);                                       //set genre type for GENRE DISPLAY
    Genre lookingGenre;
    if      (type == 'F')   {   lookingGenre = FICTION;     }
    else if (type == 'M')   {   lookingGenre = MYSTERY;     }
    else if (type == 'S')   {   lookingGenre = SCIFI;       }
    else if (type == 'C')   {   lookingGenre = COMPUTER;    }

    int totalInGenre = 0;
    double genrePrice = 0;
    for(int i = 0; i < totalBooks; i++){                        //print all books that match genre plus summary for GENRE DISPLAY
        if(lookingGenre == bookInventory[i].GetGenre()){
            if(totalInGenre == 0){
            cout << '\n' << left << setw(30) << "**Title**" << setw(20) << "**Author**" 
            << setw(9) << "**Genre**" << "\t   " << setw(9) << "**Price**\n" << endl;}
            bookInventory[i].Display();
            genrePrice += bookInventory[i].GetPrice();
            totalInGenre++;
        }
    }
    cout << "\nNumber of books in this genre: " << totalInGenre << endl;
    cout << "Total price of books in this genre = $ " << fixed << setprecision(2) << genrePrice << '\n' << endl;

}


int Store::findBookIndex(const char* id, char SellOrFind = 'F') const 
{
    int indexNum = 0;
    while(indexNum < totalBooks){                                       //look for book auhtor or title (only both if finding not selling)
            if(strcmp(id, bookInventory[indexNum].GetTitle()) == 0)
                return indexNum;
            if(strcmp(id, bookInventory[indexNum].GetAuthor()) == 0 && SellOrFind == 'F')
                return indexNum;
        indexNum++;
    }
    return -1;
}


void Store::resizeList(int alteration)                                  //make a new array based off the sum of the 
{                                                                       //  parameter and current allocated size
    int newSize = maxSize + (alteration);
    Book* tempArr = new Book[newSize];

    for(int i = 0; i < newSize; ++i){
        tempArr[i] = bookInventory[i];
    }
    delete[] bookInventory;
    bookInventory = tempArr; 
    maxSize = newSize;
    cout << "** Array being resized to " << maxSize << " allocated slots" << endl;
}


void Store::adjustArray(int indexNum)                                   //adjust book's index numbers for sales
{
    for(int i = indexNum + 1; i < totalBooks - indexNum; ++i){
        bookInventory[indexNum - 1] = bookInventory[i];
    }
    totalBooks--;
    if(maxSize-totalBooks == 4)
        resizeList(-2);
}

void Store::displayBook(int indexNum) const                             //for finding singular books
{
    bookInventory[indexNum].Display();
}

void Store::sort(char option)                                           //extra credit bubble sort :)
{
    option = toupper(option);
    for(int i = 0; i < totalBooks - 1; i++){
        for(int j = 0; j < totalBooks - 1 - i; ++j){
            if(option == 'A'){
                if (strcmp(bookInventory[j].GetAuthor(), bookInventory[j+1].GetAuthor()) > 0){
                    Book temp = bookInventory[j];
                    bookInventory[j] = bookInventory[j+1];
                    bookInventory[j+1] = temp;
                }
            } else {
                if (strcmp(bookInventory[j].GetTitle(), bookInventory[j+1].GetTitle()) > 0){
                    Book temp = bookInventory[j];
                    bookInventory[j] = bookInventory[j+1];
                    bookInventory[j+1] = temp;
                }
            }
            
        }
    }
}