class Solution {
public:
    
    static bool comp(vector<int>&v1,vector<int>&v2){
     return v1[1]<v2[1];
    }  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int s=intervals[0][0];
        int e=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<e) cnt++;
            else e=intervals[i][1];
        }
        return cnt;
    }
};