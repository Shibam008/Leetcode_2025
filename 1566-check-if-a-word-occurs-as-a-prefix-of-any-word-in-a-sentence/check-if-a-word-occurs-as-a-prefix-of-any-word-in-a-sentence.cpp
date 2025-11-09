class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int idx = 1;
        while (ss >> word) {
            if (word.rfind(searchWord, 0) == 0)
                return idx; // rfind(...,0) -> prefix
            idx++;
        }
        return -1;
    }
};