class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        // First and last occurrence of every character
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        // Find all valid intervals
        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;

            int l = i;
            int r = last[s[i] - 'a'];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                if (first[s[j] - 'a'] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[s[j] - 'a']);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // Greedily choose non-overlapping intervals
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a.second == b.second)
                     return a.first > b.first;
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto &it : intervals) {
            if (it.first > end) {
                ans.push_back(s.substr(it.first, it.second - it.first + 1));
                end = it.second;
            }
        }

        return ans;
    }
};