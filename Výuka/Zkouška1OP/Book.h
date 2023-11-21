#include <string>
#include "Library.h"
class Book
{
private:
    long id;
    std::string name;
    std::string author;
    bool available;
public:
    Book();
    long getID();
    void setID(long id);
    Book(std::string book);
    bool operator<< (const Book& obj);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    std::ostream& operator<<(std::ostream& out, const Library& obj);
};
