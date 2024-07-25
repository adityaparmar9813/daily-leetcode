class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp(r - l + 1);

        int i = l, j = m+1, k = 0;

        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= m) {
            temp[k++] = nums[i++];
        }
        while (j <= r) {
            temp[k++] = nums[j++];
        }

        for (int num: temp) {
            nums[l++] = num;
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = l + (r-l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
