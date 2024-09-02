//before writing recursive code draw a choice diagram
//2 choices here
//lets say bag weight is W
//w1 has how many choices?
//if(w1>w)dont take
//if(w1<=w)take or not take

//int f(all attributes){
//  base condition
//  choice diagram ka code
//}
//

//how to think of base condition?
//think of smallest valid input 
//if(n==0)return 0;  no elements profit 0
//if(w==0)return 0;  no weights  profit 0

#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&wt,vector<int>&val,int n,int w){
    if(n==0 || w==0)return 0;

    if(wt[n]<=w){
        return max(val[n]+f(wt,val,n-1,w-wt[n]),f(wt,val,n-1,w));
    }else if(wt[n]>w){
        return f(wt,val,n-1,w);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        //f(wt,val,n-1,w);
    }
}