class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), idx = 0;
        while(idx < n) {
            char last = s[n-1];
            for(int i=n-2; i>=0; i--) {
                s[i+1] = s[i];
            }
            s[0] = last;

            if(s == goal) {
                return true;
            }
            idx++;
        }
        return false;
    }
};