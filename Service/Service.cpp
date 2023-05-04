//
// Created by Sebi on 02.05.2023.
//

#include "Service.h"
#include <iostream>
using namespace std;

Service::Service(Repository &repo) : repo(repo) {
    this->repo.setSize(0);
    this->repo.setMaxSize(4);
}

Service::Service(Repository givenRepo,Repository &repo) : repo(repo) {
    this->repo.setSize(givenRepo.getSize());
    this->repo.setMaxSize(givenRepo.getMaxSize());
}

Service::Service(const Repository &repo, Repository &repo_0) : repo(repo_0){

}

Service::~Service() {

}

void Service::resize(Repository &repo) {
    int newSize = repo.getMaxSize()*2;
    Cheltuiala* newArr = new Cheltuiala[newSize];
    Cheltuiala* chelt = repo.getRepo();
    for(int i = 0; i<repo.getMaxSize();i++)
        newArr[i] = chelt[i];

    repo.setMaxSize(newSize);
    if(chelt != nullptr)
    {
        delete[] chelt;
        chelt = nullptr;
    }

    repo.setRepo(newArr);
}

void Service::createElem(int ziua, int suma, char *tip) {
    if (repo.getSize() != repo.getMaxSize())
        resize(this->repo);
    Cheltuiala chelt(ziua, suma, tip);
    repo.add(chelt);
}

Cheltuiala Service::getElemById(int id) {
    return this->repo.getCheltPos(id);
}

Cheltuiala* Service::getAllElems() {
    return this->repo.getRepo();
}

void Service::updateElem(int id, int ziua, int suma, char *tip) {
    Cheltuiala updatedChelt = Cheltuiala(ziua, suma, tip);
    Cheltuiala* cheltuieli = getAllElems();
    cheltuieli[id] = updatedChelt;
    this->repo.setRepo(cheltuieli);
}

int Service::nrElems(){
    return this->repo.getSize();
};

void Service::deleteElem(int id) {
    Cheltuiala* cheltuieli = this->repo.getRepo();
    int size = this->nrElems()-1;
    for(int i = id; i<size;i++)
        cheltuieli[i] = cheltuieli[i+1];
    this->repo.setRepo(cheltuieli);
    this->repo.setSize(size);
}

int Service::sumByType(char *tip) {
    Cheltuiala* cheltuieli = getAllElems();
    int sum = 0;
    for(int i = 0;i<nrElems();i++)
        if(strcmp(cheltuieli[i].getTip(), tip)==0)
            sum+=cheltuieli[i].getSuma();
    return sum;
}

int Service::cheltuialaByType(char *tip, Cheltuiala *&neededChelt) {
    Cheltuiala* cheltuieli = getAllElems();
    int k=0;
    for(int i = 0; i<nrElems(); i++)
        if(strcmp(cheltuieli[i].getTip(), tip)==0)
            neededChelt[k++] = cheltuieli[i];
    return k;
}

void Service::filterByType(char *tip) {
    Cheltuiala* filteredChelt = new Cheltuiala[nrElems()];
    Cheltuiala* cheltuieli = getAllElems();
    int k = 0;
    for(int i = 0; i<nrElems(); i++)
        if(strcmp(cheltuieli[i].getTip(), tip)==0)
            filteredChelt[k++] = cheltuieli[i];
    this->repo.setRepo(filteredChelt);
    this->repo.setSize(k);
}