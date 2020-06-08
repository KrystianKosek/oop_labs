#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

// Template struktury IntegralXn, wartość value jest ustawiana na sztywno podczas kompilacji.
template<int n, const double * a, const double * b> struct IntegralXn {
    static constexpr double value = n <= 0 ? 0.0 : (pow(*b, n + 1) / (n + 1) - pow(*a, n + 1) / (n + 1));
};

// operator << pozwalajacy wypisać wartość value z dowolnego obiektu struktury IntegralXn
template<int n, const double * a, const double * b> std::ostream &operator<<(std::ostream &o, const IntegralXn<n, a, b> &ptr){
    return o << ptr.value;
}

// Typ generyczny pt. GroupZn, symulujacy grupe cykliczną. Jako parametr przyjmuje wektor obiektów o zadanym typie
template<typename T> class GroupZn{
    public:
        // mapujemy przekazany vector na mape zawierającą dany typ T oraz wartość integera
        GroupZn(std::vector<T> vec) {
            int i = 1;
            for(auto &v : vec){
                mapa.insert({v, i});
                i *= 2;
            }
            mod = i;
        }
        
        // operator () przyjmujący dwa elementy typu T, zwracający obiekt, którego wartość jest równa iloczynowi obu tych obiektów
        T operator () (T t1, T t2){
            int index = mapa.at(t1) * mapa.at(t2);
            index = index % (mod - 1);
            for(auto &v : mapa){
                if(index == v.second){
                    return v.first;
                }
            }
            return t1;
        }
        
    private:
        std::map<T, int> mapa;
        int mod;
};