#include<bits/stdc++.h>
using namespace std;
/*
g++ productOfMaxOfAllSubsets.cpp
a.exe

clang++ productOfMaxOfAllSubsets.cpp
./a.out
*/

/*
Product of the maximums of all subsets of an array

Given an array arr[] consisting of N positive integers, the task is to find the product of the maximum of all possible subsets of the given array. Since the product can be very large, print it to modulo (109 + 7).

Examples:

Input: arr[] = {1, 2, 3}
Output:
Explanation:
All possible subsets of the given array with their respective maximum elements are:

{1}, the maximum element is 1.
{2}, the maximum element is 2.
{3}, the maximum element is 3.
{1, 2}, the maximum element is 2.
{1, 3}, the maximum element is 3.
{2, 3}, the maximum element is 3.
{1, 2, 3}, the maximum element is 3.
The product of all the above maximum element is 1*2*3*2*3*3*3 = 324.

Input: arr[] = {1, 1, 1, 1}
Output: 1

Appraoch:

The idea is to count the number of times each array element occurs as the maximum element among all possible subsets formed.
An array element arr[i] is a maximum if and only if all the elements except arr[i] are smaller than or equal to it.
Therefore, the number of subsets formed by all elements smaller than or equal to each array element arr[i] contributes to the count of subsets having arr[i] as the maximum element.
Follow the steps below to solve the problem:

Initialize a variable, say maximumProduct as 1 that stores the resultant product of maximum elements of all subsets.
Sort the given array arr[] in the increasing order.
Traverse the array from the end using the variable i and perform the following steps:
Find the number of subsets that are smaller than the current element arr[i] as (2^i – 1) and store it in a variable say P.
Since the array element arr[i] contributes P number of times, therefore multiply the value arr[i], P times to the variable maximumProduct.
Find the product of the array element with maximumProduct for including all the subsets of size 1.
After completing the above steps, print the value of maximumProduct as the resultant maximum product.
*/

int productOfMaxOfAllSubsets(vector<int> nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> _two_power_i(n);
    _two_power_i[0] = 1;
    for(int i=1; i<n; i++){
        _two_power_i[i] = _two_power_i[i-1] * 2; 
    }

    long long ans = 1;
    for(int i=0; i<n; i++){
        int count = _two_power_i[i];
        ans *= pow(nums[i], count);
    }

    return ans;
    

}

int main(){
    int arr[] = {2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);

    int ans = productOfMaxOfAllSubsets(vec);
    cout<<ans;
}

