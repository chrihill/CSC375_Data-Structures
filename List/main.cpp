#include <iostream>
#include "List.h"

using namespace std;

struct Student{
    int sID;
    string sName;
};

ostream & operator << (ostream & os, Student s){
    os << s.sID << ":" << s.sName;
    return os;
};

bool operator == (Student s, Student s2){
    if (s.sID == s2.sID) return true;
    return false;
};

void display(List<Student> stList){
    Student s;
    if(!stList.first(s)) {cout << "empty" << endl; return;}
    cout << s << "->";
    while(stList.getNext(s)){
        cout << s << "->";
    }
    cout << endl;
};

int main()
{
    Student s2;
    List<Student>list2;
    s2.sID = 1001; s2.sName = "Austin";
    list2.insert(s2);
    display(list2);
    s2.sID = 1002; s2.sName = "Thomas";
    list2.insert(s2);
    display(list2);
    s2.sID = 1003; s2.sName = "Eric";
    list2.insert(s2);
    display(list2);

    s2.sID = 1003; s2.sName = "";
    list2.retrieve(s2);
    cout << s2 << endl;
    s2.sID = 1002; s2.sName = "";
    list2.retrieve(s2);
    cout << s2 << endl;
    s2.sID = 1001; s2.sName = "";
    list2.retrieve(s2);
    cout << s2 << endl;

    s2.sID = 1001; s2.sName = "";
    list2.find(s2);
    s2.sID = 1001; s2.sName = "Kyle";
    list2.replace(s2);
    display(list2);

    s2.sID = 1025; s2.sName = "";
    cout << list2.retrieve(s2) << endl;
    cout << s2 << endl;

    List<Student>list3;
    list3.insert(s2);
    display(list3);
    list2=list3;
    display(list3);

    s2.sID=1025; s2.sName="";
    cout << list3.retrieve(s2) << endl;
    cout << s2 << endl;



    return 0;
}
