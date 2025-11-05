class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int idx = 0;
        while (true) {
            char curr_ch = 0;
            for (auto word : strs) {
                // index out of bound
                if (idx >= word.size()) {
                    curr_ch = 0;
                    break;
                }

                // matching prefix chars
                if (curr_ch == 0) {
                    curr_ch = word[idx];
                } else if (word[idx] != curr_ch) {
                    curr_ch = 0;
                    break;
                }
            }
            if (curr_ch == 0) {
                break;
            }
            ans.push_back(curr_ch);
            idx++;
        }
        return ans;
    }
};