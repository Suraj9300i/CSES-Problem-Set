
/* 
# Description

You are given an array A of N integers. 
A sequence is called good if the value x occurs x times in the array. 
Find the minimum number of integers you need to delete from A to make it good.

*/

#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

/***********॥ ॐ श्री गणेशाय नमः, सरस्वत्यै नमः ॥****************/

void init() {
    int n, x;
    cin>>n;

    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>x;
        mp[x]++;
    }

    int cnt = 0;
    for(auto it:mp){
        if(it.first != it.second){
            cnt += it.second >= it.first ? (it.second - it.first) : it.second;
        }
    }
    cout<<cnt<<endl;
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init();
    }
    return 0;
}



