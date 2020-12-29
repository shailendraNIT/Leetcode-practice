class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
      int mod=pow(10,9)+7;
      
      vector<vector<long>>dp(L+1,vector<long>(N+1,0));
      
      dp[0][0]=1;
      
      for(int i=1;i<=L;i++){
        for(int j=1;j<=N;j++){
          dp[i][j]=(dp[i-1][j-1]*(N-j+1)) %mod; //nya song chlaya hai 
          
          //purana song chalane ke treeke isme add krunga
          //matlb ki jo j-1 songs chl chuke h unhi me se koi hai
          if(j<=K){//matlb abhi k songs nhi chle to repeat nhi kr skte
            dp[i][j]+=dp[i-1][j]*0;
          }
          else{
            dp[i][j]=(dp[i][j]+(dp[i-1][j]*(j-K))%mod) %mod;
          }
        }
      }
      
      return dp[L][N];
        
    }
};