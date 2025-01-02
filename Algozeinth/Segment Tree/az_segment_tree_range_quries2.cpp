#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif
}

/***********॥ ॐ श्री गणेशाय नमः, सरस्वत्यै नमः ॥****************/

class Stree{
public:
    vector<int> arr;
    vector<int> tree;

    Stree(vector<int> arr, int n){
        this->arr = arr;
        tree.resize(4 * n, 0);
        build(0, n-1, 0);
    }

    void build(int start, int end, int ind){
        if(start == end){
            tree[ind] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(start, mid, 2 * ind + 1);
        build(mid+1, end, 2 * ind + 2);
    }

    void update(int start, int end, int ind, int qs, int qe, int x){
        if(qs > end || qe < start) return;
        if(start >= qs && end <= qe){
            tree[ind] += x;
            return;
        }

        int mid = start + (end - start) / 2;
        update(start, mid, 2*ind+1, qs, qe, x);
        update(mid+1, end, 2*ind+2, qs, qe, x);
    }

    int query(int start, int end, int ind, int k){
        if(start == end) return tree[ind];

        int mid = start + (end - start) / 2;
        int sum = tree[ind];
        if(k <= mid) sum += query(start, mid, 2 * ind + 1, k);
        else sum += query(mid+1, end, 2 * ind + 2, k);
        return sum;
    }
};


void init() {
    int n, q, qt, x, y, val;
    cin>>n>>q;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Stree st(arr, n);

    while(q--){
        cin>>qt;
        if(qt == 1){
            cin>>x>>y>>val;
            st.update(0, n-1, 0, x-1, y-1, val);
        }
        else{
            cin>>x;
            cout<<(st.query(0, n-1, 0, x-1))<<endl;
        }
    }
    
}

signed main() {
    fastIO();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        init();
    }
    return 0;
}



