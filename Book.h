#pragma once
#include <iostream>



class Book{
private:
    bool deleted = 0;
    char* author = nullptr;
    char* title = nullptr;
    char* fileName = nullptr;
    char* description = nullptr;
    short unsigned rating = 0;
    char* ISBN = nullptr;
public:
    Book(char* author, char* title, char *fileName, char* description, short unsigned rating, char* ISBN);
    ~Book();
};