#include <cassert>
#include "Tests.h"
using namespace std;

Cheltuiala c1(1, 140, (char*)"factura INTRETINERE");
Cheltuiala c2(4, 40, (char*)"factura DIGI");
Cheltuiala c3(6, 220, (char*)"factura GAZ");
Cheltuiala c4(11, 95, (char*)"factura CURENT");
Cheltuiala c5(28, 50, (char*)"factura NETFLIX");

void testRepository()
{
    Repository repo;
    repo.add(c1);
    assert(repo.getSize()==1);
    assert(repo.getCheltPos(0).getSuma()==20);
}

void testCheltuiala(){
    assert(c1.getSuma()==140);
    c1.setSuma(160);
    assert(c1.getSuma()==160);
}

void testGetZiua()
{
    assert(c3.getZiua()==4);
}

void testGetSuma()
{
    assert(c2.getSuma()==40);
}

void testGetTip()
{
    assert(c5.getTip()==(char*)"factura NETFLIX");
}

void testGetSize()
{
    Repository repo;
    repo.add(c1);
    repo.add(c2);
    repo.add(c5);
    assert(repo.getSize()==3);

}

void testServiceUpdate(){
    Repository repo;
    Service service(repo);
    service.createElem(6, 100, (char*)"Factura ORANGE");
    service.updateElem(0, 28, 50, (char*)"factura NETFLIX");
    assert(service.getElemById(0)==c5);
}

void testServiceDelete(){
    Repository repo;
    Service service(repo);
    service.createElem(9, 230, (char*)"factura spital");
    service.createElem(11, 95, (char*)"factura CURENT");
    service.deleteElem(0);
    assert(service.getElemById(0)==c4);

}

void testSumByTypeService(){
    Repository repo;
    Service service(repo);
    service.createElem(2, 100, (char*)"factura");
    service.createElem(3, 120, (char*)"factura_DIGI");
    service.createElem(4, 150, (char*)"factura");
    service.createElem(6, 140, (char*)"factura_aia");
    service.createElem(7, 130, (char*)"factura");
    int sum = service.sumByType((char*)"factura");
    assert(sum == 380);
}

void testResize()
{
    Repository repo;
    Service service(repo);
    service.createElem(2, 100, (char*)"factura");
    service.createElem(3, 120, (char*)"factura DIGI");
    service.createElem(4, 150, (char*)"factura NETFLIX");
    service.createElem(6, 140, (char*)"factura SPOTIFY");
    service.createElem(1, 130, (char*)"factura INTRETINERE");
    assert(service.getElemById(4) == c1);
}

void testAll(){
    testCheltuiala();
    testRepository();
    testGetSize();
    testGetSuma();
    testGetZiua();
    testResize();
    testServiceDelete();
    testServiceUpdate();
    testSumByTypeService();
    testGetTip();
}