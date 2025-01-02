/* 
# Description

You are given an integer N. 
You have to find all the permutations of N in lexicographic order.

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
    int n;
    cin>>n;

    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }


    do{
        for(int ele:v) cout<<ele<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(), v.end()));
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



