#pragma once

#include "vector.h"

namespace MyStuff
{
class matrix
{
public:
    // Zaprzyjaźniona funkcja przeciążenia operator << std-out
    friend std::ostream &operator<<(std::ostream &o, const matrix &wsk);

    // Zaprzyjaźniona funkcja dodająca dwie macierze
    friend matrix operator+(const matrix &wsk1, const matrix &wsk2);

    // Zaprzyjaźniona funkcja mnożąca dwie macierze
    friend matrix operator*(const matrix &wsk1, const matrix &wsk2);

    //  Konstruktor defaultowy
    matrix() : size_x(0), size_y(0), macierz(nullptr) {}

    // Konstruktor alokujący macierz o rozmiarze X na Y
    matrix(int x, int y);

    // Konstruktor kopiujący
    matrix(const matrix &wsk);

    // Konstruktor przenoszący
    matrix(matrix &&wsk);

    // Przeciązony operator przypisania kopiujący wartości z przekazanego wskaźnika
    matrix &operator=(const matrix &wsk);

    // Przeciążony operator przypisania przenoszący wartości z przekazanego wskaźnika
    // za pomocą std::move
    matrix operator=(matrix &&wsk);

    // Destruktor
    ~matrix();

    // Przeciązony operator [] zwracający adres przekazanego elementu macierzy
    vector &operator[](int i)
    {
        return *macierz[i];
    }

    // Funkcja fill wypełnia macierz, przekazanym vectorem o podanym rozmiarze
    void fill(vector *wsk, int size_y);

private:
    int size_x;
    int size_y;
    vector **macierz;
};
} // namespace MyStuff
