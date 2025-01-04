#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;

set<int> getDigits(int n){
    set<int> st;
    while(n > 0){
        st.insert(n % 10);
        n /= 10;
    }
    return st;
}


void solve() {
    int n;
    cin>>n;

    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        set<int> digits = getDigits(i);
        int mn = INF;
        for(int digit:digits){
            if(i-digit >= 0) mn = min(mn, dp[i - digit]);
        }
        dp[i] = mn + 1;
    }

    cout<<dp[n];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}



