#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;


void solve() {
    int n;
    cin>>n;

    vector<string> mat(n);
    for(int i=0; i<n; i++){
        cin>>mat[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(mat[0][0] == '.') dp[0][0] = 1;
    for(int i=1; i<n; i++){
        if(mat[i][0] == '.') dp[i][0] = dp[i-1][0];
        if(mat[0][i] == '.') dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(mat[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout<<dp[n-1][n-1];
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



