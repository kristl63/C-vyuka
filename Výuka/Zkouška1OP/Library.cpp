#include "Library.h"

Library::Library(std::string path){
    this->path = path;
    std::fstream file;
    file.open(path);
    std::string line;
    while(std::getline(file, line)){
        Book book(line);
        this->books.push_back(book);
    }
    books.sort();
}

void Library::addBook(Book book){
    for(Book b: books){
        if(b.getID() == book.getID()){
            std::cout << "Book with this ID already exists" << std::endl;
            unique=false  ;  
            break;
        }
    }
    if(unique){
        books.push_back(book);
        books.sort();
    }
}

long getUniqueId(){
    long unique_id = 0;
    for(Book b: books){
        if(b.getID() > unique_id){
            unique_id = b.getID();
        }
    }
    return unique_id+1;
}
std::list<Book> Library::showAvailableBooks(){
    std::list<Book> available_books;
    for(Book b: books){
        if(b.available){
            available_books.push_back(b);
        }
    }
    return available_books;
}

void Library::showAvailableBooks(){
    for(Book b: books){
        if(b.available){
            std::cout << b << std::endl;
        }
    }
}

Library::~Library(){
    std::ofstream file;
    file.open(path);
    std::String
    for(Book b: books){
        file << b << std::endl;
    }
    file.close();
}

std::ostream& operator<<(std::ostream& out, const Library& obj){
    for (const Book& book : obj.books){
        out << book << std::endl;
    }
    return out;
}