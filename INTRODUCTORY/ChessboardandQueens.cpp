// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
bool isvalid(int row , int col , vector <string> &s) {
    int r = row , c = col;
    while(r >= 0 && c >= 0) {
        if(s[r][c] == 'Q') return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    while(c >= 0) {
        if(s[r][c] == 'Q') return false;
        c--;
    }

    c = col;

    while(c >= 0 && r < 8) {
        if(s[r][c] == 'Q') return false;
        r++;
        c--;
    }

    return true;
}
void solve(int col , vector <vector<string>>& ans , vector <string> &s) {
    if(col == 8) {
        ans.push_back(s);
        return;
    }

    for(int row = 0 ; row < 8 ; row++){
        if(s[row][col] != '*' && isvalid(row,col,s)) {
            s[row][col] = 'Q';
            solve(col+1,ans,s);
            s[row][col] = '.';
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

char grid[8][8];
vector <string> s(8);
string a(8,'.');
for(int i = 0 ; i < 8 ; i++) s[i] = a;

for(int i = 0 ; i < 8 ; i++) {
    for(int j = 0 ; j < 8 ; j++) {
        cin>>grid[i][j];
        s[i][j] = grid[i][j];
    }
}
vector <vector<string>> ans;
solve(0,ans,s);

cout<<ans.size()<<"\n";
return 0;
}