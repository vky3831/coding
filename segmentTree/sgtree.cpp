#include<bits/stdc++.h>
using namespace std;

class SGTree {
    public:
    vector<int> seg;
    int sz;

    SGTree(int n){
        sz = n;
        seg.resize(4 * n + 1);
    }

    void build(int arr[]){
        build(0, 0, sz-1, arr);
    }
    
    void build(int ind, int low, int high, int arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid+1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ql, int qr){
        return query(0, 0, sz-1, ql, qr);
    }
    int query(int ind, int low, int high, int ql, int qr){
        // no overlap
        if(high < ql || low > qr) return INT_MAX;

        // complete overlap
        if(low >= ql && high <= qr) return seg[ind];

        // partial overlap
        int mid = (low+high)/2;
        int left = query(2 * ind + 1, low, mid, ql, qr);
        int right = query(2 * ind + 2, mid+1, high, ql, qr);

        return min(left, right);
    }

    void update(int upi, int val){
        update(0, 0, sz-1, upi, val);
    }

    void update(int ind, int low, int high, int upi, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = (low + high)/2;

        if(upi <= mid) update(2 * ind + 1, low, mid, upi, val);
        else update(2 * ind + 2, mid+1, high, upi, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    } 
};

int main(){
    int n = 6;
    int arr[] = {2, 1, 0, 4, 3, 7};
    SGTree sg(n);
    sg.build(arr); // (ind, low, high, arr, seg)
    cout<< sg.query(1, 3) << endl;
    sg.update(2, 4);
    cout<< sg.query(1, 3) << endl;
}