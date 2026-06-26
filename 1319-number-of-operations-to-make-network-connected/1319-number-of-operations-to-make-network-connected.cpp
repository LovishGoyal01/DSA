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
    int makeConnected(int n, vector<vector<int>>connections) {
        int c = connections.size();
        if(c<n-1) return -1;
        DisjointSets ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            ds.unionBysize(u,v);
        }
        int cnt=0;  
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i) cnt++;
        }
         return cnt-1;
    }
};