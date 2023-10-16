class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr(rowIndex+1, 0);
        curr[0] = 1;

        for(int i=0; i < rowIndex; i++) {
            for(int j=i+1; j >= 1; j--) curr[j] += curr[j-1];
        }
        return curr;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)