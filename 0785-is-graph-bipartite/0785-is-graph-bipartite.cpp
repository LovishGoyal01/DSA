class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();
        vector<int>visited(m,-1);
        queue<pair<int,int>>q;
        
    for(int j=0;j<m;j++){
       if(visited[j]!=-1) continue;
       visited[j]=0;
        q.push({j,0});
        while(!q.empty()){
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            for(auto i:graph[node]){
                    if(visited[i]==-1){ 
                        visited[i]= color==0?1:0;
                        q.push({i,visited[i]});
                    }else if((visited[i]==1 && color==1) || (visited[i]==0 && color==0)){
                        return false;
                    }  
            }
        }
    }    
        return true;
    }
};