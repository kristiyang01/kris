#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <iostream>
#include <fstream>


class Library{
private:
    Book* books;
    unsigned int size;
    unsigned int capacity;

    //RemoveBook() helper functions
    void deleteTextFile(Book& book);
    int findbook(const char* author, const char* title);

    //findBookByCriteria helper functions
    void castToLowerCase(char* string);
    bool mystrcmp(const char* str1, char* str2, unsigned int length);
    bool contains(const char* str1, char* str2, unsigned int length);

    //sortListOfBooks helper functions
    void sortByTitle(unsigned int* array);
    void sortByAuthor(unsigned int* array);
    void sortByRating(unsigned int* array);

public:
    Library();
    ~Library();    

    void sortListOfBooks(bool descending, unsigned short criteria);
    void findBookByCriteria(unsigned short criteria, char* string);
    void AddBook(const char* author, const char* title, const char* fileName, 
                const char* description, short unsigned rating, const char* ISBN, bool admin);
    void RemoveBook(const char* author, const char* title, bool admin);
    // void PrintBook();

    void saveInFile(const char* textFile);

    const unsigned int getSize() const;
    


};


#endif