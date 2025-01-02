#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;


void solve() {
    int n;
    cin>>n;

    vector<int> dp(n+1);
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=6; j++){
            if(i-j >= 0){
                sum = (sum + dp[i-j]) % mod;
            }
        }
        dp[i] = sum;
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



