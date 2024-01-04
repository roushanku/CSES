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

vector <vector<int>> adj;
while(m-->0){
    int a,b,d;
    cin>>a>>b>>d;

    adj.push_back({a-1,b-1,d});
}

vector <int> relaxent(n,-1);
vector <long long> dist(n,0);
int x=-1;
for(int i=0;i<n;i++){
    for(auto it:adj){
        int u = it[0];
        int v = it[1];
        int d = it[2];

        if(dist[v]>dist[u]+d){
            dist[v] = d + dist[u];
            x=v;
            relaxent[v]=u;
        }
    }
}

if(x==-1) cout<<"NO"<<"\n";

else{
    for(int i=1;i<=n;i++) x = relaxent[x];
    vector <int> ans;
    for(int v=x ;; v=relaxent[v]){
        ans.push_back(v);
        if(v==x && ans.size()>1) break;
    }

    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it+1<<" ";
    cout<<"\n";
}
return 0;
}