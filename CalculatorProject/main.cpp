#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

int convertStringToInt(string s) {
	stringstream ss(s);
	int x = 0;
	ss >> x;
	return x;
}

string convertIntToString(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

bool lowerPrec(string s1, string s2) {
    if (((s1 == "+") || (s1 == "-")) && ((s2 == "*") || (s2 == "/"))) return true;
    return false;
}

string convertToPostFix(string s) {
    stringstream ss;
    ss.str(s);
    ss.seekg(0);
    string item;
    string postFixExpr = "";
    Stack<string> stack1;
    while (getline(ss, item, ' ')) {
        if (item == "(") stack1.push(item);
        else if (item == "+" || item == "-") {
            string next;
            while (true) {
                stack1.peek(next);
                if (!(next == "+" || next == "-" || next == "*" || next == "/")) break;
                if (lowerPrec(next, item)) break;
                stack1.pop(next);
                postFixExpr = postFixExpr + " " + next;
            }
            stack1.push (item);
        }
        else if (item == "*" || item == "/") {
            string next;
            while (true) {
                stack1.peek(next);
                if (!(next == "+" || next == "-" || next == "*" || next == "/")) break;
                if (lowerPrec(next, item)) break;
                stack1.pop(next);
                postFixExpr = postFixExpr + " " + next;
            }
            stack1.push (item);
        }
        else if (item == ")") {
            string next;
            while (true) {
                stack1.pop(next);
                if (next == "(") break;
                postFixExpr = postFixExpr + " " + next;
            }
            if (stack1.isEmpty()) break;
        }
        else { // it is a number
            postFixExpr = postFixExpr + " " + item;
        }
    }
    return postFixExpr;
}

int eval(string expr) {
    return 0;
}

int main()
{
    string s;
    getline(cin, s);
    string postFixExpr = convertToPostFix(s);
    cout << "Final postFixExpr = " << postFixExpr << endl;
    int res = eval(postFixExpr);
    cout << "result = " << res << endl;
    return 0;
}
