class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int candidate = 0, count = 0;

        for(int i=0; i<size; i++) {
            if(count == 0) {
                candidate = nums[i];
                count = 1;
            }
            else {
                if(nums[i] == candidate) {
                    count ++;
                }
                else {
                    count--;
                }
            }
        }

        return candidate;
    }
};