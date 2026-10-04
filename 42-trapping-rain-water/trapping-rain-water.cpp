class Solution {
public:
    int trap(vector<int>& height) {

        int water = 0;
        int left = 0;
        int right = height.size() - 1;

        int leftMax = height[left];
        int rightMax = height[right];

        while( left < right ) 
        {
            if (leftMax < rightMax)
            {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
};