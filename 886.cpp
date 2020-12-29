class Solution {
public:
  bool dfs(vector<vector<int>>& graph,vector<int>&vis,int node,int color){
    if(vis[node]!=0){
      if(vis[node]==color)return true;
      return false;
    }
    
    vis[node]=color;
    for(auto nbr:graph[node]){
      int new_color=(color==1)?2:1;
      if(!dfs(graph,vis,nbr,new_color))return false;
    }
    return true;
    
  }
  
    bool isBipartite(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<int>vis(n,0);
      
      for(int i=0;i<n;i++){
        if(vis[i]==0 && (!dfs(graph,vis,i,1))){
          return false;
        }
      }
      
      return true;
        
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      
      vector<vector<int>>graph(N);
      for(int i=0;i<dislikes.size();i++){
        graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
        graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        
      }
      
      return isBipartite(graph);
      
      
        
    }
};