class Solution {
public:
    int solve(vector<string>& arr, int index, vector<int>& mp) {
        if(index == arr.size()) return 0;

        bool flag = false;
        int take, notTake = solve(arr, index+1, mp);

        for(auto ch: arr[index]) {
            if(mp[ch-'a'] == 1) flag = true;
            mp[ch-'a']++;
        }
        if(flag) take = INT_MIN;
        else take = arr[index].size() + solve(arr, index+1, mp);

        for(auto ch: arr[index]) {
            mp[ch-'a']--;
        }
        
        return max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        vector<int> mp(26, 0);
        return solve(arr, 0, mp);
    }
};

// Time Complexity : O(2^n)
// Space Complexity : O(2^n)
