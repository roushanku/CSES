// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
#define int long long int
 
const int INF = 1e17;
const int NINF = INF*(-1);

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

vector<pair<int,pair<int,int>>> adj;
int c = -1;
int id=1;
int id1=0;
for(int i=1;i<=m;i++){
    int a,b,d;
    cin>>a>>b>>d;

    adj.push_back({0-d,{a-1,b-1}});
}

vector <int> dist(n,1e17);

for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        int u = adj[j].second.first;
        int v = adj[j].second.second;
        int d = adj[j].first;

        if(d+dist[u]<dist[v]) dist[v]=d+dist[u];

    }
}

for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        int u = adj[j].second.first;
        int v = adj[j].second.second;
        int d = adj[j].first;

        if(d+dist[u]<dist[v]) dist[v]=INF;

    }
}

if(dist[n-1]==INF) cout<<-1<<"\n";
cout<<0-dist[n-1]<<"\n";

return 0;
}