/* 
# Description

You are given Q queries and have to perform the following operations:

add x y - add student name X (string in lowercase alphabets) with marks y (integer). If it already exists, update.
erase x - erase marks of student with name x, if the entry exists
print x - print marks of student with name x, if entry is not there for x, print 0.

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
    map<string, int> mp;
    string opr, name;
    for(int q=0; q<n; q++){
        cin>>opr>>name;
        if(opr == "add"){
            cin>>x;
            mp[name] = x;
        }
        else if(opr == "erase"){
            if(mp.find(name) != mp.end()) mp.erase(name);
        }
        else{
            cout<<mp[name]<<endl;
        }
    }

    
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



