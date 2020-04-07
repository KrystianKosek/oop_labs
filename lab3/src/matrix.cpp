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

void matrix::fill(vector *wsk, int size_y)
{
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < macierz[i]->size(); j++)
        {
            (macierz[i])->operator[](j) = wsk[i][j];
        }
    }
}

std::ostream &operator<<(std::ostream &o, const matrix &wsk)
{
    for (int i = 0; i < wsk.size_y; i++)
    {
        o << *wsk.macierz[i] << "\n";
    }
    o << "\n";
    return o;
}

matrix operator+(const matrix &wsk1, const matrix &wsk2)
{
    int size_x = wsk1.size_x > wsk2.size_x ? wsk1.size_x : wsk2.size_x;
    int size_y = wsk1.size_y > wsk2.size_y ? wsk1.size_y : wsk2.size_y;
    matrix tmp(size_x, size_y);
    for (int i = 0; i < size_y; i++)
    {
        if (i < wsk1.size_y && i < wsk2.size_y)
        {
            for (int j = 0; j < size_x; j++)
            {
                if (j < wsk1.size_x && j < wsk2.size_x)
                {
                    (tmp.macierz[i])->operator[](j) = (wsk1.macierz[i])->operator[](j) + (wsk2.macierz[i])->operator[](j);
                }
                else if (j < wsk1.size_x)
                {
                    (tmp.macierz[i])->operator[](j) = (wsk1.macierz[i])->operator[](j);
                }
                else
                {
                    (tmp.macierz[i])->operator[](j) = (wsk2.macierz[i])->operator[](j);
                }
            }
        }
        else if (i < wsk1.size_y)
        {
            for (int j = 0; j < wsk1.size_x; j++)
            {
                (tmp.macierz[i])->operator[](j) = (wsk1.macierz[i])->operator[](j);
            }
        }
        else
        {
            for (int j = 0; j < wsk2.size_x; j++)
            {
                (tmp.macierz[i])->operator[](j) = (wsk2.macierz[i])->operator[](j);
            }
        }
    }
    return tmp;
}

matrix operator*(const matrix &wsk1, const matrix &wsk2)
{
    matrix tmp1;
    matrix tmp2;
    if (wsk1.size_y == wsk2.size_x)
    {
        tmp1 = wsk1;
        tmp2 = wsk2;
    }
    else
    {
        tmp1 = wsk2;
        tmp2 = wsk1;
    }

    matrix tmp(tmp1.size_x, tmp2.size_y);
    for (int i = 0; i < tmp2.size_y; i++)
    {
        for (int j = 0; j < tmp1.size_x; j++)
        {
            int x = 0;
            for (int k = 0; k < tmp1.size_y; k++)
            {
                x += (tmp1[k]).operator[](j) * (tmp2[i]).operator[](k);
            }
            (tmp.macierz[i])->operator[](j) = x;
        }
    }
    return tmp;
}
} // namespace MyStuff