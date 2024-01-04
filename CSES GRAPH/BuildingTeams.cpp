// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
bool bfs(vector <int> adj[],vector<int> &ans,int i){
    queue <int> q;
    ans[i]=0;
    q.push(i);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            //not visited
            if(ans[it]==-1){
                ans[it]=!ans[node];
                q.push(it);
            }

            //visited and are in same grp -> not possible
            else if(ans[it]==ans[node]) return false;
        }
    }
    return true;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

//Bi-partite graph ques type
int n,m;
cin>>n>>m;

vector <int> adj[n];
while(m-->0){
    int u,v;
    cin>>u>>v;

    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

vector <int> ans(n,-1);
bool ok = true;
for(int i=0;i<n;i++){
    if(ans[i]==-1){
        if(!bfs(adj,ans,i)){
            ok=false;
            break;
        }
    }
}

if(ok){
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";
}

else cout<<"IMPOSSIBLE"<<"\n";

return 0;
}