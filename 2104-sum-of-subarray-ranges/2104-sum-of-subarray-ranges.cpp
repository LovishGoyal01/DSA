class Solution {
public:
    // ----------- MINIMUM ------------
    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    // ----------- MAXIMUM ------------
    vector<int> NGE(vector<int>& arr){
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> PGE(vector<int>& arr){
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse = NSE(nums);
        vector<int> pse = PSE(nums);

        vector<int> nge = NGE(nums);
        vector<int> pge = PGE(nums);

        long long minSum = 0, maxSum = 0;

        for(int i = 0; i < n; i++){
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            minSum += leftMin * rightMin * nums[i];

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxSum += leftMax * rightMax * nums[i];
        }

        return maxSum - minSum;
    }
};