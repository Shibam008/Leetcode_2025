class Solution {
public:
    void helper(vector<int>&arr, vector<int>&temp, vector<vector<int>>&ans,int idx, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(target < 0) 
        {
            return;
        }

        for(int i = idx; i < arr.size(); i++) 
        {
            temp.push_back(arr[i]);
            helper(arr, temp, ans, i, target - arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(candidates, temp, ans, 0, target);
        return ans;
    }
};