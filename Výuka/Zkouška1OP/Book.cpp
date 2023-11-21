    #include "Book.h"
    #include <sstream>
    #include <iostream>
    #include <vector>
    
    Book::Book(){
        this->id = 0;
        this->name = "";
        this->author = "";
        this->available = false;
    }

    Book::Book(std::string book){
        std::stringstream ss(book);
        std::vector<std::string>items;
        std::string item;
        while(std::getline(ss, item, ';')){
            items.push_back(item);
        }
        this->id = std::stol(items[0]);
        this->name = items[1];
        this->author = items[2];
        if (items[3] == "Available"){
            this->available = true;
        } else {
            this->available = false;
        }
        
    }
    long Book::getID(){
        return this->id;
    }
    void Book::setID(long id){
        this->id = id;
    };

    bool Book::Book

    bool Book::operator<<(const Book &obj)
    {
        if (author.compare(obj.name) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        }

    std::ostream& operator<<(std::ostream& out, const Book& obj){
        out << obj.id << ";" << obj.name << ";" << obj.author << ";";
        if (obj.available){
            out << "Available";
        } else {
            out << "Unavailable";
        }
        return out;
        }

