// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool isvalid(vector <int> &ans) {
    int n = ans.size();
    for(int i = 1 ; i < n ; i++) {
        if(abs(ans[i]-ans[i-1]) == 1) return false;
    }

    return true;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// int n;
// cin>>n;

// vector <int> temp;
// for(int i = 1 ; i <= n ; i++) temp.push_back(i);

// int id;
// if(n&1) id = (n/2) + 1;
// else id = (n/2);

// vector <int> ans;

// for(int i = 0 ; i < (n/2) ; i++) {
//     ans.push_back(temp[i]);
//     ans.push_back(temp[i+id]);
// }

// if(n&1) ans.push_back(id);

// if(n==1) {
//     cout <<1<<"\n";
// }

// else if(n==4) {
//     cout<<2<<" "<<4<<" "<<1<<" "<<3<<"\n";
// }
// else if(isvalid(ans)) {
//     for(auto it:ans) cout<<it<<" ";
//     cout<<"\n";
// }

// else cout<<"NO SOLUTION"<<"\n";
char ch = 'a';
cout<<ch-'a'<<"\n";
return 0;
}