class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> result, remaining;
        
        for (int num : arr1) {
            mp[num]++;
        }

        for (int num : arr2) {
            while (mp[num]-- > 0) {
                result.push_back(num);
            }
            mp.erase(num);
        }

        for (auto& pair : mp) {
            while (pair.second-- > 0) {
                remaining.push_back(pair.first);
            }
        }

        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};


// Time Complexity : O(n*log(n))
// Space Complexity : O(n)
