#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    {
        Array<int> a1(5); a1[0] = 10;
        Array<int> a2(5);
        a2 = a1; // operator = (a2, a1); a2.operator = (a1);
        cout << a2[0] << endl;
        a2[0] = 20;
        cout << a1[0] << endl;
        cout << a2[0] << endl;
    }

    Array<int> dynArr(5);
    for (int i = 0; i < dynArr.length(); i++) {
        dynArr[i] = i * 2;
    }
    for (int i = 0; i < dynArr.length(); i++) {
        cout << dynArr[i] << ", ";
    }
    cout << endl;
    dynArr[6];
    dynArr.changeSize(0);
    cout << dynArr.errMsg() << endl;

    dynArr.changeSize(10);
    for (int i = 5; i < dynArr.length(); i++) {
        dynArr[i] = i * 4;
    }
    for (int i = 0; i < dynArr.length(); i++) {
        cout << dynArr[i] << ", ";
    }
    cout << endl;

    dynArr.changeSize(8);
    for (int i = 0; i < dynArr.length(); i++) {
        cout << dynArr[i] << ", ";
    }
    cout << endl;


    return 0;
}
