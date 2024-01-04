//https://www.codechef.com/problems/SNSOCIAL

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Intuituin -> put all the source in queue and apply bfs
int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int a[n][m];
	    int mx = -1e9;
	    queue <pair<int,int>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>a[i][j];
	            mx=max(mx,a[i][j]);
	        }
	    }
	    
	    vector <vector <int>> vis(n,vector<int>(m,0));
	    vector <vector <int>> level(n,vector<int>(m,0));
	    vector <pair<int,int>> move = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mx==a[i][j]) {
	                q.push({i,j});
	                vis[i][j]=1;
	                level[i][j]=0;
	            }
	        }
	    }
	    int ans=0;
	    
	    while(!q.empty()){
	        int row = q.front().first;
	        int col = q.front().second;
	        q.pop();
	        
	        for(int i=0;i<8;i++){
	            int nrow = row + move[i].first;
	            int ncol = col + move[i].second;
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
	                q.push({nrow,ncol});
	                vis[nrow][ncol]=1;
	                level[nrow][ncol] = level[row][col]+1;
	                ans=max(ans,level[nrow][ncol]);
	            }
	        }
	        
	    }
	    
	    cout<<ans<<"\n";
	}
	return 0;
}
