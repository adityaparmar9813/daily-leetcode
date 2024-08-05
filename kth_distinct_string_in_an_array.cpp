class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> mp;

    for (string str : arr) {
      mp[str]++;
    }

    for (string str : arr) {
      if (mp[str] == 1) {
        k--;
      }
      if (!k) {
        return str;
      }
    }
    return "";
  }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
