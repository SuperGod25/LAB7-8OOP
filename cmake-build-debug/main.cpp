#include "cmake-build-debug/Tests/Tests.h"
#include "cmake-build-debug/UI/UI.h"
#include "cmake-build-debug/Service/Service.h"
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