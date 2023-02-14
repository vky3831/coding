#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

// print all subsequences of the given array
// g++ 1_print_all_subsequences.cpp
// ./a.exe

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
	tmp_arr.pop_back(); // not take
	util(index+1, tmp_arr, n, arr); 
	
}

int main() {
	int a[] = { 10, 20, 30 };
    int n = sizeof(a) / sizeof(a[0]);
	vector<int> arr(a, a + n);

	vector<int> tmp_arr;
	util(0,  tmp_arr, n, arr);
	
}
