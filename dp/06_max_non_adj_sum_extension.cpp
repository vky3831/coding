

/*
g++ 04_max_non_adj_sum.cpp
a.exe OR ./a.exe

for mac: 
clang++ 05_max_non_adj_sum.cpp
./a.out

A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. 
Therefore the first and the last house are adjacent to each other. 
The security system in the street is such that if adjacent houses are robbed, the police will get notified.
Given an array of integers “Arr'' which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.

Link: https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/

*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

int maxNonAdjSum_tab(vector<int>& elements){
    int n = elements.size();
    vector<int> dp(n);
    dp[0] = elements[0];

    for(int ind=1; ind<n; ind++){
        int pick = elements[ind];
        if(ind-2 >= 0){
            pick += dp[ind-2];
        }
        int notPick = dp[ind-1];

        dp[ind] = max(pick, notPick);
    }
    return dp[n-1];
}

int maxNonAdjSum_rec(int ind, vector<int>& elements){
    if(ind == 0) return elements[ind];

    int pick = elements[ind];
    if(ind-2 >= 0){
        pick += maxNonAdjSum_rec(ind-2, elements);
    }
    int notPick = maxNonAdjSum_rec(ind-1, elements);

    return max(pick, notPick);
}

int maxNonAdjSum_memo(int ind, vector<int>& elements, vector<int>& dp){
    if(ind == 0) return elements[ind];
    if(dp[ind] != -1) return dp[ind];

    int pick = elements[ind];
    if(ind-2 >= 0){
        pick += maxNonAdjSum_memo(ind-2, elements);
    }
    int notPick = maxNonAdjSum_memo(ind-1, elements);

    return dp[ind] = max(pick, notPick);
}

int houseRobber(vector<int>& elements){
    // PENDING
}

int main(){
    int a[] = {2,1,4,9};
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> elements(a, a + n);
    
    vector<int> dp(n, -1);

    // int ans = maxNonAdjSum_rec(n-1, elements);
    // int ans = maxNonAdjSum_memo(n-1, elements, dp);
    // int ans = maxNonAdjSum_tab(elements);
    houseRobber(elements)

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