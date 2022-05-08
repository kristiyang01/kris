#include "Library.h"

    Library::Library(){
        array = nullptr;
        size = 0;
        capacity = 0;
    };
    Library::~Library(){
        delete[] array;
        array = nullptr;
    };    

    void Library::sortListOfBooks(bool descending, unsigned short criteria){
        unsigned int* sortIndex = nullptr;
        sortIndex = new unsigned int[size];
        if(sortIndex == nullptr){
            throw "Memory allocation error!";
            return;
        }
        for(unsigned int i=0; i<size; i++){
            sortIndex[i] = i;
        }

        if(criteria == 0){
            sortByTitle(sortIndex);
        }
        if(criteria == 1){
            sortByAuthor(sortIndex);
        }
        if(criteria == 2){
            sortByRating(sortIndex);
        }

        if(descending){
            for(unsigned short i=size-1; i>=0; i--){
                Book[sortIndex[i]].print;  //implement
            }
        }else{
            for(unsigned short i=0; i<size; i++){
                Book[sortIndex[i]].print;
            }
        }
    };

    void Library::findBookByCriteria(unsigned short criteria){
        unsigned int index;
        if(criteria == 0){
            index = findByTitle();
        }
        if(criteria == 1){
            index = findByAuthor();
        }
        if(criteria == 2){
            index = findByISBN();
        }
        if(criteria == 3){
            index = findByDescription();
        }

        Book[index].fullprint;
        //invalid criteria tbd
        return;
    }
    void Library::AddBook(char* author, char* title, char *fileName, char* description, short unsigned rating, char* ISBN, bool admin){
        
        if(!admin){
            cout<<"Unauthorized access";
            return;
        }

        if(size == capacity){
            capacity = capacity*2;
            Book* newarray = nullptr;
            newarray = new Book[capacity];
            if(newarray == nullptr){
                throw "Memory allocation problem" //tbd
                return;
            }
            for(unsigned int i=0; i<size; i++){
                newarray[i] = array[i]; //need operator=
            }
            delete[] array;
            array = newarray;
            newarray = nullptr;
        }
        array[size] = Book(author, title, fileName, description, rating, ISBN); //need constructor
        size++;

        return;
    }
    void Library::RemoveBook(char* author, char* title, bool deleteTxt, bool admin){
        
        if(!admin){
            cout<<"Unauthorized access";
            return;
        } 
        
        int index = findbook(author, title);
        if(index >= 0){ // to implement
            setDeleted(Book[index]); // to implement in book.cpp
            deleteTextFile(Book[index]); // to implement
        }; 
    }
    void Library::PrintBook(){

    }