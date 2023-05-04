#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Domain/Cheltuiala.h"

class Repository{
    private:
        Cheltuiala* cheltuiala;
        int nrCheltuieli;
        int nrMaxChelt;
    public:
        Repository();
        Repository(Cheltuiala* cheltuiala, int size, int maxSize);
        Repository(const Repository& repo);
        ~Repository();

        void add(Cheltuiala& cheltuiala);
        Cheltuiala getCheltPos(int pos);
        int getSize() const;
        int getMaxSize() const;
        Cheltuiala* getRepo();
        void setRepo(Cheltuiala* cheltuiala);
        void setSize(int);
        void setMaxSize(int);
        Repository& operator=(const Repository &repo);



};
#endif