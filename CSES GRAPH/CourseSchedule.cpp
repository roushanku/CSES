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

int n,m;
cin>>n>>m;

vector <int> adj[n];
while(m-->0){
    int u,v;
    cin>>u>>v;

    adj[u-1].push_back(v-1);
}

vector <int> InDegree(n,0);

for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        InDegree[it]++;
    }
}

queue <int> q;
for(int i=0;i<n;i++){
    if(InDegree[i]==0) q.push(i);
}

vector <int> ans;
while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for(auto it:adj[node]){
        if(InDegree[it]>0) InDegree[it]--;
        if(InDegree[it]==0) q.push(it);
    }
}

if(ans.size()<n) cout<<"IMPOSSIBLE"<<"\n";
else{
    for(auto it:ans) cout<<it+1<<" ";
    cout<<"\n";
}

return 0;
}