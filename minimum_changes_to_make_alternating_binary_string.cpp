class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
        char tracker = '0';

        for(auto ch: s) {
            if(ch == tracker) ans2++;
            else ans1++;

            tracker == '0' ? tracker = '1' : tracker = '0';
        }
        return min(ans1, ans2);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)