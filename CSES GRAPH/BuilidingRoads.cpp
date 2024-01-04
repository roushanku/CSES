// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

//no of roads = no of connected component -1
//and print one node from each connected component
void bfs(int node,vector<int> &vis,vector<int> adj[]){
    queue <int> q;
    q.push(node);
    vis[node]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

vector <int> adj[n];

while(m-->0){
    int u,v;
    cin>>u>>v;

    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

vector <int> ans;
vector <int> vis(n,0);
int ct=0;

for(int i=0;i<n;i++){
    if(!vis[i]){
        ct++;
        ans.push_back(i+1);
        bfs(i,vis,adj);
    }
}

cout<<ct-1<<"\n";

for(int i=0;i<ct-1;i++){
    cout<<ans[i]<<" "<<ans[i+1]<<"\n";
}
return 0;
}