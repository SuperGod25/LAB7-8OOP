#include <iostream>
#include "Cheltuiala.h"
#include <cstring>
using namespace std;

Cheltuiala::Cheltuiala(){
    this->ziua = 0;
    this->suma = 0;
    this->tip = nullptr;
}


Cheltuiala::~Cheltuiala(){
    if (this->tip != nullptr){
        delete[] this->tip;
        this->tip = nullptr;
    }
}

Cheltuiala::Cheltuiala(int ziua, int suma, char* tip ){
    this->ziua = ziua;
    this->suma = suma;
    this->tip = tip;
}

Cheltuiala::Cheltuiala(const Cheltuiala& cheltuiala) {
    this->ziua = cheltuiala.ziua;
    this->suma = cheltuiala.suma;
    this->tip = new char[strlen(cheltuiala.tip)+1];
    strncpy(this->tip, cheltuiala.tip, strlen(cheltuiala.tip)+1);
    this->tip[strlen(cheltuiala.tip)+1] = '\0';
}

int Cheltuiala::getSuma() const{
    return suma;
}

void Cheltuiala::setSuma(int suma){
    this->suma = suma;
}

char* Cheltuiala::getTip() const{
    return this->tip;
}

void Cheltuiala::setTip(char *tipChelt) {
    this->tip = new char[strlen(tipChelt)+1];
    strncpy(this->tip, tipChelt, strlen(tipChelt)+1);
    this->tip[strlen(tipChelt)+1] = '\0';
}

int Cheltuiala::getZiua() const{
    return this->ziua;
}

void Cheltuiala::setZiua(int ziuaChelt) {
    this->ziua = ziuaChelt;

}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala &cheltuiala) {
    this->setZiua(cheltuiala.ziua);
    this->setSuma(cheltuiala.suma);
    this->tip = nullptr;
    this->setTip(cheltuiala.getTip());
    return *this;
}

bool Cheltuiala::operator==(const Cheltuiala &cheltuiala) {
    if(this->ziua == cheltuiala.ziua)
    {
        if(this->suma == cheltuiala.suma)
        {
            if(strcmp(this->tip, cheltuiala.tip)==0)
                return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, Cheltuiala& cheltuiala){
    os<<"In ziua "<<cheltuiala.getZiua()<<" ai cheltuit "<<
    cheltuiala.getSuma()<<" lei pe "<<cheltuiala.getTip()<<endl;
    return os;
}