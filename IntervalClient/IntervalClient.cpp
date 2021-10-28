// IntervalClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Interval.h"

using namespace in;
int main()
{
    //Interval* i=new Interval(0,0);
    Interval j(1, 4);
    Interval k(0, 2);
    Interval* i=new Interval();
    //j(0, 1);
    *i = j;
    *i = k.unionInterval(j);
    //*i = j.intersectInterval(k);
    i->afficher();
    if (k.appartenir(1))    std::cout << "yes\n";
    delete i;

    std::cout << "Hello World!\n";
}

