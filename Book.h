#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book{
private:
    char* author = nullptr;
    char* title = nullptr;
    char* fileName = nullptr;
    char* description = nullptr;
    short unsigned rating = 0;
    char* ISBN = nullptr;

    void setString(char*& destination, const char* source);
    void setRating(short unsigned rating);

public:
    
    Book();
    Book(const char* author, const char* title, const char *fileName, const char* description, short unsigned rating, const char* ISBN);
    Book& operator=(const Book& other);
    ~Book();

    friend std::ostream& operator<<(std::ostream& out, const Book& book);

    void print();
    void fullprint();


    friend class Library;
};

#endif