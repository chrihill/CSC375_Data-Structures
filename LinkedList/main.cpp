#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;



int main(){
	LinkedList<string>list1;	//head=nullptr

	list1.addEl("hima");
	list1.addEl("jon");
	list1.addEl("austin");
	list1.addEl("jack");

    cout << list1.findEl("jon") << endl;
    cout << list1.findEl("hima") << endl;
    cout << list1.findEl("bob") << endl;
    cout << endl;
	cout << list1.removeEl("hima") << endl;
	cout << list1.removeEl("jon") << endl;
	cout << list1.removeEl("bob") << endl;

	return 0;
}
