#include "Book.h"
#include <string.h>

using std::endl;
using std::cout;

void Book::setString(char*& destination, const char* source){
    destination = new char[strlen(source) + 1];
    if(destination == nullptr){
        throw "Memory allocation error!";
        return;
    }
    strcpy(destination, source);
    return;
}

void Book::setRating(short unsigned rating){
    if(rating >= 0 && rating <=10){
        this->rating = rating;
    }else{
        this->rating = 0;
    }
    return;
}

Book::Book(){
    author = nullptr;
    title = nullptr;
    fileName = nullptr;
    description = nullptr;
    rating = 0;
    ISBN = nullptr;
}

Book::Book(const char* author, const char* title, const char *fileName, const char* description, short unsigned rating, const char* ISBN){
    
    setString(this->author, author);
    setString(this->title, title);
    setString(this->fileName, fileName);
    setString(this->description, description);
    setString(this->ISBN, ISBN);

    setRating(rating);
}

Book& Book::operator=(const Book& other){
    if(this != &other){
        delete[] author;
        delete[] title;
        delete[] fileName;
        delete[] description;
        delete[] ISBN;

        setString(this->author, other.author);
        setString(this->title, other.title);
        setString(this->fileName, other.fileName);
        setString(this->description, other.description);
        setString(this->ISBN, other.ISBN);

        setRating(other.rating);
    }
    return *this;
}
    
Book::~Book(){
        delete[] author;
        delete[] title;
        delete[] fileName;
        delete[] description;
        delete[] ISBN;
}

std::ostream& operator<<(std::ostream& out, const Book& book){
    out<<book.author<<" "<<book.title<<" "<<book.fileName<<" "<<book.description<<" "<<book.rating<<" "<<book.ISBN;
    return out;
}


void Book::print(){
    cout<<title<<" written by "<<author<<" has ISBN:"<<ISBN<<endl;
    return;
}

void Book::fullprint(){
    cout<<title<<" written by "<<author<<" has "<<rating<<" rating ";
    cout<<endl;
    cout<<"The book's ISBN is: "<<ISBN;
    cout<<endl;
    cout<<"Here is a short description of what the book is about: "<<description;

    return;
}

