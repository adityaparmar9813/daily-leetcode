class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;

        int i = 0, j = people.size()-1;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
            }
            ans++;
            j--;
        }
        return ans;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)
