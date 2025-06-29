/*
g++ 07_ninja_training.cpp
a.exe OR ./a.exe

for mac: 
clang++ 07_ninja_training.cpp
./a.out

Problem Statement: A Ninja has an ‘N’ Day training schedule. 
He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
There are merit points associated with performing an activity each day. 
The same activity can’t be performed on two consecutive days. 
We need to find the maximum merit points the ninja can attain in N Days.

We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
Our task is to calculate the maximum number of merit points that the ninja can earn.

Link: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
Link: https://www.naukri.com/code360/problems/ninja-s-training_3621003
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

int maxScore_rec(int ind, int prev, vector<vector<int> >& grid){

    if(ind == 0){
        int maxSc = 0;
        for(int j=0; j<3; j++){
            if(j != prev){
                maxSc = max(maxSc, grid[ind][j]);
            }
        }
        return maxSc;
    }

    int maxScore = 0;
    for(int j=0; j<3; j++){
        if(j != prev){
            maxScore = max(maxScore, grid[ind][j] + maxScore_rec(ind-1, j, grid));
        }
    }
    return maxScore;
}

int maxScore_memo(int ind, int prev, vector<vector<int> >& grid, vector<vector<int> >& dp){

    if(ind == 0){
        int maxSc = 0;
        for(int j=0; j<3; j++){
            if(j != prev){
                maxSc = max(maxSc, grid[ind][j]);
            }
        }
        return maxSc;
    }
    if(dp[ind][prev] != -1) return dp[ind][prev];

    int maxScore = 0;
    for(int j=0; j<3; j++){
        if(j != prev){
            maxScore = max(maxScore, grid[ind][j] + maxScore_rec(ind-1, j, grid));
        }
    }
    return dp[ind][prev] = maxScore;
}

int main(){
    vector<vector<int>>grid{{10,40,70},{20,50,80},{30,60,90}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m+1, -1));

    // int ans = maxScore_rec(n-1, 3, grid);
    int ans = maxScore_memo(n-1, 3, grid, dp);
    // int ans = maxScore_rec(grid); // PENDING

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