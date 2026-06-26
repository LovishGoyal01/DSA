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
    int removeStones(vector<vector<int>>& stones) {
      int mxR=0;
      int mxC=0;
      // Finding out max row and col
      for(auto it:stones){
        mxR = max(mxR,it[0]);
        mxC = max(mxC,it[1]); 
      }

      DisjointSets ds(mxR + mxC + 1);
      unordered_map<int,int>stoneNodes;
      for(auto it : stones){
            int u = it[0];
            int v = it[1] + mxR + 1;
            ds.unionBysize(u,v);
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
      } 
      int cnt=0;
      for(auto it : stoneNodes){
        if(ds.findUpar(it.first)==it.first) cnt++;
      } 
      return stones.size()-cnt;
    }
};