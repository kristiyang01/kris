#include "Library.h"
#include <cstdio>

Library::Library(){
    array = nullptr;
    size = 0;
    capacity = 0;
};
Library::~Library(){
    delete[] array;
    array = nullptr;
};    

void Library::deleteTextFile(Book& book){
    int result = remove(book.fileName);
    if(result == 0){
        cout<<"File deletion completed!";
    }else{
        cerr<<"File deletion failed!";
    }

    return;
}

int Library::findbook(const char* author, const char* title){
    for(unsigned int i=0; i<size; i++){
        if(strcmp(Book[i].title, title) == 0){
            if(strcmp(Book[i].author, author) == 0){
                return i;
            }
        }
    }
    return -1;
}

int Library::findByCriteria(const char* lhs, const char* rhs){
    
}

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

    if(criteria>3){
        cout<<"criteria should be 0,1,2 or 3";
        return;
    }

    if(criteria == 0){
        for(unsigned int i=0; i<size; i++){
            if(strcmp(Book[i].title, title) == 0){
                index = i;
            }
        }
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

    Book[index].fullprint;  //implement
    //invalid criteria tbd
    return;
}
void Library::AddBook(const char* author, const char* title, const char *fileName, 
const char* description, short unsigned rating, const char* ISBN, bool admin){
    
    if(!admin){
        cout<<"Unauthorized access";
        return;
    }

    if(size == capacity){
        Book* newarray = nullptr;
        newarray = new Book[capacity*2];
        if(newarray == nullptr){
            throw "Memory allocation problem" //tbd
            return;
        }
        capacity = capacity*2;
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
void Library::RemoveBook(const char* author, const char* title, bool admin){
    
    if(!admin){
        cout<<"Unauthorized access";
        return;
    } 
    
    int index = findbook(author, title);
    if(index >= 0){ // to implement
        deleteTextFile(Book[index]); // to implement
        if(index < size-1){
            for(unsigned int i=index; i<size-1; i++){
                Book[i] = Book[i+1];
            }
        }
        size--;
    }; 

    return;
}
void Library::PrintBook(){

}