class Solution {
public:
    int expectedSolution(vector<int> heights) {
        int n = heights.size();

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], heights[i - 1]);
        }

        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], heights[i + 1]);
        }

        int totalUnitOfWater = 0;
        for (int i = 0; i < n; i++) {
            int miniHeight = min(maxLeft[i], maxRight[i]);
            int capacity = miniHeight - heights[i];
            if (capacity >= 0) {
                totalUnitOfWater += capacity;
            }
        }
        return totalUnitOfWater;
    }

    int optimalSolution(vector<int> heights) {
        int n = heights.size();
        int leftMax = 0, rightMax = 0, water = 0;

        //* find largest building and it's position
        int maxHeight = 0, maxHeightIdx = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxHeightIdx = i;
            }
        }

        //* solve left part
        for (int i = 0; i < maxHeightIdx; i++) {
            if (leftMax > heights[i]) {
                water += leftMax - heights[i];
            } else {
                leftMax = heights[i];
            }
        }

        //* solve right part
        for (int i = n - 1; i > maxHeightIdx; i--) {
            if (rightMax > heights[i]) {
                water += rightMax - heights[i];
            } else {
                rightMax = heights[i];
            }
        }

        return water;
    }
    int trap(vector<int>& heights) { 
        return optimalSolution(heights); 
    }
};