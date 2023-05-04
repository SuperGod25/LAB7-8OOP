#include "Tests/Tests.h"
#include "UI/UI.h"
#include "Service/Service.h"
#include <iostream>
using namespace std;
int main(){
    testAll();
    Repository repo;
    Service service(repo);
    UI ui = UI(service);
    ui.runMenu();

    return 0;
}