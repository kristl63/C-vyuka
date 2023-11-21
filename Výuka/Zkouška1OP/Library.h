#pragma once
#include "Book.h"
#include <fstream>
#include <iostream>
//#include <string>nemusim je v book.h
#include <list>

class Library
{
private:
    std::string path;
    std::list<Book> books;
public:
    Library(std::string path);
    
    //~Library();
};

