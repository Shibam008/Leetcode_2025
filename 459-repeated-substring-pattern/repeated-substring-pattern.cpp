class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }

        int last = lps[n - 1];
        return (last > 0 && n % (n - last) == 0);
    }
};