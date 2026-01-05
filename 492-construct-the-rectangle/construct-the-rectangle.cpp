class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>ans(2,0);
        for(int width = sqrt(area); width >= 1; width--) {
            int height = area / width;
            if(area == height * width) {
                ans[0] = height;
                ans[1] = width;
                break;
            }
        }
        return ans;
    }
};