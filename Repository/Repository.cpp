#include "Repository.h"
#include <iostream>
using namespace std;

Repository::Repository(){
    this->nrCheltuieli=0;
    this->nrMaxChelt = 4;
    this->cheltuiala = new Cheltuiala[10];
}

Repository::Repository(Cheltuiala* cheltuiala, int size, int maxSize) {
    this->nrCheltuieli = size;
    this->nrMaxChelt = maxSize;
    this->cheltuiala = new Cheltuiala[size];
    for(int i = 0; i<size; i++)
        this->cheltuiala[i] = cheltuiala[i];
}

Repository::Repository(const Repository &repo) {
    this->nrCheltuieli = repo.getSize();
    this->nrMaxChelt = repo.getMaxSize();
    this->cheltuiala = new Cheltuiala[repo.getSize()];
    for(int i=0; i<repo.getSize();i++)
        this->cheltuiala[i] = cheltuiala[i];
}

Repository::~Repository(){
    if(this->cheltuiala != nullptr)
    {
        delete[] this->cheltuiala;
        this->cheltuiala = nullptr;
    }
}

void Repository::add(Cheltuiala& chelt)
{
    this->cheltuiala[this->nrCheltuieli++]=chelt;
    
}

Cheltuiala Repository::getCheltPos(int pos){
    return this->cheltuiala[pos];
}

int Repository::getSize() const {
    return nrCheltuieli;
}

int Repository::getMaxSize() const {
    return this->nrMaxChelt;
}

void Repository::setSize(int size) {
    this->nrCheltuieli = size;
}

void Repository::setMaxSize(int size) {
    this->nrMaxChelt = size;
}

Cheltuiala* Repository::getRepo() {
    return this->cheltuiala;
}

void Repository::setRepo(Cheltuiala *cheltuiala) {
    this->cheltuiala = cheltuiala;
}

Repository& Repository::operator=(const Repository &repo) {
    this->cheltuiala=repo.cheltuiala;
    this->nrCheltuieli = repo.getSize();
    this->nrMaxChelt = repo.getMaxSize();
    return *this;
}