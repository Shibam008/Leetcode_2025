class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26, 0);

        // for(int i = 0; i < s.size(); i++) {
        //     count[s[i] - 'a']++;
        // }
        // for(int i = 0; i < t.size(); i++) {
        //     count[t[i] - 'a']--;
        // }

        // for(int i=0; i<26; i++) {
        //     if(count[i] != 0) {
        //         return i + 'a';
        //     }
        // }
        // return '0';

        char ans = 0;
        for(char ch: s) ans ^= ch;
        for(char ch: t) ans ^= ch;
        return ans;
    }
};