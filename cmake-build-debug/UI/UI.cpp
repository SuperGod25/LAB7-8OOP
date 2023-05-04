//
// Created by Sebi on 02.05.2023.
//

#include "cmake-build-debug/Service/Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(Service& service) : service(service)
{

}

UI::~UI()
{
}

void UI::readProcedure(int& ziua, int& suma, char*& tip){
    cout << "Introduceti ziua: ";
    cin >> ziua;
    cout << endl;
    cout << "Introduceti suma: ";
    cin >> suma;
    cout << endl;
    cout << "Introduceti tipul: ";
    cin >> tip;
    cout << endl;
}

void UI::addCheltuialaUI() {
    int ziua, suma;
    char* tip = new char[25];
    readProcedure(ziua, suma, tip);
    this->service.createElem(ziua, suma, tip);
    delete[] tip;
}

void UI::showCheltuialaUI(){
    cout << "Ce cheltuiala vrei sa verifici? " << endl;
    int cheltId;
    cin >> cheltId;
    Cheltuiala neededChelt = this->service.getElemById(cheltId);
    cout << neededChelt << endl;
}

void UI::showAllCheltuieliUI(){
    cout << "Toate cheltuielile sunt: " << endl;
    int nrChelt = service.nrElems();
    Cheltuiala* cheltuieli = service.getAllElems();
    for (int i = 0; i < nrChelt; i++)
        cout << i <<". " << cheltuieli[i] << endl;
}

void UI::updateCheltuialaUI() {
    int ziua, suma, id;
    char* tip = new char[25];
    cout << "Ce cheltuiala vrei sa modifici? ";
    showAllCheltuieliUI();
    cin >> id;
    readProcedure(ziua, suma, tip);
    this->service.updateElem(id, ziua, suma, tip);
    delete[] tip;
}

void UI::deleteCheltuialaUI() {
    int id;
    cout << "Ce cheltuiala vrei sa stergi? ";
    showAllCheltuieliUI();
    cin >> id;
    this->service.deleteElem(id);

}

void UI::showSumCheltuialaTypeUI(){
    char* tip = new char[25];
    cout << "Introduceti tipul de cheltuiala pentru care doriti sa vedeti suma totala: ";
    cin>>tip;
    int sum = this->service.sumByType(tip);
    cout << endl << "Suma totala: " << sum << endl;
    delete[] tip;
}

void UI::filterCheltuialaByTypeUI(){
    char* tip = new char[25];
    cout << "Introduceti tipul de cheltuiala dupa care vreti sa filtrati: ";
    cin>>tip;
    this->service.filterByType(tip);
    delete[] tip;
}

void UI::showCheltuialaByType() {
    char* tip = new char[25];
    cout << "Introduceti tipul de cheltuiala pe care doriti sa il vedeti: ";
    cin>>tip;
    Cheltuiala* neededChelt = new Cheltuiala[this->service.nrElems()];
    int nrChelt = this->service.cheltuialaByType(tip, neededChelt);
    for(int i = 0; i < nrChelt; i++)
        cout << i <<". " << neededChelt[i] << endl;
    delete[] neededChelt;
    delete[] tip;
}



void UI::showMenu(){
    cout << endl;
    cout << "1.Adauga cheltuiala :(" <<endl;
    cout << "2.Arata o cheltuiala dupa ID" << endl;
    cout << "3.Arata toate cheltuielile" << endl;
    cout << "4.Actualizeaza o cheltuiala" << endl;
    cout << "5.Sterge o cheltuiala" << endl;
    cout << "6.Suma unei cheltuieli dupa tip" << endl;
    cout << "7.Arata cheltuielile dupa tip" << endl;
    cout << "8.Filtreaza cheltuielile dupa tip" << endl;
    cout << "m. Arata meniul" << endl;
    cout << "x. Iesire" << endl;
}


void UI::console(char& option){
    this->showMenu();
    cout << "Alege una din optiunile de mai sus: ";
    cin >> option;
    cout << endl;
}

void UI::runMenu() {
    bool run = true;
    while (run) {
        char option;
        console(option);
        switch (option) {

            case '1': {
                addCheltuialaUI();
                break;
            }

            case '2': {
                showCheltuialaUI();
                break;
            }
            case '3': {
                showAllCheltuieliUI();
                break;
            }
            case '4': {
                updateCheltuialaUI();
                break;
            }
            case '5': {
                deleteCheltuialaUI();
                break;
            }
            case '6': {
                showSumCheltuialaTypeUI();
                break;
            }
            case '7': {
                showCheltuialaByType();
                break;
            }
            case '8': {
                filterCheltuialaByTypeUI();
                break;
            }

            case 'x': {
                run = false;
                break;
            }

            case 'm': {
                showMenu();
                break;
            }

            default:
                cout << "Optiune invalida! Alege o optiune din cele existente. ";
                cout << endl;
        }
    }
}

