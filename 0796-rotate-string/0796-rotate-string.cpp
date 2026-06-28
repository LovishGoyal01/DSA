class Solution {
public:
    bool rotateString(string s, string t) {
          return (s+s).find(t) !=-1;
    }
};