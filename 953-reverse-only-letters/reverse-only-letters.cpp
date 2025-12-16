class Solution {
public:
    string reverseOnlyLetters(string str) {
        int left = 0, right = str.size()-1;
        while(left < right) {
            if( isalpha(str[left]) && isalpha(str[right]) ) {
                swap(str[left++], str[right--]);
            }
            else if(!isalpha(str[left])) {
                left++;
            }
            else if(!isalpha(str[right])) {
                right--;
            }
        }
        return str;
    }
};