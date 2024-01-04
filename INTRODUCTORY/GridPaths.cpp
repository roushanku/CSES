// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
vector <pair<int,int>> v = {{-1,0} , {0,1} , {1,0} , {0,-1}};
int dfs(int i , int r , int c , vector < vector <int>> &vis , string s) {
    if(r == 7 && c == 0) return 1;

    if(i >= 48) return 0;
    int ans = 0;
    if(s[i] == '?') {
        for(int j = 0 ; j < 4 ; j++) {
            int nrow = r + v[j].first;
            int ncol = c + v[j].second;
            if(nrow >= 0 && ncol >= 0 && nrow < 8 && ncol < 8 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                ans += dfs(i,nrow,ncol,vis,s);
                vis[nrow][ncol] = 0;
            }
        }
    }
    else {
        if(s[i] == 'L' && c > 0) {
            vis[r][c-1] = 1;
            ans += dfs(i+1,r,c-1,vis,s);
            vis[r][c-1] = 0;
        }

        if(s[i] == 'R' && c < 7) {
            vis[r][c+1] = 1;
            ans += dfs(i+1,r,c+1,vis,s);
            vis[r][c+1] = 0;
        }

        if(s[i] == 'U' && r > 0) {
            vis[r-1][c] = 1;
            ans += dfs(i+1,r-1,c,vis,s);
            vis[r-1][c] = 0;
        }

        if(s[i] == 'D' && c < 7) {
            vis[r][c+1] = 1;
            ans += dfs(i+1,r,c+1,vis,s);
            vis[r][c+1] = 0;
        }
    }

    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

vector < vector <int>> vis(8,vector<int>(8,0));
string s;
cin>>s;

int ans = dfs(0,0,0,vis,s);
cout<<ans<<"\n";
return 0;
}