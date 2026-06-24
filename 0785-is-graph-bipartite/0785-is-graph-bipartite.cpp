class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>vis(n,-1);
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            if(vis[i]!=-1) continue;
            q.push({i,0});
            vis[i]=0;
            while(!q.empty()){
                int node = q.front().first;
                int setNo = q.front().second;
                q.pop();
                for(int j:graph[node]){
                  if(vis[j]==-1){
                    vis[j]=!setNo;
                    q.push({j,!setNo});
                  }else if(vis[j]==setNo) return false;
                }
            }
        }
        return true;
    }
};