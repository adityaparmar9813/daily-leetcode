class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;

        for(int i=0; i < s.size(); i++) {
            string curr = "";
            for(int j=i; j < s.size(); j++) {
                curr += s[j];
                int num = stoi(curr);

                if(low <= num && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)
