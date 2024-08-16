class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int largest = INT_MIN, secondLargest = INT_MIN;
        int smallest = INT_MAX, secondSmallest = INT_MAX;
        int lIndex = -1, slIndex = -1, sIndex = -1, ssIndex = -1;

        for (int i = 0; i < arrays.size(); i++) {
            int first = arrays[i].front();
            int last = arrays[i].back();

            if (first < smallest) {
                secondSmallest = smallest;
                ssIndex = sIndex;
                smallest = first;
                sIndex = i;
            } else if (first < secondSmallest) {
                secondSmallest = first;
                ssIndex = i;
            }

            if (last > largest) {
                secondLargest = largest;
                slIndex = lIndex;
                largest = last;
                lIndex = i;
            } else if (last > secondLargest) {
                secondLargest = last;
                slIndex = i;
            }
        }

        if (lIndex != sIndex) {
            return largest - smallest;
        }

        return max(largest - secondSmallest, secondLargest - smallest);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
