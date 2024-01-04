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
int t;
cin>>t;
while(t--){
    int a,b;
    cin>>a>>b;

    int c = max(a,b);
    int d = min(a,b);
    long long sum = a+b;
    int op = (c/2);
    if(c%2 != 0) op++;

    if(sum % 3 != 0) cout<<"NO"<<"\n";

    else{
        if(d < op) cout<<"NO"<<"\n";

        else{
            cout<<"YES"<<"\n";
        }
    }      
}
return 0;
}