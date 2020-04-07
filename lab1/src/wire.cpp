#include "wire.h"

QuantumWire::QuantumWire(){
    length = 0.0;
    quantity = 0;
    arrayOfParts = nullptr;
}
        
QuantumWire::QuantumWire(double length, int quantity){
    this->length = length;
    this->quantity = quantity;
    arrayOfParts = new bool[quantity];
    for(int i = 0; i < quantity; i++){
        arrayOfParts[i] = rand() % 2;
    }
}
        
QuantumWire::QuantumWire(const QuantumWire& toCopy){
    this->operator=(toCopy);
}

QuantumWire::QuantumWire(QuantumWire&& toMove){
   this->operator=(toMove);
}
        
QuantumWire & QuantumWire::operator = (const QuantumWire & wire){

    length = wire.length;
    quantity = wire.quantity;
    arrayOfParts = new bool[quantity];
    for (int i = 0; i < quantity; i++)
    {
        arrayOfParts[i] = wire.arrayOfParts[i];
    }

    return *this;
}
        
QuantumWire & QuantumWire::operator = (QuantumWire && wire){
    length = std::move(wire.length);
    quantity = std::move(wire.quantity);
    delete [] arrayOfParts;
    arrayOfParts = new bool[quantity];
    for(int i = 0; i < quantity; i++){
        arrayOfParts[i] = std::move(wire.arrayOfParts[i]);
    }
    delete [] wire.arrayOfParts;
    wire.arrayOfParts = nullptr;

    return *this;
}

QuantumWire& QuantumWire::operator *= (double x){
    length *= x;
    return *this;
}
        
QuantumWire operator * (double x, QuantumWire wire){
   QuantumWire tmp(wire);
   tmp.length *= x;
   return tmp;
}

QuantumWire QuantumWire::operator *(double x){
   QuantumWire tmp(*this);
   tmp.length *= x;
   return tmp;
}

QuantumWire QuantumWire::operator ! (){
   QuantumWire A(*this);
   for (int i = 0; i < quantity; i++)
   {
       if(this->arrayOfParts[i] == 0){
           A.arrayOfParts[i] = 1;
       }
       else{
           A.arrayOfParts[i] = 0;
       }
   }

   return A;
}

int QuantumWire::operator [] (int i){
    return arrayOfParts[i];
}
        
QuantumWire::operator int (){
    return quantity;
}
        
bool QuantumWire::operator () (const QuantumWire wire1, const QuantumWire wire2){
    if(wire1.length > wire2.length)
        return true;
    return false;
}

std::ostream &operator << (std::ostream &o, const QuantumWire &ptr){
    o << "length: " << ptr.length << ", quanta:";
    for(int i = 0; i < ptr.quantity; i++){
        o << ptr.arrayOfParts[i] << " ";
    }
    return o;
}

QuantumWire::~QuantumWire(){
    delete [] arrayOfParts;
    arrayOfParts = nullptr;
}