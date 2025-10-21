class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string ans;
        int carry = 0;
        int sum = 0;
        int i = num1.size()-1, j = num2.size()-1;

        while(i >= 0 || j >= 0 || carry) 
        {
            int x = (i >= 0) ? num1[i]-'0' : 0;
            int y = (j >= 0) ? num2[j]-'0' : 0;
            
            int sum = x + y + carry;
            char digit = (sum % 10) + '0';
            carry = sum / 10;
            ans += digit;
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};