/*
g++ 02_frog_jump_extension.cpp
a.exe OR ./a.exe

for mac: 
clang++ 02_frog_jump_extension.cpp
./a.out

This is a follow-up question to “Frog Jump” discussed in the previous article.
In the previous question, the frog was allowed to jump either one or two steps at a time.
In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.

Link: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/


*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

int minEnergy_tab(int ind, vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n);
    dp[0] = 0;
    for(int ind=1; ind<n; ind++){
        int minStep = INT_MAX;
        for(int i=1; i<=k; i++){
            if(ind - i >= 0)
            minStep = min(minStep, abs(heights[ind] - heights[ind-i]) + dp[ind-i]);
        }
        dp[ind] = minStep;
    }
    return dp[ind-1];
}

int minEnergy_rec(int ind, vector<int>& heights, int k){
    if(ind == 0) return 0;

    int minStep = INT_MAX;
    for(int i=1; i<=k; i++){
        if(ind - i >= 0)
        minStep = min(minStep, abs(heights[ind] - heights[ind-i]) + minEnergy_rec(ind-i, heights, k));
    }

    return minStep;
}

int minEnergy_memo(int ind, vector<int>& heights, vector<int>& dp, int k){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int minStep = INT_MAX;
    for(int i=1; i<=k; i++){
        if(ind - i >= 0)
        minStep = min(minStep, abs(heights[ind] - heights[ind-i]) + minEnergy_memo(ind-i, heights, dp, k));
    }

    return dp[ind] = minStep;
}

int main(){
    int a[] = {10,20,30,10};
    int k = 2;
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> heights(a, a + n);

    vector<int> dp(n, -1);
    // int ans = minEnergy_rec(n-1, heights, k);
    // int ans = minEnergy_memo(n-1, heights, dp, k);
    int ans = minEnergy_tab(n-1, heights, k);

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