#include "vector.h"

namespace MyStuff
{

vector &vector::operator=(const vector &wsk)
{
    sizeOfArray = wsk.sizeOfArray;
    delete[] array;
    array = new int[sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++)
    {
        array[i] = wsk.array[i];
    }
    return *this;
}

vector &vector::operator=(vector &&wsk)
{
    sizeOfArray = std::move(wsk.sizeOfArray);
    delete[] array;
    array = std::move(wsk.array);
    wsk.array = nullptr;
    return *this;
}

void vector::push_back(int m)
{
    int *n_array = new int[sizeOfArray + 1];
    for (int i = 0; i < sizeOfArray; i++)
    {
        n_array[i] = array[i];
    }
    n_array[sizeOfArray] = m;
    sizeOfArray += 1;
    delete[] array;
    array = n_array;
}

void vector::pop_back()
{
    int *n_array = new int[sizeOfArray - 1];
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        n_array[i] = array[i];
    }
    sizeOfArray -= 1;
    delete[] array;
    array = n_array;
}

std::ostream &operator<<(std::ostream &o, const vector &wsk)
{
    for (int i = 0; i < wsk.sizeOfArray; i++)
    {
        o << wsk.array[i] << " ";
    }
    return o;
}

vector operator+(vector &wsk1, vector &wsk2)
{
    vector tmp(wsk1);
    int i = 0;
    for (i = 0; i < tmp.size(); i++)
    {
        tmp[i] += wsk2[i];
    }
    if (wsk2.size() > wsk1.size())
    {
        for (; i < wsk2.size(); i++)
        {
            tmp.push_back(wsk2[i]);
        }
    }

    return tmp;
}
} // namespace MyStuff
