// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
vector <vector<int>> vis(1001,vector<int>(1001,0));
char grid[1001][1001];
void bfs(int sr,int sc,int n,int m){
    queue <pair<int,int>> q;
    q.push({sr,sc});

    vector <pair<int,int>> rc = {{-1,0},{0,1},{1,0},{0,-1}};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + rc[i].first;
            int ncol = col + rc[i].second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='.'){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
}

int ans=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && grid[i][j]=='.'){
            bfs(i,j,n,m);
            ans++;
        }
    }
}

cout<<ans<<"\n";
return 0;
}