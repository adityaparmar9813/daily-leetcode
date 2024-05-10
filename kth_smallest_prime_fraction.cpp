class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0.0, r = 1.0, mid;

        while (l < r) {
            mid = (l + r) / 2;
            int count = 0;
            int j = 1;

            for (int i = 0; i < n; i++) {
                while (j < n && arr[i] > mid*arr[j]) {
                    j++;                
                }
                count += (n-j);
            }
            if (count > k)  {
                r = mid;
            }
            else if(count < k) {
                l = mid;
            }
            else {
                break;
            }   
        }
        
        vector<int> res;
        double fraction = 0.0;
        
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i]*1.0/mid);

            if (it != arr.end()) {
                int j = it - arr.begin();
                if (arr[i]*1.0/arr[j] > fraction) {
                    fraction = arr[i]*1.0/arr[j];
                    res = {arr[i], arr[j]};
                }
            }
        }
        return res;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)  
