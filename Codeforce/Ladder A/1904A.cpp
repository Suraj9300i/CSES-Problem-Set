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


void solve() {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;

    vector<pair<int, int>> moves = {
        {-b, -a}, {-b, a}, {-a, -b}, {-a, b},
        {a, -b}, {a, b}, {b, -a}, {b, a}
    };

    

    set<pair<int, int>> st1, st2;
    for(int i=0; i<8; i++){
        st1.insert({xk + moves[i].first, yk + moves[i].second});
        st2.insert({xq + moves[i].first, yq + moves[i].second});
    }

    int ans = 0;
    for(auto it:st1){
        if(st2.find(it) != st2.end()){
            ans++;
        }
    }

    cout<<ans<<endl;
}

signed main() {
    fastIO(true);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}



