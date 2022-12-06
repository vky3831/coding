/*
Given a list arr of N integers, print sums of all subsets in it.

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

*/
#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

void util(int ind, int sum, vector<int>& arr,vector<int>& ans){
    if(ind ==  arr.size()) {
        ans.push_back(sum);
        return;
    }

    util(ind+1, sum + arr[ind], arr, ans); // take
    util(ind+1, sum, arr, ans); // not take
}

vector<int> subsetSums(vector<int> arr)
{
    vector<int> ans;
    util(0, 0, arr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {

    int a[] = {2, 3};
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> arr(a, a + n);

    vector<int> ans = subsetSums(arr);
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