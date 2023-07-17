/* Reversse stack using recursion */
// g++ reverseStack.cpp
// ./a.out | ./a.exe

#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> stk){
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

void pushBack(int ele, stack<int>& stk){
    if(stk.empty()){
        stk.push(ele);
    }else{
        int t = stk.top();
        stk.pop();

        pushBack(ele, stk);
        stk.push(t);
    }
}

void reverse(stack<int>& stk){
    if(!stk.empty()){
        int t = stk.top();
        stk.pop();
        reverse(stk);

        pushBack(t, stk);
    }
    return;
}

void reverseStack(stack<int>& stk){
    reverse(stk);
}

int main(){
    stack<int> stk;
    stk.push(4);
    stk.push(3);
    stk.push(2);
    stk.push(1);
    cout<<"Original Stack \n";
    printStack(stk);
    reverseStack(stk);
    cout<<"Reversed Stack \n";
    printStack(stk);
    
}