class Solution {
public:
    void helper(vector<int>&arr, vector<vector<int>>&ans, int idx) {
        if(idx == arr.size()) {
            ans.push_back(arr);
            return;
        }

        vector<bool> trackNumber(21, 0);
        for(int i = idx; i < arr.size(); i++) 
        {
            if(trackNumber[arr[i] + 10] == 0) 
            {
                trackNumber[arr[i] + 10] = 1;
                swap(arr[i], arr[idx]);
                helper(arr, ans, idx+1);
                swap(arr[i], arr[idx]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};