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

} // namespace MyStuff
