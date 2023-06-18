#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& vect);

void merge(vector<int>& arr, int low, int mid, int high){
    int l = low, r = mid+1;
    vector<int> temp;
    while(l <= mid && r <= high){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        } else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l <= mid){
        temp.push_back(arr[l]);
            l++;
    }
    while(r <= high){
        temp.push_back(arr[r]);
        r++;
    }

    for(int i=low; i<= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low)/2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr){
    mergeSort(arr, 0, arr.size()-1);
}

int main(){
    int arr[] = {16, 5, 13, 24, 87, 76};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    mergeSort(vec);
    print(vec);
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