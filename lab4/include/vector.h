#pragma once

#include <iostream>
#include <utility>

namespace MyStuff
{
class vector
{
public:
    // konstruktor bez parametrowy, ustawiający rozmiar na 0 i ustawiający wskaźnik na nullptr
    vector() : sizeOfArray(0), array(nullptr) {}

    // konstruktor przyjmujący jeden parametr integer określający rozmiar tablicy, alokuje i zeruje tablice
    vector(int sizeOfArray) : sizeOfArray(sizeOfArray), array(new int[sizeOfArray]{0})
    {
        /*   for(int i = 0; i < sizeOfArray; i++)
                    array[i] = 0;
                    */
    }

    // konstruktor kopiujący, kopiuje rozmiar i przepisuje element po elementcie
    vector(const vector &wsk) : sizeOfArray(wsk.sizeOfArray), array(new int[sizeOfArray])
    {
        for (int i = 0; i < sizeOfArray; i++)
            array[i] = wsk.array[i];
    }

    // konstruktor przenoszący
    vector(vector &&wsk)
    {
        sizeOfArray = std::move(wsk.sizeOfArray);
        array = new int[sizeOfArray];
        array = std::move(wsk.array);
        wsk.array = nullptr;
    }

    // destruktor, kasuje zaalokowaną pamięć i ustawia wskaźnik na nullptr
    ~vector()
    {
        delete[] array;
        array = nullptr;
    }

    /* przeciążony operator przypisywania, przyjmujący stały wskaźnik do obiektu który kopiujemy.
               usuwa starą tablice, ustawia na nowo rozmiar i alokuje nową tablice, następnie
               przepisuje elment po elemencie. 
            */
    vector &operator=(const vector &wsk);

    // przeciążony operator przypisania, usuwa starą tablice i za pomocą std::move przenosi
    // nową, ustawia array w wsk na nullptr
    vector &operator=(vector &&wsk);

    // Przeciążony operator [] przyjmujący jako parametr index, którego adres zwraca
    int &operator[](int index)
    {
        return array[index];
    }

private:
    int sizeOfArray;
    int *array;
};
} // namespace MyStuff
