class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7;
        stack<int> mono;
        vector<int> left(arr.size()), right(arr.size());
        long long ans = 0;
        
        for(int i=0; i < arr.size(); i++) {
            int num = arr[i];
            
            while(true) {
                if(mono.empty()) {
                    left[i] = -1;
                    mono.push(i);
                    break;
                }
                if(arr[mono.top()] < num) {
                    left[i] = mono.top();
                    mono.push(i);
                    break;
                }
                mono.pop();
            }
        }

        while(!mono.empty()) mono.pop();

        for(int i=arr.size()-1; i >= 0; i--) {
            int num = arr[i];

            while(true) {
                if(mono.empty()) {
                    right[i] = arr.size();
                    mono.push(i);
                    break;
                }
                if(arr[mono.top()] <= num) {
                    right[i] = mono.top();
                    mono.push(i);
                    break;
                }
                mono.pop();
            }
        }

        for(int i=0; i < arr.size(); i++) {
            long long l = i - left[i];
            long long r = right[i] - i;
            ans = (ans + (l*r*arr[i]) % MOD) % MOD;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
