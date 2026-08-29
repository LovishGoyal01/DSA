class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && asteroids[i]<0 && st.top()>0 && abs(asteroids[i])>st.top()) st.pop();
            if(st.empty() || st.top()<0 ||asteroids[i]>0 ) st.push(asteroids[i]);
            else if(abs(asteroids[i]) == st.top()) st.pop();
        }
        int n = st.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};