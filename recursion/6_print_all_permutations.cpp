/*
Given a string S, the task is to write a program to print all permutations of a given string. 
A permutation also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length N has N! permutations. 

Input: S = “ABC”
Output: “ABC”, “ACB”, “BAC”, “BCA”, “CBA”, “CAB”

Input: S = “XY”
Output: “XY”, “YX”
*/

#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& vect);
void print(vector<vector<int> >& vect);

void util(int ind, string s, int n, vector<string>& ans){
    if(ind >= n){ans.push_back(s); return;}

    for(int i=ind; i<n; i++){
        swap(s[i], s[ind]);
        util(ind+1, s, n, ans);
        swap(s[i], s[ind]);
    }
}

vector<string> permute(string s){
    int n = s.size();
    int ind = 0;
    vector<string> ans;
    util(ind, s, n, ans);
    return ans;
}

/* Driver */ 
int main(){

    string s = "ABC";

    vector<string> ans = permute(s);
    cout<<"[";
	int n = ans.size();
	for(int i=0; i < n; i++){
		
		cout<<ans[i];
		if(i < n-1)
		cout<<", ";
	}
	cout<<"]"<<endl;
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