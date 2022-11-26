#include<bits/stdc++.h>

using namespace std;

int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '.') return 0;
    else return -1;
}

string infixToPostfix(string infix) {

    string postfix = "";
    int i = 0;

    stack<char> stk;
    for(i; infix[i]; i++) {
        char ch = infix[i];
        if(ch == '(') stk.push(ch);
        else if(ch == ')') {
            while(!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                postfix += ',';
                stk.pop();
            }
            stk.pop(); 
        }
        else {
            int priority = precedence(ch);
            if(priority == 0) {
                while(precedence(infix[i]) == 0) {
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += ',';
            }
            else {
                if(stk.empty()) stk.push(ch);
                else {
                    while(!stk.empty() && stk.top() != '(' && (priority <= precedence(stk.top()))) {
                        postfix += stk.top();
                        postfix += ',';
                        stk.pop();
                    }
                stk.push(ch);
                }
            }
        }
    }

    while(!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
} 

int main() {

    string infix = "(A+B)/190.3*3.4+(c*d)";
    string ans = infixToPostfix(infix);

    cout << ans << endl;

    return 0;

}