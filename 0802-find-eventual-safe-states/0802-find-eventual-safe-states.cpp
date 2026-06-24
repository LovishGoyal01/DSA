class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,vector<int>& vis,vector<int>& pathvis,vector<int>& check){
       vis[i]=1;
       pathvis[i]=1;
       check[i]=0;
       
       for(int it : graph[i]){
          if(!vis[it]){
             if(dfs(graph,it,vis,pathvis,check)) return true;
          }
          else if(pathvis[it]) return true;
       }
       check[i]=1;
       pathvis[i]=0;
       return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,i,vis,pathvis,check);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};