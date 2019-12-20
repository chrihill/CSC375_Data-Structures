#include <iostream>

using namespace std;

int sum(int x,int y){return(x+y);}
int(*fn1)(int,int);

int main()
{
    fn1 = sum;
    cout << sum(10,20) << endl;
    cout << fn1(10,10) << endl;
    return 0;
}
