/*
g++ 02_frog_jump.cpp
a.exe OR ./a.exe

for mac: 
clang++ 02_frog_jump.cpp
./a.out

Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. 
A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference.
We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

int minEnergy_tab(int ind, vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n);
    dp[0] = 0;
    for(int ind=1; ind<n; ind++){
        int oneStep = abs(heights[ind] - heights[ind-1]) + dp[ind-1];
        int twoStep = INT_MAX;
        if(ind>1) twoStep = abs(heights[ind] - heights[ind-2]) + dp[ind-2];
        dp[ind] = min(oneStep, twoStep);
    }
    return dp[ind-1];
}

int minEnergy_rec(int ind, vector<int>& heights){
    if(ind == 0) return 0;

    int oneStep = abs(heights[ind] - heights[ind-1]) + minEnergy_rec(ind-1, heights);
    int twoStep = INT_MAX;
    if(ind>1) twoStep = abs(heights[ind] - heights[ind-2]) + minEnergy_rec(ind-2, heights);

    return min(oneStep, twoStep);
}

int minEnergy_memo(int ind, vector<int>& heights, vector<int>& dp){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int oneStep = abs(heights[ind] - heights[ind-1]) + minEnergy_memo(ind-1, heights, dp);
    int twoStep = INT_MAX;
    if(ind>1) twoStep = abs(heights[ind] - heights[ind-2]) + minEnergy_memo(ind-2, heights, dp);

    return dp[ind] = min(oneStep, twoStep);
}

int main(){
    int a[] = {10,20,30,10};
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> heights(a, a + n);

    vector<int> dp(n, -1);
    // int ans = minEnergy_rec(n-1, heights);
    // int ans = minEnergy_memo(n-1, heights, dp);
    int ans = minEnergy_tab(n-1, heights);

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