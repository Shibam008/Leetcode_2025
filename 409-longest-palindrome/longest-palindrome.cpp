class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 1)
            return 1;
        vector<int> capital(26, 0), small(26, 0);
        int len = 0, flagOdd = 0;

        for (int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a')
                small[s[i] - 'a']++;
            else
                capital[s[i] - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if(small[i] % 2 == 0) {
                len += small[i];
            } 
            else {
                len += small[i] - 1;
                flagOdd = 1;
            }
            if(capital[i] % 2 == 0) {
                len += capital[i];
            } 
            else {
                len += capital[i] - 1;
                flagOdd = 1;
            }
        }
        return len + flagOdd;
    }
};