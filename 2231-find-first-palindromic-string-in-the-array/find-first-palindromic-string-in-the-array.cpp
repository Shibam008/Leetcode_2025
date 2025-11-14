class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end) {
            if(s[start++] != s[end--]) 
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word: words) {
            if(isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};