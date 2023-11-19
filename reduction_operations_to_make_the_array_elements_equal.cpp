class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        priority_queue<int> pq;
        int operations = 0,count = 0;
        
        for(auto& num: nums) pq.push(num);
        
        while(true) {
            int num = pq.top();
            pq.pop();

            if(pq.empty()) break;
            count++;
            if(num != pq.top()) operations += count;
        }
        return operations;
    }
};