class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        string s = nums[0];
        int maxi = s.size();

        for(int i = 1; i < nums.size(); i++) {
            int count = 0;

            while(count < maxi && count < nums[i].size() && s[count] == nums[i][count]) {
                count++;
            }

            maxi = count; // update every time
        }

        return s.substr(0, maxi);
    }
};