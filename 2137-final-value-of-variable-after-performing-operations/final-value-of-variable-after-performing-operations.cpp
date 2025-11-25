class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto operation: operations) {
            if(operation == "X++" || operation == "++X") {
                ans += 1;
            } else {
                ans -= 1;
            }
        }
        return ans;
    }
};