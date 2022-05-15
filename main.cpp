#include <iostream>
#include <string.h>
#include "Book.h"
#include "Library.h"


using std::endl;
using std::cout;
using std::cin;

int main(){
    // Library lib;
    // lib.AddBook("Andy Weir", "The Martian", "martian.pdf", 
    //             "nice book", 5, "05433", 1);
    Book a;

    //

    char adminpassword = "adminskaparola535";
    bool admin = 0;
    char password[30];
    cout<<"Enter password to login as an admin:"
    cin.getline(password, 30);

    if(strcmp(password, adminpassword) == 0){
        admin = 1;
    }

    unsigned short operation;
    unsigned short operationsCount;
    cout<<"Enter how many times you would want to be given access to the menu";
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
                        
        }
        
    }

    return 0;
}