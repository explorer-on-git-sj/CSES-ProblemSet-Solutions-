#include<bits/stdc++.h>
using namespace std;


int main(){

  int n; cin>>n;

  long long m = 1e9+7;

  // sum n create krna using dices
//   36    6 6 6 6  6 6    4 4 4 4 4 4 4 4 4
//count possible ways

// 3---> 1+1+1   2+1   1+2   3


//    15
//    0   --->1    dp[0]=1
//    1   + (14)    === dp[14]
//    2   + (13)    === dp[13]
//    3   + (12)    ''
//    4   + (11)
//    5   + (10)
//    6   + (9)
// dp[15]=dp[14] + dp[13] + dp[12] + dp[11] + dp[10] + dp[9]
//dp[2] = dp[1]+dp[0]+
// dp[n] = dp[n-1] + dp[n-2] dp{n-3} +dp[n-4] +dp[n-5] +dp[n-6]

  if(n==0)  {
   cout<<0<<endl;
   return 0;
  }
  if(n==1)  {
   cout<<1<<endl;
   return 0;
  }
  if(n==2)  {
   cout<<2<<endl;
   return 0;
  }
  if(n==3)  {
   cout<<4<<endl;
   return 0;
  }
  if(n==4)  {
   cout<<8<<endl;
   return 0;
  }
  if(n==5)  {
   cout<<16<<endl;
   return 0;
  }
  if(n==6)  {
   cout<<32<<endl;
   return 0;
  }

  vector<long long> dp(n+1);
  dp[0]=1;

   dp[1]=1;
  
  dp[2]= dp[1]+dp[0];
  
  dp[3]= dp[2]+dp[1]+dp[0];  //4
  dp[4]=dp[1]+dp[2]+dp[3]+dp[0];
  dp[5]=dp[1]+dp[2]+dp[3]+dp[4]+dp[0];


  //for n>=6
 
  for(int i=6;i<=n;i++){
   dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6];
   dp[i]%=m;
  }



cout<<dp[n]<<endl;
   return 0;
}
