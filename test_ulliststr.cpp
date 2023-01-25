#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr* dat = new ULListStr();
    dat->push_back("0");
    dat->push_back("1");
    dat->push_back("2");
    dat->push_back("3");
    dat->push_back("4");
    dat->push_back("5");
    dat->push_back("6");
    dat->push_back("7");
    dat->push_back("8");
    dat->push_back("9");
    dat->push_back(" 10");
    dat->push_back("11");
    dat->push_back("12");
    //dat->push_front("8");
    //dat->push_back("1");
    cout << "Value: " << dat->get(0) <<dat->get(1)<< dat->get(2) <<dat->get(3)<< dat->get(4) <<dat->get(5)<< dat->get(6) <<dat->get(7)<< dat->get(8) <<dat->get(9)<< dat->get(10) <<dat->get(11)<<dat->get(12)<<endl;
    //cout << "Value: " << dat->get(0) << " " << dat->get(1) << endl;
    //cout << "Value2: " << dat->get(1) << dat->get(1) << dat->get(1) << dat->get(1) << endl;
    //<< " " << dat->get(2) << endl;
    // prints: 8 7 9
    cout << "Size: " << dat->size() << endl;  // prints 3 since there are 3 strings stored

    delete dat;
}
