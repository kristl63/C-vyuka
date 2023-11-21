#include <iostream>

class Shape
{
    public:
        Shape();
};

Shape::Shape()
{
    std::cout << "Vykresli obrazec" << std::endl;
}

class Square:public Shape
{
    private:
        int a;
    public:
    Square()    ;
    Square(int a);
    int getA() const;
    double perimeter();
    double area();
    void print();
};

class Rectangle:public Square
{
    private:
    int b;
    public:
        Rectangle();
        Rectangle(int a, int b);
        int getB() const;
        double perimeter();
        double area();
        void print();
};

class Cube:public Square
{
    private:
        int c;
    public:
        Cube();
        Cube(int a);
        double volume();
};

int Square::getA() const
{
    return a;
}

int Rectangle::getB() const
{
    return b;
}

int main(){
    Cube cb(5);
    std::cout<<cb.volume()<<std::endl;
    cb.print();
    return 0;
}

Square::Square():Shape()
{
    std::cout<<"Vytváříme čtverec"<<std::endl;
};
Square::Square(int a)
{
    this->a = a;
    std::cout<<"Vytváříme čtverec"<<std::endl;

};

Rectangle::Rectangle()
{
    std::cout<<"Vytváříme obdélník"<<std::endl;
};
Rectangle::Rectangle(int a, int b):Square(a)
{
    this->b = b;
    std::cout<<"Vytváříme obdélník"<<std::endl;
};

double Square::perimeter()
{
    return 4 * a;
};

double Square::area()
{
    return a * a;
};

double Rectangle::perimeter()
{
    return 2 * (getA() + b);
};

double Rectangle::area()
{
    return getA() * b;
};

Cube::Cube(){
    std::cout<<"Vytváříme krychli"<<std::endl;
};

Cube::Cube(int a):Square(a){
    std::cout<<"Vytváříme krychli"<<std::endl;
};

double Cube::volume(int a){
    return content()*getA();
};
