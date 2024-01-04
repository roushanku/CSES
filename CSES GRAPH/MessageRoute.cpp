// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//as the graph has wt "1" -> we can use bfs (and obviously dijkstra)
int n,m;
cin>>n>>m;

vector <int> adj[n];

while(m-->0){
    int u,v;
    cin>>u>>v;

    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

// queue <pair<int,int>> q;
// q.push({0,0}); // {d,node}
// vector <int> dist(n,1e9);
// vector <int> parent(n,-1);

// while(!q.empty()){
//     int node = q.front().second;
//     int d = q.front().first;
//     q.pop();

//     for(auto it:adj[node]){
//         if(1+d<dist[it]){
//             dist[it]=1+d;
//             q.push({dist[it],it});
//             parent[it]=node;
//         }
//     }
// }


vector <int> dist(n,1e9);
vector <int> parent(n,-1);

priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pq.push({0,0}); //{d,node}
dist[0]=0;

while(!pq.empty()){
    int node = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    for(auto it:adj[node]){
        if(d+1<dist[it]){
            dist[it]=1+d;
            pq.push({dist[it],it});
            parent[it]=node;
        }
    }
}
if(dist[n-1]==1e9) cout<<"IMPOSSIBLE"<<"\n";
else cout<<dist[n-1]+1<<"\n";

vector <int> ans;
ans.push_back(n-1);
int it=n-1;
while(it!=0){
    ans.push_back(parent[it]);
    it=parent[it];
}
reverse(ans.begin(),ans.end());
for(auto it:ans) cout<<it+1<<" ";
cout<<"\n";
return 0;
}