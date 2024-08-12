class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    for (int num : nums) {
      pq.push(num);

      if (pq.size() > k) {
        pq.pop();
      }
    }
    this->k = k;
  }

  int add(int val) {
    pq.push(val);

    if (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};

// Time Complexity : O(n * log(k))
// Space Complexity : O(k)
