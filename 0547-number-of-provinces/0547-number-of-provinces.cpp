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
        vector<pair<int,int>>edges;
        // for(int i=0;i<n;i++){
        //  // int v=1;  
        //   for(auto it :isConnected[i]){
        //     int u=i+1;
        //     if(it==1) edges.push_back({u,v});
        //     v++;
        //   } 
        // }
         for(int i=0;i<n;i++){  
          for(int j=0;j<n;j++){
            if(isConnected[i][j]) ds.unionBysize(i,j);
          } 
        }
       // sort(edges.begin(),edges.end());
        // for(auto it:edges){
        //     int u = it.first;
        //     int v = it.second;
        //     if(ds.findUpar(u)!=ds.findUpar(v)){
        //         ds.unionBysize(u,v);
        //     }
        // }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i) cnt++;
        }  
        return cnt;
    }
};