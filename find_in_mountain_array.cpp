class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 1, high = n - 2;
        int peakIndex = -1;

        // Find peak index
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) low = mid + 1;
            else high = mid;
        }

        peakIndex = low;
        low = 0;
        high = peakIndex;

        // Search before peak
        while (low != high) {
            int mid = low + (high-low)/2;
            if (mountainArr.get(mid) < target) low = mid+1;
            else high = mid;
        }
        if (mountainArr.get(low) == target) return low;

        low = peakIndex+1;
        high = n-1;

        // Search after peak
        while (low != high) {
            int mid = low + (high-low)/2;
            if (mountainArr.get(mid) > target) low = mid + 1;
            else high = mid;
        }

        if (mountainArr.get(low) == target) return low;
        return -1;
    }
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)