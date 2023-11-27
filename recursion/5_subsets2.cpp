/*
g++ 5_subsets2.cpp
a.exe

Given an integer array nums that may contain duplicates, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

void util(int ind, vector<int>& nums, vector<vector<int> >& ans, vector<int>& ds){
    ans.push_back(ds);
    if(ind >= nums.size()) return;

    for(int i = ind; i < nums.size(); i++){
        if(i > ind && nums[i-1] == nums[i]) continue;
        ds.push_back(nums[i]);
        util(i+1, nums, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& nums) {
    int ind = 0;
    vector<int> ds;
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    util(ind, nums, ans, ds);
    return ans;
}

int main() {

    int a[] = {1,2,2};
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> arr(a, a + n);

    vector<vector<int> > ans = subsets(arr);
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