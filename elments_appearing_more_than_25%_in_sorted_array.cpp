class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int continuous = 1;

        for(int i=1; i < arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                continuous++;
                if(continuous > arr.size()/4) return arr[i];
            }
            else continuous = 1;
        }
        return arr[0];
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)