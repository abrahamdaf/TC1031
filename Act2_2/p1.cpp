#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stack<char> stck;
    for(int i = 0; i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stck.push(s[i]);
        }
        if(s[i] == ')'){
            if(!stck.empty()){
                if (stck.top() == '('){
                    stck.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
        else if(s[i] == '}'){
            if(!stck.empty()){
                if (stck.top() == '{'){
                    stck.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
        else if(s[i] == ']'){
            if(!stck.empty()){
                if (stck.top() == '['){
                    stck.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if (!stck.empty()){
        return false;
    }else{
        return true;
    }
}