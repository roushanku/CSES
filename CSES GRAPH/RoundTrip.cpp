// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int sv,ev;

bool dfs(vector <int> adj[],vector <int> &parent,vector <int> &vis,int i,int p){
    vis[i]=1;
    parent[i]=p;

    for(auto u:adj[i]){
        if(!vis[u]){
            if(dfs(adj,parent,vis,u,i)) return true;;
        }

        else{
            if(u!=p) {
                sv=u-1;
                ev=i-1;
                return true;
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
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

bool ok = false;
vector <int> parent(n,-1);
vector <int> vis(n,0);

for(int i=0;i<n;i++){
    if(!vis[i]){
        if(dfs(adj,parent,vis,i,-1)) {
            ok=true;
        }
    }
}

if(ok){
    int check = ev;
    cout<<ev<<" ";
    while(true){
        if(parent[ev]==sv) break;
        cout<<parent[ev]<<" ";
        ev=parent[ev];
    }
    cout<<check<<"\n";
}

else cout<<"IMPOSSIBLE"<<"\n";

return 0;
}