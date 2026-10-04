class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        int slow = 0;
        int fast = slow + 1;

        while(fast < n) 
        {
            if (nums[slow] == 0 && nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);
                slow++;
                fast++;
            }
            else if (nums[slow] == 0 && nums[fast] == 0) {
                fast++;
            }
            else {
                slow++;
                fast++;
            }
        }
    }
};