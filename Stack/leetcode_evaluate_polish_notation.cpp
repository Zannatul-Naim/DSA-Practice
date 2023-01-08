class Solution {
public:

int calculate(int a, int b, string s) {
         if(s == "+") return a+b;
         else if(s == "-") return a-b;
         else if(s == "*") return a*b;
         else if(s == "/") return a/b;
         else return a+b;
     }

    int evalRPN(vector<string>& tokens) {
        
     stack < int > stk;

     

     for(int i = 0; i < tokens.size(); i++) {
         if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
             int b = stk.top();
             stk.pop();
             int a = stk.top();
             stk.pop();

             stk.push(calculate(a, b, tokens[i]));
         } else {
             stk.push(stoi(tokens[i]));
         }

     } 
         int ans = stk.top();
    return ans;  
    }

};
