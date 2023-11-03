class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ptr = 0;

        for(int i=1; i <= target[target.size()-1]; i++) {
            if(i == target[ptr]) {
                ans.push_back("Push");
                ptr++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)