// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
char grid[1001][1001];
vector <vector<int>> dist(1001,vector<int>(1001,1e9));

bool bfs(pair<int,int> src,pair<int,int> drc,int n,int m,vector <vector<pair<int,int>>> &parent){
    priority_queue <pair<int,pair<int,int>>,vector <pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    dist[src.first][src.second]=0;
    pq.push({0,{src.first,src.second}});

    vector <pair<int,int>> rc = {{-1,0},{0,1},{1,0},{0,-1}};

    while(!pq.empty()){
        int d = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        for(int i=0;i<4;i++){
            int nrow = row + rc[i].first;
            int ncol = col + rc[i].second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] != '#'){
                if(d+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = d+1;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                    parent[nrow][ncol] = {row,col};
                }
            }
        }
    }

    if(dist[drc.first][drc.second] != 1e9) return true;
    else return false;

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;
pair<int,int> src,drc; 
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
        if(grid[i][j]=='A') src={i,j};
        if(grid[i][j]=='B') drc={i,j};
    }
}
vector <vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));

if(bfs(src,drc,n,m,parent)) {
    cout<<"YES"<<"\n";
    cout<<dist[drc.first][drc.second]<<"\n";
    //int r = drc.first,c = drc.second;
    int str = drc.first,stc=drc.second;
    while(str!=src.first && stc!= src.second){
        cout<<parent[str][stc].first<<" "<<parent[str][stc].second<<"\n";
        str = parent[str][stc].first;
        stc = parent[str][stc].second;
    }
}

else cout<<"NO"<<"\n";
return 0;
}