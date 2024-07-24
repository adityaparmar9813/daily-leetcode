class Solution {
public:
    static bool sortHelper(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vals(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int updated_num = 0;
            int place_value = 1;

            do {
                int r = n % 10;
                n = n / 10;

                r = mapping[r];
                updated_num += place_value * r;
                place_value *= 10;
            } while (n != 0);
            vals[i] = {nums[i], updated_num};
        }
        
        sort(vals.begin(), vals.end(), sortHelper);

        for (int i = 0; i < vals.size(); i++) {
            nums[i] = vals[i].first;
        }
        return nums;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
