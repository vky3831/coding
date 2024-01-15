#include<bits/stdc++.h>
using namespace std;

/*
clang++ interviewAdobe.cpp
./a.out
*/
/*

l > m left unsorted
l < m left sorted
0 1 2 3 4 5 6 7 8
3 4 5 6 7 8 9 1 2 
l       m        h


0 1 2 3 4 5 6 7 8
8 9 1 2 3 4 5 6 7
l       m        h


h > m sorted


*/
int search(vector<int> nums, int ele){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == ele){
            return mid;
        }else if(nums[high] > nums[mid]){ // right sorted
            if(ele > nums[mid] && ele <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }else{ // left sorted
            if(ele < nums[mid] && ele >= nums[low]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    // int arr[] = {4, 5, 1, 2, 3};
    // int arr[] = {3, 4, 5, 6, 7, 8, 9, 1, 2 };
    int arr[] = {8, 9, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    
    cout<<search(vec, 8);
    cout<<search(vec, 9);
    cout<<search(vec, 1);
    cout<<search(vec, 2);
    cout<<search(vec, 3);
    cout<<search(vec, 4);
    cout<<search(vec, 5);
    cout<<search(vec, 6);
    cout<<search(vec, 7);

}

/*
0 1 2 3 4
4 5 1 2 3
l   m   h

l > m left unsorted
l < m left sorted
0 1 2 3 4 5 6 7 8
3 4 5 6 7 8 9 1 2 
l       m        h

l=0 h=8 m=4

h > m sorted


*/

/*



*/