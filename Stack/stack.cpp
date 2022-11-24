#include <iostream>
#include<stack>
#include<math.h>
using namespace std;

int top = -1;
#define MAX 100
char sstack[MAX];

class Stack
{
public:
    bool isFull()
    {
        return top == MAX - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }

    void push(char item)
    {
        if (isFull()) return;
            // cout << "Stack Overflow!" << endl;
        else
            sstack[++top] = item;
    }

    void pop()
    {
        if (isEmpty())
            return;
        int poped_item = sstack[top];
        --top;
    }

    char peek()
    {
        // if(isEmpty()) return;
        return sstack[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << sstack[i] << " ";
        cout << endl;
    }
};

// INFIX = (A+B)*C-D/E

int precedence(char ch) {
    switch(ch) {
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}

string infixToPostFix(string infix) {
    Stack stack;
    string expr = "";
    for(char ch : infix) {
        if(ch == '(') stack.push(ch);
        else if(ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') expr += ch;
        else if(precedence(ch) == 3) stack.push(ch);
        else if(precedence(ch) == 2) {
            while(precedence(stack.peek()) > 2) {
                expr += stack.peek();
                stack.pop();
            }
            stack.push(ch);
        }
        else if(precedence(ch) == 1) {
            while(precedence(stack.peek()) > 1) {
                expr += stack.peek();
                stack.pop();
            }
            stack.push(ch);
        }
        else if(precedence(ch) == 0) {
            while(stack.peek() != '(') {
                expr += stack.peek();
                stack.pop();
            }
            stack.pop();
        }
        
    }
    while(!stack.isEmpty()) {
        expr += stack.peek();
        stack.pop();
    }
    return expr;
}

double operation(double a, double b, char ch) {
    switch(ch) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a, b);
    }
}

double postfix_evaluate(string postfix) {
    // double result = 0;

    stack<double> stk;

    for(char ch : postfix) {
        if(ch >= '0' && ch <= '9') {
            stk.push(double(ch - '0'));
        }
        else {
            double b = stk.top();
            stk.pop();
            double a = stk.top();
            stk.pop();
            stk.push(operation(a, b, ch));
        }
    }
    return stk.top();
}

int main()
{
    
    string infix = "(9/3)+5*9-3^2";
    string postfix = infixToPostFix(infix);
    cout << "Infix : " << infix << endl;
    cout << "Postfix : " << postfix << endl;

    double res = postfix_evaluate(postfix);
    cout << "Evaluate : " << res << endl;
    
    return 0;
}