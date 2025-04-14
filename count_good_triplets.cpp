class Solution {
   public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int ans = 0;
		vector<int> interval(1001, 0);

		for (int j = 0; j < arr.size(); j++) {
			for (int k = j + 1; k < arr.size(); k++) {
				if (abs(arr[j] - arr[k]) <= b) {
					int left = max(0, max(arr[j] - a, arr[k] - c));
					int right = min(1000, min(arr[j] + a, arr[k] + c));

					if (left <= right) {
						if (left == 0)
							ans += interval[right];
						else
							ans += interval[right] - interval[left - 1];
					}
				}
			}

			for (int ind = arr[j]; ind <= 1000; ind++) {
				interval[ind]++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(1)