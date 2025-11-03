class Solution {
public:
    void lpsFinder(vector<int>&lps, string s) {
        int pre = 0, suf = 1;
        while(suf < s.size()) {
            if(s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++; suf++;
            }
            else {
                if(pre == 0) {
                    suf++;
                }
                else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int kmp_match(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsFinder(lps, needle);
        int first = 0, second = 0;
        while(first < haystack.size() && second < needle.size()) {
            if(haystack[first] == needle[second]) {
                first++; second++;
            }
            else {
                if(second == 0) {
                    first++;
                }
                else {
                    second = lps[second - 1];
                }
            }
        }
        if(second == needle.size()) {
            return 1;
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int cnt = 1;
        while(temp.size() < b.size()) {
            temp += a;
            cnt++;
        }
        // check for first match
        if(kmp_match(temp, b)) {
            return cnt;
        }
        // if first match fails, check for once adding that string againg to temp
        if(kmp_match(temp + a, b)) {
            return cnt + 1;
        }
        return -1;
    }
};