class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                  calc(isConnected,vis,i);
                  cnt++;
            }
        }
        return cnt;
    }

    void calc(vector<vector<int>>& isConnected,vector<bool>& vis,int node){
       int n=isConnected.size();
        vis[node]=true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int root=q.front(); q.pop();
            for(int i=0;i<n;i++){
                if(!vis[i] && isConnected[root][i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }
};