class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;

        string prefix = "";
        for(char c : searchWord) {
            prefix += c;

            // Lower bound gives the first position where prefix can be inserted
            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> curr;

            // Check next 3 products from the lower bound
            for(int i = 0; i < 3 && it + i != products.end(); i++) {
                string &word = *(it + i);
                if(word.substr(0, prefix.size()) == prefix)
                    curr.push_back(word);
                else
                    break;
            }

            result.push_back(curr);
        }

        return result;
    }
};