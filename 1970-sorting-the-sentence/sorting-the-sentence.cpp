class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int cnt = 0;

        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                cnt++;
            }
            else {
                temp += s[i];
            }
        }
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        cnt++;

        for(int i = 1; i <= cnt; i++) {
            temp += ans[i] + " ";
        }
        temp.pop_back();
        return temp;
    }
};