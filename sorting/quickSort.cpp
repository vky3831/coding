#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& vect);


int findPartitonIndex(vector<int>& arr, int low, int high){
	int pivotInd = low;
	int pivot = arr[pivotInd];
	int l=low, r = high;
	while(l < r){
		// find first element greater than pivot from left
		while(arr[l] <= pivot && l <= high){
			l++;
		}
		// find first element smaller than pivot from right
		while(arr[r] > pivot && r >= low){
			r--;
		}

		// if (l < r) swap [first_element_greater_than pivot_from_left] and [first_element_smaller_than_pivot_from_right]
		if(l < r){
			swap(arr[l], arr[r]);
		}
	}

	// swap [pivotInd] and [r]
	swap(arr[pivotInd], arr[r]);

	return r;
}

void quickSort(vector<int>& arr, int low, int high){
	if(low >= high){
		return;
	}

	int partitionInd = findPartitonIndex(arr, low, high);
	quickSort(arr, low, partitionInd-1);
	quickSort(arr, partitionInd+1, high);
}

void quickSort(vector<int>& arr){
    quickSort(arr, 0, arr.size()-1);
}

int main(){
    int arr[] = {16, 5, 13, 24, 87, 76};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    quickSort(vec);
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
