class DisjointSets{
    vector<int> parent,size;
    public:

    DisjointSets(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }

    int findUpar(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUpar(parent[u]);
    }

    void unionBysize(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSets ds(n);

        for(int i=0;i<n;i++){  
          for(int j=0;j<n;j++){
            if(isConnected[i][j]) ds.unionBysize(i,j);
          } 
        }
    
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i) cnt++;
        }  
        return cnt;
    }
};