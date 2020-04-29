#pragma once
#include "shape.h"

class Shape_ptr{

    public:
        // konstruktor, standardowo jeśli nie przekażemy żadnego parametru ustawia wartość ptr na null
        Shape_ptr(Shape *ptr = nullptr) : ptr(ptr) {}
        
        // konstruktor blokujący, zapobiega automatycznemu wygenerowaniu
        Shape_ptr(const Shape_ptr &another) = delete;
        
        // destruktor, usuwa wskaźnik na Shape
        ~Shape_ptr(){
            delete ptr;
        }
        
        // zapobiega sytuacji w której 2 wskaźniki wskazują na ten sam obiekt, ponieważ nie pozwala tworzyć kopii
        Shape_ptr& operator = (const Shape_ptr &another) = delete;
        
        // dwukrotnie przeciążony operator =, odpowiednio przyjmujący referencje na Shape_ptr lub referencje do wskaźnika klasy Shape
        // najpierw sprawdza czy nie przekazujemy tego samego wskaźnika, po czym przestawia wskaźnik i ustawia odpowiednio another.ptr lub another na nullptr
        Shape_ptr& operator = (Shape_ptr &another){
            if(another != *this){
                ptr = another.ptr;
                another.ptr = nullptr;
            }
            return *this;
        }
        Shape_ptr& operator = (Shape *&another){
            if(another != ptr){
                ptr = another;
                another = nullptr;
            }
            return *this;
        }
        
        // przeładowany operator -> (zwraca wskaźnik)
        Shape* operator ->(){
            return ptr;
        }
        
        // przeładowany operator * (dereferencja)
        Shape& operator*(){
            return *ptr;
        }
        
        // przeładowany operator bool, zwraca true jeśli ptr na coś wskazuje
        operator bool(){
            if (ptr != nullptr){
                return true;
            }
            return false;
        }
        
    private:
        Shape *ptr;
};