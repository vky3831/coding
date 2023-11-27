/*

g++ 2_combinationSum.cpp
a.exe

39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/

#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

void util(int ind, int target, vector<int>& tmp_arr, vector<vector<int> >& ans, vector<int>& candidates, int n){
    if(target == 0){
        ans.push_back(tmp_arr);
        return;        
    }
    if(ind == n){
        return;
    }

    if(target >= candidates[ind]){
        tmp_arr.push_back(candidates[ind]);
        util(ind, target-candidates[ind], tmp_arr, ans, candidates, n); // take
        tmp_arr.pop_back();
    }

    util(ind+1, target, tmp_arr, ans, candidates, n); // not take
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp_arr;
        vector<vector<int> > ans;
        int n = candidates.size();
        int ind = 0; 
        util(ind, target, tmp_arr, ans, candidates, n);

        return ans;
}

int main(){
    int a[] = { 2,3,6,7 };
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> arr(a, a + n);
    int target = 7;

    vector<vector<int> > ans = combinationSum(arr, target);
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