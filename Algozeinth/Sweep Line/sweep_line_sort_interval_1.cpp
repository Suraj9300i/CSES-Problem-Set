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

void init() {
    int n, l, s, e;
    cin>>n>>l;
    vector<pair<int, int>> intervals(n);
    for(int i=0; i<n; i++){
        cin>>intervals[i].first>>intervals[i].second;
    }
    
    sort(intervals.begin(), intervals.end());

    if(intervals[0].first != 0){
        cout<<"-1";
        return;
    }

    int last = intervals[0].second;
    int cnt = 1;
    int i = 1;
    bool flag = false;
    while(i < n && last < l){
        int mx = last;
        int j = i;
        while(j < n && intervals[j].first <= last){
            mx = max(mx, intervals[j].second);
            j++;
        }

        if(mx == last){
            flag = true;
            break;
        }

        cnt++;
        last = mx;
        i = j;
    }

    // cerr<<last<<" "<<flag;

    if(flag || last < l) cout<<"-1";
    else cout<<cnt;
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



