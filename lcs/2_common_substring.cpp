#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s1,string s2,int &ma){
    if(i==0||j==0)return 0;
    if(s1[i-1]==s2[j-1]){
        int l=1+f(i-1,j-1,s1,s2,ma);
        ma=max(ma,l);
        return l;
    }
    else{
        f(i-1,j,s1,s2,ma);
        f(i,j-1,s1,s2,ma);
        return 0;
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
        int ma=0;
        f(n1,n2,s1,s2,ma);
        cout<<ma;
    }
}