class Solution {
public:
    int num(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0, idx = 0;

        while(idx < s.size()-1) {
            if(num(s[idx]) < num(s[idx + 1])) {
                sum -= num(s[idx]);
            }
            else {
                sum += num(s[idx]);
            }
            idx++;
        }
        // for last roman numeral
        sum += num(s[s.size() - 1]);
        return sum;
    }
};