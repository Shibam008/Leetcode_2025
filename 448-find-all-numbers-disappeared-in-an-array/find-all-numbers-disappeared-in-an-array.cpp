class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // Mark visited numbers by making the index negative
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // Convert value to index
            if (nums[index] > 0)
                nums[index] = -nums[index];  // Mark as visited
        }

        // Missing numbers are those whose indexes are still positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};