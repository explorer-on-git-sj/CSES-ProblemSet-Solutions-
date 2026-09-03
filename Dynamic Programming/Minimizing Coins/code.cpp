#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<long long>


int main(){
    //minimizn coins
    //      amount x :  55
    //      coins ->  1,5 ,7   --->55
    //   7 ko lo 7 times 5 ->1 1->1    9


    ll n,x; cin>>n>>x;
    vi a(n);

    for(auto &x: a) cin>>x;

    //1-> left to right
    //states pe ek relation
    vi dp(x+1);

    dp[0]=0;
    //dp[i]  is no of coins needed to amount to i

    //  55
    //  1 5 7
    //  1      ---->   54    (1+dp[54])
    //  5      ---->   50    (1+dp[50])
   //  7       ---->   48    (1+dp(48))
   // 100 

    for(int i=1; i<=x; i++){
      ll cur = INT_MAX;
      for(auto deno: a){
        if(i-deno<0)  continue;
        cur=min(cur,1+dp[i-deno]);
      }
      dp[i]=cur;
    }
   if(dp[x]!=INT_MAX)
    cout<<dp[x]<<endl;
    else cout<<-1<<endl;
  return 0;
}
