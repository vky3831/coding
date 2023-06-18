#include<bits/stdc++.h>
using namespace std;

class SGTRangeSum {
    public:
    vector<int> seg, lazy;
    int sz;

    SGTRangeSum(int n){
        sz = n;
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(int arr[]){
        build(0, 0, sz-1, arr);
    }

    void build(int ind, int low, int high, int arr[]){
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];

    }

    void rangeUpdate(int l, int r, int val){
        rangeUpdate(0, 0, sz-1, l, r, val);
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int val){
        // update pending
        if(lazy[ind] != 0){
            // update current
            seg[ind] += (high - low + 1) * lazy[ind];

            // propagate the update to children nodes via lazy tree
            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap
        // high l OR r low
        if(high < l || r < low){
            return;
        }

        // complete overlap
        // l <= low and high <= r
        // update current node in seg and propagte update to children nodes via lazy
        if(l <= low && high <= r){
            seg[ind] += (high - low + 1) * val;

            if(low != high){
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // partial overlap
        // go left and right
        int mid = (high + low) >> 1;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid+1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];

    }

    int query(int l, int r){
        return query(0, 0, sz-1, l, r);
    }

    int query(int ind, int low, int high, int l, int r){
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];

            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap
        // high l or r low
        // return value which doesn' affects the result
        if(high < l or r < low){
            return 0;
        }

        // complete overlap
        // l low and high r
        // return seg[ind]
        if(l <=  low and high <= r){
            return seg[ind];
        }

        // partial overlap
        int mid = (high + low) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid+1, high, l, r);
        
        return left + right;
    }

    void pointUpdate(int upi, int val){
        pointUpdate(0, 0, sz-1, upi, val);
    }

    void pointUpdate(int ind, int low, int high, int upi, int val){
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];

            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        if(low == high){
            seg[ind] = val;
            return;
        }

        int mid = (high + low) >> 1;

        if(upi <= mid) pointUpdate(2 * ind + 1, low, mid, upi, val);
        else pointUpdate(2 * ind + 2, mid+1, high, upi, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main(){
    // { 2, 3, 7, 0, 6, 8}
    int arr[] = {2, 3, 7, 0, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;
    SGTRangeSum sgt(n);
    sgt.build(arr);
    res = sgt.query(1, 3); // 10
    cout<<res<<endl;
    sgt.pointUpdate(3, 5); // { 2, 3, 7, 5, 6, 8}
    res = sgt.query(1, 3); // 15
    cout<<res<<endl;
    sgt.rangeUpdate(0, 1, 2); // { 4, 5, 7, 5, 6, 8}
    res = sgt.query(1, 3); // 17
    cout<<res<<endl;
    sgt.pointUpdate(3, 0); // { 4, 5, 7, 0, 6, 8}
    res = sgt.query(1, 3); // 12
    cout<<res<<endl;

}