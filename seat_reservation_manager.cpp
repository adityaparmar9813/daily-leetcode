class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat = 1;
    
    SeatManager(int n) {
        for(int i=1; i<=n; i++) pq.push(i);
    }
    
    int reserve() {
        int reserved = pq.top();
        pq.pop();
        return reserved;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

// Time Complexity : O(n) 
// Space Complexity : O(n)