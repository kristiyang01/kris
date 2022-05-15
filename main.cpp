#include <iostream>
#include <string.h>

#include "Book.h"
#include "Library.h"


using std::endl;
using std::cout;
using std::cin;

const unsigned short bufferlength = 100;
const unsigned short Author_MAXLENGTH = 30;
const unsigned short Title_MAXLENGTH = 30;
const unsigned short fileName_MAXLENGTH = 20;
const unsigned short ISBN_MAXLENGTH = 30;
const unsigned short Description_MAXLENGTH = 100;

int main(){

    Library lib;
    
    lib.AddBook("Andy Weir", "The Martian", "martian.pdf", 
                "nice book", 5, "05433", 1);
    
    const char* adminpassword = "adminskaparola535";
    bool admin = 0;
    
    char password[30];
    
    cout<<"Enter password to login as an admin:"<<endl;
    cin.getline(password, 30);

    if(strcmp(password, adminpassword) == 0){
        admin = 1;
    }

    unsigned short operation;
    unsigned short operationsCount;
    cout<<"Enter how many times you would want to be given access to the menu"<<endl;
    cin>>operationsCount;
    for(unsigned short i=0; i<operationsCount; i++){
        cout<<"Choose an operation"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Sort list of books"<<endl;
        cout<<"2.Find book by criteria"<<endl;
        cout<<"3.Add Book"<<endl;
        cout<<"4.Remove Book"<<endl;
        cout<<"5.Print Book"<<endl;       
        cin>>operation;
        
        if(operation == 0){
            break;
        }

        switch(operation){
            case 1:
            {
                bool descending;
                cout<<"if you want the list to be sorted descending, enter 1, else enter 0."<<endl;
                cin>>descending;

                unsigned short criteria;
                cout<<"enter the criteria: "<<endl;
                cout<<"0: Author, 1: Title, 2: Rating"<<endl;
                cin>>criteria;
                
                lib.sortListOfBooks(descending, criteria);   

                break;
            }
            case 2:
            {
                unsigned short criteria;
                cout<<"enter the criteria by which you want to find a book,"<<endl;
                cout<<"0:title 1:author 2:ISBN 3:description"<<endl;
                cin>>criteria;

                cout<<"enter the string";
                char buffer[bufferlength]; 
                cin.clear();
                cin.ignore();
                cin.getline(buffer, bufferlength);

                lib.findBookByCriteria(criteria, buffer);  

                break;
            }
            case 3:
            {
                cout<<"enter Author"<<endl;
                char author[Author_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(author, Author_MAXLENGTH);

                cout<<"enter Title"<<endl;
                char title[Title_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(title, Title_MAXLENGTH);

                cout<<"enter fileName"<<endl;
                char fileName[fileName_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(fileName, fileName_MAXLENGTH);

                cout<<"enter Description"<<endl;
                char description[Description_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(description, Description_MAXLENGTH);

                cout<<"enter ISBN"<<endl;
                char ISBN[ISBN_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(ISBN, ISBN_MAXLENGTH);

                cout<<"enter rating between 0 and 10"<<endl;
                unsigned short rating;
                cin>>rating;

                lib.AddBook(author, title, fileName, description, rating, ISBN, admin);

                break;
            }

            case 4:
            {
                cout<<"enter Author"<<endl;
                char author[Author_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(author, Author_MAXLENGTH);
                

                cout<<"enter Title"<<endl;
                char title[Title_MAXLENGTH];
                cin.clear();
                cin.ignore();
                cin.getline(title, Title_MAXLENGTH);

                lib.RemoveBook(author, title, admin);

                break;
            }

            default:
                cout<<"wrong number"<<endl;
                break;
        }
        
    }
    
    lib.saveInFile("BooksLibrary.txt");
        
    return 0;
}