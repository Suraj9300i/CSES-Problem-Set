#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void fastIO(bool useFiles = false) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (useFiles) {
        #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt","w",stderr);
        #endif
    }
}

// Debugging utilities
template<class T> void _print(T x) { cerr << x; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for(T ele : v) cerr << ele << " "; cerr << "]\n"; }
template<class T> void _print(T arr[], int n) { cerr << "[ "; for (int i = 0; i < n; i++) cerr << arr[i] << " "; cerr << "]\n"; }
template<class T1, class T2> void _print(pair<T1, T2> p) { cerr << "{" << p.first << ", " << p.second << "} "; }
template<class T> void _print(set<T> v) { cerr << "[ "; for (T ele : v) cerr << ele << " "; cerr << "]"; }
template<class T1, class T2> void _print(map<T1, T2> m) { cerr << "[ "; for (auto p : m) cerr << "{" << p.first << ", " << p.second << "} "; cerr << "]"; }

class Stree{
    vector<int> arr;
    vector<int> tree;
public:
    Stree(vector<int> arr, int n){
        this->arr = arr;
        tree.resize(4 * n, 0);
        buildTree(0, n-1, 0);
    }

    void buildTree(int start, int end, int ind){
        if(start == end){
            tree[ind] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        buildTree(start, mid, 2 * ind + 1);
        buildTree(mid+1, end, 2 * ind + 2);
    }

    void update(int start, int end, int ind, int qs, int qe, int val){
        if(qe < start || qs > end) return;
        if(start >= qs && end <= qe){
            tree[ind] += val;
            return;
        }

        int mid = start + (end - start) / 2;
        update(start, mid, 2 * ind + 1, qs, qe, val);
        update(mid+1, end, 2 * ind + 2, qs, qe, val);
    }

    int query(int start, int end, int ind, int k){
        if(start == end) return tree[ind];

        int mid = start + (end - start) / 2;
        if(k <= mid) return tree[ind] + query(start, mid, 2*ind + 1, k);
        else return tree[ind] + query(mid+1, end, 2*ind + 2, k);
    }
};

void solve() {
    int n, q, qt, a, b, c;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Stree st(arr, n);
    while(q--){
        cin>>qt;
        if(qt == 1){
            cin>>a>>b>>c;
            st.update(0, n-1, 0, a-1, b-1, c);
        }
        else{
            cin>>a;
            cout<<(st.query(0, n-1, 0, a-1))<<endl;
        }
    }
}

signed main() {
    fastIO(true);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}



