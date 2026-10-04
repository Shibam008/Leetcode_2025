class Solution {
public:
    int trap(vector<int>& height) {

        // first have to findout the largest tower.
        int maxHeightIdx = 0;
        for(int i=0; i<height.size(); i++) {
            if(height[i] > height[maxHeightIdx]) {
                maxHeightIdx = i;
            }
        }

        // solving left part - 
        int leftMax = 0;
        int water = 0;

        for (int i=0; i<maxHeightIdx; i++) 
        {
            if (leftMax > height[i])
            {
                water += leftMax - height[i];
            }
            else {
                leftMax = height[i];
            }
        }

        int rightMax = 0;

        for (int i=height.size()-1; i > maxHeightIdx; i--) 
        {
            if (rightMax > height[i])
            {
                water += rightMax - height[i];
            }
            else {
                rightMax = height[i];
            }
        }
        return water;
        
    }
};