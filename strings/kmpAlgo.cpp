/*
g++ kmpAlgo.cpp
a.exe

clang++ kmpAlgo.cpp
./a.out
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string txt = "abxabcabcaby";
    string pattern = "abcaby";

    int a = 5;
    int b = 6;
    int c = b & ~a;
    cout<< c << endl;
    
}