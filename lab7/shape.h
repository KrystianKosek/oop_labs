#pragma once
#include <iostream>
#include <vector>


class Shape{
    public:
        // deklarujemy jako friend operator <<, który wypisuje nazwe
        friend std::ostream &operator <<(std::ostream &out, const Shape &shape);
        
        // konstruktor przyjmujący pole name i vector z wartościami zmiennoprzecinkowymi
        Shape(std::string name, std::vector<double> vec) : name(name), vec(vec){}
        
        // funkcje czysto wirtualne
        virtual double area() const = 0;
        virtual double circumference() const= 0;
        
        // defaultowy konstruktor virtualny
        virtual ~Shape() = default;
        
    protected:
        std::string name;
        std::vector<double> vec;
};

std::ostream &operator <<(std::ostream &out, const Shape &shape){
    out << shape.name;
    return out;
}

class Circle : public Shape {
    // pozwala nam to dziedziczyć konstruktor z klasy Shape
    using Shape::Shape;
    public:
        // przeładowane funkcje z klasy Shape
        double area() const override {
            return 3.14 * vec[0] * vec[0];
        }
        double circumference() const override {
            return 2 * 3.14 * vec[0];
        }
};

class Rectangle : public Shape {
    // pozwala nam to dziedziczyć konstruktor z klasy Shape
    using Shape::Shape;
    public:
        // przeładowane funkcje z klasy Shape
        double area() const override {
            return vec[0] * vec[1];
        }
        double circumference() const override {
            return 2 * vec[0] + 2 * vec[1];
        }
};