class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size();
        vector<vector<double>>  worker(n, vector<double>(2));

        for(int i= 0; i < n; i++) {
            worker[i] = {(double)wage[i] / quality[i], (double)quality[i]}; 
        }
        sort(worker.begin(), worker.end());

        int quality_sum = 0;
        priority_queue<int> pq;

        for(int i = 0; i < k; i++) {
            quality_sum += worker[i][1];
            pq.push(worker[i][1]);
        }

        double cost = quality_sum * worker[k-1][0];

        for(int i = k; i < n; i++) {
            pq.push(worker[i][1]);
            quality_sum += worker[i][1]-pq.top();
            pq.pop();

            cost = min(cost, quality_sum * worker[i][0]);
        }
        return cost;
    }
};

// Time Complexity : O(n*log(n)
// Space Complexity : O(n)
