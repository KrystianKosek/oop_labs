#include "matrix.h"

namespace MyStuff
{

matrix::matrix(int x, int y) : size_x(x), size_y(y)
{
    macierz = new vector *[size_y];
    for (int i = 0; i < size_y; i++)
    {
        macierz[i] = new vector(size_x);
    }
}
matrix::matrix(const matrix &wsk) : size_x(wsk.size_x), size_y(wsk.size_y)
{
    macierz = new vector *[size_y];
    for (int i = 0; i < size_y; i++)
    {
        macierz[i] = new vector(*wsk.macierz[i]);
    }
}
matrix::matrix(matrix &&wsk)
{
    size_x = std::move(wsk.size_x);
    size_y = std::move(wsk.size_y);
    macierz = std::move(wsk.macierz);
    wsk.size_x = 0;
    wsk.size_y = 0;
    wsk.macierz = nullptr;
}

matrix &matrix::operator=(const matrix &wsk)
{
    for (int i = 0; i < size_y; i++)
    {
        delete macierz[i];
    }
    delete[] macierz;
    size_x = wsk.size_x;
    size_y = wsk.size_y;
    macierz = new vector *[size_y];
    for (int i = 0; i < size_y; i++)
    {
        macierz[i] = new vector(*wsk.macierz[i]);
    }
    return *this;
}
matrix matrix::operator=(matrix &&wsk)
{
    for (int i = 0; i < size_y; i++)
    {
        delete macierz[i];
    }
    delete[] macierz;
    size_x = std::move(wsk.size_x);
    size_y = std::move(wsk.size_y);
    macierz = std::move(wsk.macierz);
    wsk.macierz = nullptr;
    return *this;
}
matrix::~matrix()
{
    if (macierz)
    {
        for (int i = 0; i < size_y; i++)
            delete macierz[i];
        delete[] macierz;
    }
}

} // namespace MyStuff