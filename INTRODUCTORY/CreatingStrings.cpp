// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

void permute(string s , set <string> &ans , vector <int> &vis , string &temp) {
    if(temp.size() == s.size()) {
        ans.insert(temp);
        return;
    }

    for(int i = 0 ; i < s.size() ; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            temp.push_back(s[i]);
            permute(s,ans,vis,temp);
            vis[i] = 0;
            temp.pop_back();
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string s;
cin>>s;

int n = s.size();
set <string> ans;
vector <int> vis(n+1,0);
string temp;
permute(s,ans,vis,temp);

cout <<ans.size()<<"\n";
for(auto it : ans) cout<<it<<"\n";
return 0;
}