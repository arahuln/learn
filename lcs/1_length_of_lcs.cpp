#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s1,string s2){
    if(i==0||j==0)return 0;
    if(s1[i-1]==s2[j-1])return 1+f(i-1,j-1,s1,s2);
    else{
        return max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n1=s1.size(),n2=s2.size();
        cout<<f(n1,n2,s1,s2);
    }
}