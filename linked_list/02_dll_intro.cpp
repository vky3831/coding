#include<bits/stdc++.h>
using namespace std;
/*
g++ 02_dll_intro.cpp
a.exe

clang++ 02_dll_intro.cpp
./a.out
*/

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

    Node(int val, Node* next, Node* prev){
        this->data = val;
        this->next = next;
        this->prev = prev;
    }
};