class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V); 
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
         for(auto it : graph[i]){
           adj[it].push_back(i);
            indegree[i]++;
         }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
           if(indegree[i]==0) q.push(i);
          
        }
        vector<int>topo;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            topo.push_back(i);
            for(auto it : adj[i]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
     sort(topo.begin(),topo.end());  
    return topo;      
    }
};