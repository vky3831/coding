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

int fibo_rec(int n, vector<int>& dp){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fibo_rec(n-1, dp) + fibo_rec(n-2, dp);
}

int fibo_memo(int n, vector<int>& dp){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fibo_memo(n-1, dp) + fibo_memo(n-2, dp);
}

int fibo_tab(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main(){
    int n = 4;
    vector<int> dp(n+1, -1);
    // int ans = fibo_memo(n, dp);
    int ans = fibo_tab(n);
    cout<<ans<<endl;
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
