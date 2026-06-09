class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     priority_queue<int>pq;   
     map<char,int>mpp;
     int time=0;
     for(int i=0;i<tasks.size();i++){
        mpp[tasks[i]]++;
     } 
     for(auto it : mpp){
       pq.push(it.second);
     }  
     while(!pq.empty()){
        vector<int>temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                temp.push_back(f);
            }
        }
        for(int f:temp){
            if(f>0) pq.push(f);
        }
        
        if(pq.empty()) time+=temp.size();
        else time+=n+1;
     }
     return time;
    }
};