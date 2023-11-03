class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr = 1;

        for(int i=0; i < target.size(); i++) {
            while(i < target.size() && curr != target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                curr++;
            }
            curr++;
            ans.push_back("Push");
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)