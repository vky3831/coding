/*
g++ 01_fibonacci.cpp
a.exe OR ./a.exe

for mac: 
clang++ 01_fibonacci.cpp
./a.out
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n = 4;
    int ans = fibo(n);
    cout<<ans;
}

void print(vector<int>& vect){
	cout<<"[";
	int n = vect.size();
	for(int i=0; i < n; i++){
		
		cout<<vect[i];
		if(i < n-1)
		cout<<", ";
	}
	cout<<"]"<<endl;
}

void print(vector<vector<int> >& vect){
	int n = vect.size();
    for(int i=0; i<n; i++){
        print(vect[i]);
    }
}
