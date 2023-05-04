//
// Created by Sebi on 02.05.2023.
//

#ifndef LAB78_UI_H
#define LAB78_UI_H

#include "cmake-build-debug/Service/Service.h"

class UI {
private:
    Service& service;
public:
    UI(Service& service);
    ~UI();

    void addCheltuialaUI();
    void showCheltuialaUI();
    void showAllCheltuieliUI();
    void updateCheltuialaUI();
    void deleteCheltuialaUI();
    void showSumCheltuialaTypeUI();
    void showCheltuialaByType();
    void filterCheltuialaByTypeUI();
    void readProcedure(int& ziua, int& suma, char*& tip);
    void showMenu();
    void console(char&);
    void runMenu();
};

#endif //LAB78_UI_H
