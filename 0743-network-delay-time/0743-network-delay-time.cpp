class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vis(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        for(auto it : times ){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>>q;
        q.push({0,k});
        vis[k]=0;
        vis[0]=0;
        while(!q.empty()){
            int node = q.top().second;
            int time = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int dist = it.second;
                if(dist+time<vis[adjnode]){
                    vis[adjnode] = dist+time;
                    q.push({dist+time,adjnode});
                }
            }
        }
        int maxt=0;
        for(int i=1;i<n+1;i++){
          if(vis[i]!=INT_MAX) maxt=max(maxt,vis[i]);
          else return -1;
        }
        return maxt;
    }
};