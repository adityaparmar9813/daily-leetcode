
class Solution {
public:
  static bool sortHelper(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
  }

  int minimumPushes(string word) {
    vector<pair<int, int>> mp(26);

    for (int i = 0; i < 26; i++) {
      mp[i] = {i, 0};
    }

    for (char ch : word) {
      mp[ch - 'a'].second++;
    }

    sort(mp.begin(), mp.end(), sortHelper);

    vector<int> clicks(26);
    int curr = 1, index = 0, ans = 0;

    for (int i = 0; i < 26 && mp[i].second != 0; i++) {
      clicks[mp[i].first] = curr;

      if (++index % 8 == 0) {
        curr++;
      }
    }

    for (char ch : word) {
      ans += clicks[ch - 'a'];
    }

    return ans;
  }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
