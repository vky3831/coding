/*
g++ 3_combinationSum2.cpp
a.exe

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

void util(int ind, int target, vector<int>& candidates, vector<vector<int> >& ans, vector<int>& ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i=ind; i < candidates.size(); i++){
        if(i>ind && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        ds.push_back(candidates[i]); // take
        util(i+1, target-candidates[i], candidates, ans, ds);
        ds.pop_back(); // not take
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    util(0, target, candidates, ans, ds);
    return ans;
}

/* Driver */ 
int main(){

    int a[] = { 10,1,2,7,6,1,5 };
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> arr(a, a + n);
    int target = 8;

    vector<vector<int> > ans = combinationSum2(arr, target);
    print(ans);
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