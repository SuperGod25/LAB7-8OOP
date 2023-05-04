//
// Created by Sebi on 02.05.2023.
//

#ifndef LAB78_SERVICE_H
#define LAB78_SERVICE_H

#include "cmake-build-debug/Repository/Repository.h"

class Service{
private:
    Repository& repo;
public:
    Service(Repository& repo);
    Service(Repository givenRepo, Repository& repo);
    Service(const Repository& repo, Repository& repo_0);
    ~Service();

    void resize(Repository& repo);
    void createElem(int, int, char*);
    int nrElems();
    int sumByType(char* tip);

    Cheltuiala getElemById(int);
    Cheltuiala* getAllElems();

    int cheltuialaByType(char* tip, Cheltuiala*& neededChelt);
    void filterByType(char* tip);
    void updateElem(int, int, int, char*);
    void deleteElem(int);

};

#endif //LAB78_SERVICE_H
