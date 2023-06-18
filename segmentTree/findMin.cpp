#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int arr[], int seg[]){
    if(low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = (high+low)/2;
    build(2 * ind + 1, low, mid, arr, seg);
    build(2 * ind + 2, mid + 1, high, arr, seg);
    seg[ind] = min(seg[2 * ind +1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int ql, int qr, int seg[]){
    // no overlap
    if(high < ql || low > qr) return INT_MAX;
    // complete overlap
    if(low >= ql && high <= qr) return seg[ind];

    // partial overlap
    int mid = (high+low)/2;
    int left = query(2 * ind + 1, low, mid, ql, qr, seg);
    int right  = query(2 * ind + 2, mid + 1, high, ql, qr, seg);
    return min(left, right);
}

void update(int ind, int low, int high, int seg[], int upi, int val){
    if(low == high){
        seg[ind] = val;
        return;
    }

    int mid = (low + high)/2;
    if(upi <= mid) update(2 * ind + 1, low, mid, seg, upi, val);
    else update(2 * ind + 2, mid + 1, high, seg, upi, val);

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main(){
    int n = 6;
    int arr[] = {2, 1, 0, 4, 3, 7};
    int seg[4 * n];
    build(0, 0, n-1, arr, seg); // (ind, low, high, arr, seg)
    update(0, 0, n-1, seg, 2, 4);
    cout<< query(0, 0, n-1, 1, 3, seg) << endl;
}