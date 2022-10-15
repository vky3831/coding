#include<bits/stdc++.h>
using namespace std;

// print all subsequences of the given array

void print(vector<int>& tmp_arr){
	cout<<"[";
	int n = tmp_arr.size();
	for(int i=0; i < n; i++){
		
		cout<<tmp_arr[i];
		if(i < n-1)
		cout<<", ";
	}
	cout<<"]"<<endl;
}

void util(int index, vector<int>& tmp_arr, int n, vector<int>& arr){
	if(index >= n){
		print(tmp_arr); return;
	}
	
	tmp_arr.push_back(arr[index]); // take
	util(index+1, tmp_arr, n, arr); 
	tmp_arr.pop_back();
	util(index+1, tmp_arr, n, arr); // not take
	
}

int main() {
	vector<int> arr{3, 2, 1};
	int n = arr.size();
	vector<int> tmp_arr;
	util(0,  tmp_arr, n, arr);
	
}
