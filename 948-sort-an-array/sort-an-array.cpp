class Solution {
public:
    void merge(vector<int>& arr, int mid, int st, int end) {
        vector<int> temp(end - st + 1);
        int left = st;
        int right = mid + 1;
        int idx = 0;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp[idx] = arr[left];
                idx++;
                left++;
            } else {
                temp[idx] = arr[right];
                idx++;
                right++;
            }
        }

        while (left <= mid) {
            temp[idx] = arr[left];
            idx++;
            left++;
        }

        while (right <= end) {
            temp[idx] = arr[right];
            idx++;
            right++;
        }

        idx = 0;
        while (st <= end) {
            arr[st] = temp[idx];
            st++;
            idx++;
        }
    }

    void mergeSort(vector<int>& arr, int st, int end) {
        if (st == end) {
            return;
        }
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, mid, st, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};