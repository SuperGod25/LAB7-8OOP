#ifndef CHELTUIALA_H
#define CHELTUIALA_H

#include <iostream>
using namespace std;

class Cheltuiala{
    private:
        int suma;
        int ziua;
        char* tip;
    public:
        Cheltuiala();
        Cheltuiala(int, int, char*);
        Cheltuiala(const Cheltuiala& cheltuiala);
        ~Cheltuiala();
        int getSuma() const;
        void setSuma(int);
        int getZiua() const;
        void setZiua(int);
        char* getTip() const;
        void setTip(char*);

        Cheltuiala& operator=(const Cheltuiala& cheltuiala);
        bool operator==(const Cheltuiala& cheltuiala);

        friend ostream& operator<<(ostream& os, Cheltuiala& cheltuiala);

        
};
#endif