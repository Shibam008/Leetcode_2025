class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fst = 0, sec = 0, len = 0;
        vector<bool> count(256, 0);
        while(sec < s.size())
        {
            while(count[s[sec]]) 
            {
                count[s[fst]] = 0;
                fst++;
            }
            count[s[sec]] = 1;
            len = max(len, sec - fst + 1);
            sec++;
        }
        return len;
    }
};