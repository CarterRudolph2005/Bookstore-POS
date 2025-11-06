

#include<iomanip>
#include<iostream>
#include<cctype>
#include "store.h"

using namespace std;

void displayMenu();

int main() {
    char operation; 
    double initialMoneyAmount = 0.0;

    cout << "*** Welcome to Bookstore Inventory Manager ***\n" <<
    "Please input the starting money in the cash register: ";
    cin >> initialMoneyAmount;
    cout << endl;

    Store BookStore(initialMoneyAmount);

    displayMenu();
    do{

        bool isvalid;
        do{
            cout << "> ";
            cin >> operation;
            operation = toupper(operation);
            isvalid = (operation != 'A' && operation != 'F' && operation != 'S' 
            && operation != 'D' && operation != 'G' && operation != 'M' && operation != 'X' && operation != 'O');
            if (isvalid)
                cout << "\nInvalid menu choice. Try again!!" << endl; 
        } while (isvalid);
        
        
        switch (operation){
            case 'A': {
                char title[31], author[21];
                char genre;
                double bookPrice = 0.0;
                
                cout << "Enter title: ";
                cin.ignore();
                cin.getline(title, 31);
                cout << "Enter author: ";
                cin.getline(author, 21);
                
                do{
                cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                cin  >> genre;
                genre = toupper(genre);
                
                if(genre != 'F' && genre != 'M' && genre != 'S' && genre != 'C')
                    cout << "Invalid genre! Invalid Genre entry.  Please re-enter" << endl;
                } while (genre != 'F' && genre != 'M' && genre  != 'S' && genre != 'C');
                
                do{
                cout << "Enter price: ";
                cin >> bookPrice;
                
                if(bookPrice <= 0)
                    cout << "Must enter a positive price.  Please re-enter" << endl;
                } while (bookPrice <= 0);
                
                cout << endl;
                
                BookStore.insertBook(title, author, bookPrice, genre);
                break;
            
            }
            case 'F': {
                char id[31];
                cout << "\nEnter search string (title or author): ";
                cin.ignore();
                cin.getline(id, 31);
                
                int bookNum = BookStore.findBookIndex(id, 'F');
                if(bookNum < 0)
                    cout << '\n' << id << ": not found\n" << endl;
                else{
                    cout << "\nBook Found:" << endl;
                    BookStore.displayBook(bookNum);
                    cout << endl;
                }
                
                break;
            
            }
            case 'S': {
                char t[31];
                cout << "Enter title to sell: ";
                cin.ignore();
                cin.getline(t, 31);
                
                if(BookStore.removeBook(t))
                    cout << "\nSale Complete\n" << endl;
                else{
                    cout << '\n' << t << " not found in inventory" << endl;
                    cout << "* No sale made *\n" << endl;
                }
                
                break;
            
            }
            case 'D':{
                BookStore.displayInventory();
                break;
            
            }
            case 'G':{
                char g;
                cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                cin >> g;
                g = toupper(g);
                BookStore.displayInventory(g);
                
                break;
            
            }
            case 'O' :{
                char sortOption;
                do{
                    cout << "Sort by (T)itle or (A)uthor? > ";
                    cin >> sortOption;
                    sortOption = toupper(sortOption);
                    
                    if(sortOption != 'A' && sortOption != 'T')
                        cout << "Invalid delimeter! Please Re-enter" << endl;
                } while (sortOption != 'A' && sortOption != 'T');
                
                BookStore.sort(sortOption);
                cout << "\nSort Complete\n" << endl;
                
                break;
            }
            case 'M': {
                displayMenu();
                break;
            
            }
            case 'X':{
                cout << "\nGoodbye!" << endl;
                break;
            }
        }
    } while (operation != 'X');
}

void displayMenu(){
    cout <<
    "\n\t\t*** Bookstore Menu ***\n"
    "\tA:\tAdd a book to inventory\n" << 
    "\tF:\tFind a book from inventory\n" << 
    "\tS:\tSell a book\n" << 
    "\tD:\tDisplay the inventory list\n" << 
    "\tG:\tGenre summary\n" << 
    "\tO:\tSort inventory list\n" <<
    "\tM:\tShow this Menu\n" << 
    "\tX:\teXit the program\n" << endl;
}