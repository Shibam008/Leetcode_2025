class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, mid;

        int ans = nums[0]; // if array is not rotated

        while(s <= e) {
            mid = s + (e-s)/2;
            // left side sorted array
            if(nums[0] <= nums[mid]) { 
                s = mid + 1;
            } 
            // right side sorted array
            else { 
                ans = nums[mid];
                e = mid - 1;
            }
        }
        return ans;
    }
};