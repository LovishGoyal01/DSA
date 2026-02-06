class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int i){
        visited[i]=1;
        int size = visited.size();
        for(int j=0;j<size;j++){
            if(!visited[j] && i!=j && isConnected[i][j]==1){
                dfs(isConnected,visited,j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int>visited(size);
        int count=0;
        for(int i=0;i<size;i++){
           if(!visited[i]){
            count++;
            dfs(isConnected,visited,i);
           }
        }
        return count;  
    }
};