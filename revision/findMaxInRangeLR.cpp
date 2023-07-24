#include<bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;
    int sz;

    void build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int ql, int qr){
        // no overlap
        if(high < ql || qr < low){
            return INT_MIN;
        }

        // complete overlap
        if(ql <= low && high <= qr) return seg[ind];

        int mid = low + ((high - low)>>1);
        int left = query(2 * ind + 1, low, mid, ql, qr);
        int right = query(2 * ind + 2, mid + 1, high, ql, qr);
        return max(left, right);
    }

    void pointUpdate(int ind, int low, int high, int upi, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = low + ((high - low)>>1);
        if(upi <= mid) pointUpdate(2 * ind + 1, low, mid, upi, val);
        else pointUpdate(2 * ind + 2, mid, high, upi, val);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }


    public:
    SGTree(int n){
        sz = n;
        seg.resize(4 * n + 1);
    }

    void build(vector<int>& arr){
        // build(ind, low, high, arr)
        build(0, 0, sz-1, arr);
    }

    int query(int l, int r){
        // query(ind, low, high, ql, qr)
        return query(0, 0, sz-1, l, r);
    }

    void pointUpdate(int upi, int val){
        // pointUpdate(ind, low, high, upi, val)
        pointUpdate(0, 0, sz-1, upi, val);
    }


};

int main(){
    int arr[] = {2, 3, 1, 12, 54, 67, 37, 23, 90, 0, 45};
            //   0  1  2  3   4   5   6   7   8   9  10
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+n);
    SGTree sg(n);
    sg.build(vec);
    cout<<"query: "<<sg.query(4, 10)<<endl;  
}