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

vector <pair<long long,long long>> adj[n];
for(int i=1;i<=m;i++){
    long long a,b;
    long long c;
    cin>>a>>b>>c;

    adj[a-1].push_back({b-1,c}); //{node,dist}
}

priority_queue <pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq; //{d,node}
vector <long long> dist(n,1e17);

pq.push({0,0});
dist[0]=0;

while(!pq.empty()){
    long long node = pq.top().second;
    long long d = pq.top().first;
    pq.pop();
    if(dist[node]<d) continue; // if u will not include this line then u will get TLE

    for(auto it:adj[node]){
        long long adjnode = it.first;
        long long distance = it.second;

        if(d+distance < dist[adjnode]){
            dist[adjnode] = d+distance;
            pq.push({dist[adjnode],adjnode});
        }
    }
}

for(int i=0;i<n;i++) cout<<dist[i]<<" ";
cout<<"\n";
return 0;
}