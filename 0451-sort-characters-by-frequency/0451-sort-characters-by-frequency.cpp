class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> hash(256, {0, 0});
        for(char ch:s) hash[ch] = {hash[ch].first+1,ch};

        sort(hash.begin(),hash.end());
        string res = "";
        for(auto it:hash){
            res = string(it.first,it.second) + res;
        }
        return res;
    }
};