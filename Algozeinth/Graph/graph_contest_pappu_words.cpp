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

map<char, set<char>> graph;

void init() {
    int n;
    cin>>n;

    vector<string> words(n);
    vector<int> rank(n);

    for(int i=0; i<n; i++) cin>>words[i];
    for(int i=0; i<n; i++) cin>>rank[i];

    vector<string> arrangedWords(n);
    for(int i=0; i<n; i++){
        int r = rank[i] - 1;
        string word = words[r];
        arrangedWords[i] = word;
    }

    for(string s:arrangedWords) cout<<s<<endl;

    set<char> st;
    for(int i=1; i<n; i++){
        string s1 = arrangedWords[i-1];
        string s2 = arrangedWords[i];
        int x = min(s1.size(), s2.size());
        for(int j=0; j<x; j++){
            st.insert(s1[j]);
            st.insert(s2[j]);
            if(s1[j] != s2[j]){
                graph[s1[j]].insert(s2[j]);
                break;
            }
        }
    }

    map<char, int> indegree;
    for(auto it:graph){
        for(auto ch:graph[it.first]){
            indegree[ch]++;
        }
    }

    for(char ch:st){
        cout<<ch<<" : ";
        for(char c:graph[ch]) cout<<c<<" ";
        cout<<endl;
    }

    queue<char> qu;
    vector<char> topo;
    for(auto ch:st){
        if(indegree[ch] == 0){
            qu.push(ch);
        }
    }
    
    while(!qu.empty()){
        char ch = qu.front();
        qu.pop();
        topo.push_back(ch);

        for(char nbr:graph[ch]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                qu.push(nbr);
            }
        }
    }

    if(topo.size() == st.size()) cout<<"YES";
    else cout<<"NO";
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



