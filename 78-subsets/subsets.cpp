class Solution {
public:
    void helper(vector<int>arr, int idx, int n, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(idx == n) {
            ans.push_back(temp);
            return;
        }

        // exclude
        helper(arr, idx+1, n, temp, ans);
        // include
        temp.push_back(arr[idx]);
        helper(arr, idx+1, n, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums, 0, nums.size(), temp, ans);
        return ans;
    }
};