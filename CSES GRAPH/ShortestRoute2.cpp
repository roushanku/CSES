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
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m,q;
cin>>n>>m>>q;

vector <vector<int>> dist(n+1,vector<int>(n+1,1e15));

for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j) dist[i][j]=0;
    }
}

for(int i=1;i<=m;i++){
    int u,v,d;
    cin>>u>>v>>d;
    dist[u][v]=min(dist[u][v],d);
    dist[v][u]=min(dist[u][v],d);
}

for(int via=1;via<=n;via++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
        }
    }
}

for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;

    if(dist[a][b]==1e15) cout<<-1<<"\n";
    else cout<<dist[a][b]<<"\n";
}

// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cout<<dist[i][j]<<" ";
//     }
//     cout<<"\n";
// }

return 0;
}