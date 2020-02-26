#pragma once

#include <iostream>

class QuantumWire {
    public:
        /*
            Konstruktory
        */
        QuantumWire();
        QuantumWire(double, int);
        QuantumWire(const QuantumWire&);
        QuantumWire(QuantumWire&&);

        /*
            Destruktor
        */
        ~QuantumWire();

        /*
            Przeładowany operator przypisania kopiujący
        */
        QuantumWire & operator = (const QuantumWire &);

        /*
            Przeładowany operator przypisania przenoszący
        */
        QuantumWire & operator = (QuantumWire &&);

        /*
            Przeładowany operator *= mnożący pole "length" przez stałą
        */
        QuantumWire & operator *= (double);
        /*
            Przeładowania operatorów * z lewej i prawej strony
        */
        friend QuantumWire operator * (double, QuantumWire);
        QuantumWire operator *(double);

        /*
            Przeładowany operator !, robiący negacje w całej tablicy arrayOfParts
        */
        QuantumWire operator ! ();

        /*
            Przeładowany operator [] przyjmujący wartość int, zwracający element tablicy arrayOfParts o indeksie podanym jako parametr
        */
        int operator [] (int);

        /*
            Przeładowany operator rzutowania na int
        */
        operator int ();

        /*
            Przeładowany operator () realizujący predykat
        */
        bool operator () (QuantumWire, QuantumWire);

        /*
            Przeładowany operator << drukujący obiekt QuantumWire
        */
        friend std::ostream &operator << (std::ostream &o, const QuantumWire &ptr);
    private:
        /*
            Zmienna length oznacza długość drutu
            Zmienna quantity oznacza ilość cząstek
            Wskaźnik arrayOfParts to tablica boolów długości quantity
        */
        double length;
        int quantity;
        bool *arrayOfParts;
};