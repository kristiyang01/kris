#include "Library.h"
#include <cstdio>
#include <cstring>

using std::cout;
using std::endl;

Library::Library(){
    Book = nullptr;
    size = 0;
    capacity = 0;
};
Library::~Library(){
    delete[] Book;
    Book = nullptr;
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

void Library::castToLowerCase(char* string){
    unsigned int len = strlen(string);
    char offset = 'a' - 'A';
    
    for(unsigned int i=0; i<len; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] += offset;
        }
    }

    return;
}

bool Library::mystrcmp(const char* str1, char* str2, unsigned int length){
    unsigned int len1 = strlen(str1);
    char offset = 'a' - 'A';
    if(len1 != length){
        return 0;
    }

    castToLowerCase(str2);
    for(unsigned int i=0; i<len1; i++){
        if(str1[i] != str2[i] && (str1[i] + offset) != str2[i]){
            return 0;
        }
    }

    return 1;
}

bool Library::contains(const char* str1, char* str2, unsigned int length){
    unsigned int len1 = strlen(str1);

    if(len1 < length){
        return 0;
    }

    bool didntbreak;
    char offset = 'a' - 'A';
    castToLowerCase(str2);

    for(unsigned int i=0; i<=len1-length; i++){
        didntbreak = 1;
        for(unsigned int j=0; j<length; j++){
            if(str1[i+j] != str2[j] && (str1[i+j] + offset) != str2[j]){
                didntbreak = 0;            
                break;
            }
        }
        if(didntbreak){
            return 1;
        }
    }

    return 0;
}

void Library::sortByTitle(unsigned int* array){
    for(unsigned int i=0; i<size-1; i++){
        for(unsigned int j=i+1; j<size; j++){
            if(strcmp(Book[array[i]].title, Book[array[j]].title) > 0){
                std::swap(array[i], array[j]);
            }
        }
    }

    return;
}

void Library::sortByAuthor(unsigned int* array){
    for(unsigned int i=0; i<size-1; i++){
        for(unsigned int j=i+1; j<size; j++){
            if(strcmp(Book[array[i]].author, Book[array[j]].author) > 0){
                std::swap(array[i], array[j]);
            }
        }
    }

    return;
}

void Library::sortByRating(unsigned int* array){
    for(unsigned int i=0; i<size-1; i++){
        for(unsigned int j=i+1; j<size; j++){
            if(Book[array[i]].rating > Book[array[j]].rating){
                std::swap(array[i], array[j]);
            }
        }
    }

    return;
}

///////////////////////////////////////////////////////////////////////////

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
            Book[sortIndex[i]].print();  //implement
        }
    }else{
        for(unsigned short i=0; i<size; i++){
            Book[sortIndex[i]].print();
        }
    }
};

void Library::findBookByCriteria(unsigned short criteria, char* string){
    unsigned int index;
    unsigned int stringlength = strlen(string);

    switch(criteria){
        case 0:
            for(unsigned int i=0; i<size; i++){
                if(mystrcmp(Book[i].title, string, stringlength)){
                    index = i;
                }
            }

        case 1:
            for(unsigned int i=0; i<size; i++){
                if(mystrcmp(Book[i].author, string, stringlength)){
                    index = i;
                }
            }

        case 2:
            for(unsigned int i=0; i<size; i++){
                if(mystrcmp(Book[i].ISBN, string, stringlength)){
                    index = i;
                }
            }

        case 3:
            for(unsigned int i=0; i<size; i++){
                if(contains(Book[i].description, string, stringlength)){
                    index = i;
                }
            }
                
        default:
            cout<<"criteria should be 0,1,2 or 3";
            return;
    }

    Book[index].fullprint();  //implement
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
        Book* newBook = nullptr;
        newBook = new Book[capacity*2];
        if(newBook == nullptr){
            throw "Memory allocation problem"; //tbd
            return;
        }
        capacity = capacity*2;
        for(unsigned int i=0; i<size; i++){
            newBook[i] = Book[i]; //need operator=
        }
        delete[] Book;
        Book = newBook;
        newBook = nullptr;
    }
    Book[size] = Book(author, title, fileName, description, rating, ISBN); //need constructor
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
// void Library::PrintBook(){

// }