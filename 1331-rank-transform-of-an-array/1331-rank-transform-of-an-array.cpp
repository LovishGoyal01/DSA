class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

       for(int i=0;i<arr.size();i++){
         pq.push({arr[i],i});
       }  
       int prev;
       int i=0;
       while(!pq.empty()){
         auto it = pq.top();  pq.pop();
         if(i==0 || prev!=it.first)  i++;
         arr[it.second]=i;
         prev=it.first;
          
       }
       return arr;
    }
};