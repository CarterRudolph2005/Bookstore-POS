

#include<iomanip>
#include<iostream>
#include<cstring>
#include "book.h"

using namespace std;

Book::Book()
{
    
}

void Book::Set(const char* t, const char* a, Genre g, double p)
{
    strncpy(title, t, 30);
    strncpy(author, a, 20);
    price = p;
    type = g;
}

const char* Book::GetTitle() const
{
    return title;
}

const char* Book::GetAuthor() const
{
    return author;
}

double Book::GetPrice() const
{
    return price;
}

Genre Book::GetGenre() const
{
    return type;
}

void Book::Display() const
{
    char genre[20];
    if(type == COMPUTER)        {   strcpy(genre, "Computer");  }
    else if(type == SCIFI)      {   strcpy(genre, "Sci-Fi");    }
    else if(type == FICTION)    {   strcpy(genre, "Fiction");   }
    else if (type == MYSTERY)   {   strcpy(genre, "Mystery");   }
    
    
    cout << left << setw(30) << title << setw(20) << author 
    << setw(9) << genre << "\t$  " << right << setw(7) 
    << fixed << setprecision(2) << price << endl;
}