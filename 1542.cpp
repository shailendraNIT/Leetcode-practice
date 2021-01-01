class Solution {
public:
  
  //vortubrac solution 
  //youtube video  ->>> https://www.youtube.com/watch?v=rZPCi5JySY4&ab_channel=RoshanSrivastava
  
    int longestAwesome(string s) {
      int n=s.size();
      int ans=0,mask=0;
      unordered_map<int,int>map;  //storing the mask value ans its index
      
      map[0]=-1;
      
      for(int i=0;i<n;i++){
        mask^=1<<(s[i]-'0');
        
        
        //if mask found again then the substr in b/w has all even counts
        if(map.find(mask)!=map.end()){
          ans=max(ans,i-map[mask]);
        }
        else map[mask]=i;
        
        //checking for condition when one odd count number can be there
        for(int pos=0;pos<=9;pos++){
          int new_mask=mask^(1<<pos);
          if(map.find(new_mask)!=map.end()){
            ans=max(ans,i-map[new_mask]);
          }
        }
      }
      return ans;
    }
};