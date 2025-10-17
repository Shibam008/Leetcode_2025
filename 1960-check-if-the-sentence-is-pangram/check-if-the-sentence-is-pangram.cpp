class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabets(26, 0);
        for(int i = 0; i < sentence.size(); i++) {
            alphabets[sentence[i] - 'a'] = 1;
        }
        for(int el: alphabets) {
            if(el == 0) {
                return false;
            }
        }
        return true;
    }
};