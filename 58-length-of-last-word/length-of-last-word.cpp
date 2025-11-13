class Solution {
public:
    // string trim(string& s) {
    //     int start = s.find_first_not_of(' ');
    //     int end = s.find_last_not_of(' ');
    //     if (start == string::npos)
    //         return "";
    //     return s.substr(start, end - start + 1);
    // }

    int lengthOfLastWord(string s) {
        // s = trim(s);
        // int cnt = 0;
        // for (int i = s.size() - 1; i >= 0; i--) {
        //     if (s[i] == ' ')
        //         return cnt;
        //     cnt++;
        // }
        // return -1;

        int i = s.size() - 1;
        int cnt = 0;

        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0 && s[i] != ' ') {
            cnt++;
            i--;
        }
        return cnt;
    }
};