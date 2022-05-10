#pragma once
#include <iostream>

class Library{
private:
    Book* array;
    unsigned int size;
    unsigned int capacity;

    //RemoveBook() helper functions
    void deleteTextFile(Book& book);
    int findbook(const char* author, const char* title);

    //findBookByCriteria helper function
    int findByCriteria(const char* lhs, const char* rhs);
public:
    Library();
    ~Library();    

    void sortListOfBooks(bool descending, unsigned short criteria);
    void findBookByCriteria(unsigned short criteria);
    void AddBook(const char* author, const char* title, const char *fileName, 
                const char* description, short unsigned rating, const char* ISBN, bool admin);
    void RemoveBook(const char* author, const char* title, bool admin);
    void PrintBook();
};