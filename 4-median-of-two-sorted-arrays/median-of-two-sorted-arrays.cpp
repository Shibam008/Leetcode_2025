class Solution {
public:
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;

        int i=0, j=0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n) {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < m) {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }

    double findMedian(vector<int> arr) {
        int n = arr.size();
        if(n % 2 == 1) {
            return arr[n/2]; // middle elem
        }
        else {
            return (arr[n/2 - 1] + arr[n/2]) / 2.0;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = merge(nums1, nums2);
        return findMedian(mergedArray);
    }
};