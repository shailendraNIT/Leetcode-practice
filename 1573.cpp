#define ll long long
class Solution {
public:
    int numWays(string s) {
      ll mod=pow(10,9)+7;
      ll n=s.size();
      
      ll ones=0;
      for(ll i=0;i<n;i++){
        if(s[i]=='1')ones++;
      }
      if(ones%3!=0)return 0;
      
      if(ones==0)return ((n-1)*(n-2)/2)%mod;
      ll sum=ones/3;
      
      ll preways=0,suffways=0,prefix=0,suffix=0;
      
      ll j=0;
      while(prefix<=sum){
        prefix+=s[j]-'0';
        
        if(prefix==sum)preways++;
        j++;
      }
      j=n-1;
      while(suffix<=sum){
        suffix+=s[j]-'0';
        
        if(suffix==sum) suffways++;
        j--;
      }
      
      return ((preways)%mod * (suffways)%mod)%mod;
        
    }
};