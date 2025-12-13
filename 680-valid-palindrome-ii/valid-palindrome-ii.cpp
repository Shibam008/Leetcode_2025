class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // try skipping one character
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }
        return true;
    }
};