class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        int curr = 0, prev = -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> temp;
        
        for (int card: hand) {
            pq.push(card);
        }

        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();

            if(prev == -1 || top - prev == 1) {
                prev = top;
                curr++;
            } else {
                temp.push_back(top);
            }

            if(curr == groupSize) {
                curr = 0;
                prev = -1;

                for(int card: temp) {
                    pq.push(card);
                }
                temp = {};
            }
        }   
        return curr ? false : true;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)
