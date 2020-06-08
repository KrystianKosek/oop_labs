#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class User{
    public:
        // Konstruktory
        User() : name(""), isAuthorized(false) {}
        User(const std::string name) : name(name), isAuthorized(false) {
            std::cout << "Creating User " << name << "\n";
        }
        // destruktor
        ~User(){
            std::cout << "Deleting User " << name << "\n";
        }
        // getter do name
        std::string get_name() const{
            if(isAuthorized)
                return name;
            else{
                std::string msg = "Authorisation for User " + name + " was not granted.\n";
                throw msg;
            }
        }
        
        // funkcja authorize, ustawia zmienną isAuthorized na przekazaną wartość
        void authorize(const bool decision){
            isAuthorized = decision;
        }
    
    
    private:
        std::string name;
        bool isAuthorized;
        
};


class UserArray{
    public:
        // konstruktory
        UserArray() : size(0) {}
        UserArray(int n) : size(n) {
            array.resize(size);
        }
        
        // destruktor
        ~UserArray(){
            for(auto v : array){
                delete v;
            }
        }
        
        // funkcja set, dopisuje do naszego vectora nowego usera na określony index
        void set(const int index, User * usr){
            if(index < size){
                array[index] = std::move(usr);
            }
            else{
                delete usr;
                throw std::unique_ptr<UserArray>(this);
            }
        }
        
        // get, zwraca użytkownika o określonym indexie
        User * get(const int index){
            if(index < size)
                return array[index];
            else{
                throw "Index out of bands exception";
            }
        }
    
    
    private:
        int size;
        std::vector<User *> array;
};
