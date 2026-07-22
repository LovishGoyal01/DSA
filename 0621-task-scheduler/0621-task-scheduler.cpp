class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        map<int,int>mp;
        for(char ch:tasks){
          mp[ch-'A']++;
        }
         for(auto it:mp){
            pq.push(it.second);
         }
         
         int time=0;
         while(!pq.empty()){
            vector<int> arr;
            for(int i=0;i<=n;i++){
              if(pq.empty()) break;  
              arr.push_back(pq.top()-1);
              pq.pop();
            }
            for(int i=0;i<arr.size();i++){
                if(arr[i]>0) pq.push(arr[i]);
            }
            if(!pq.empty()) time+=n+1;
            else time +=arr.size();
         }
      return time;
    } 
};