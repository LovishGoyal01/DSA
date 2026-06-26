class DisjointSet{
  public:
  vector<int> parent,size;

    DisjointSet(int n){
      parent.resize(n);
      size.resize(n);
      for(int i=0;i<n;i++){
        parent[i]=i;  size[i]=1;
      } 
    }
    void unionBySize(int u,int v){
      int ulp_u = findUParent(u);
      int ulp_v = findUParent(v);
      if(ulp_u==ulp_v) return;
      if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
      }else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];   
      }
    }
    int findUParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUParent(parent[u]);
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[4] = {-1,0,1,0};
                int dc[4] = {0,1,0,-1};
                for(int z=0;z<4;z++){
                    int nr = i+dr[z];
                    int nc = j+dc[z];
                    if(nr>=0 && nr<n && nc>=0 && nc<n &&  grid[nr][nc]){
                      int node = i*n + j;
                      int adjnode = nr*n + nc;
                      ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        // step 2
        int mx=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[4] = {-1,0,1,0};
                int dc[4] = {0,1,0,-1};
                set<int>components;
                for(int z=0;z<4;z++){
                    int nr = row+dr[z];
                    int nc = col+dc[z];
                    if(nr>=0 && nr<n && nc>=0 && nc<n &&  grid[nr][nc]){
                        components.insert(ds.findUParent(nr*n+ nc));
                    }
                }

                // claculating size;
                int s =0 ;
                for(int it : components) s+=ds.size[it];
                mx = max(mx,s+1);
            }
        }
        for(int i=0;i<n*n;i++){
          if(ds.findUParent(i)==i)
         mx = max(mx, ds.size[i]);
        }
       return mx;
    }
};