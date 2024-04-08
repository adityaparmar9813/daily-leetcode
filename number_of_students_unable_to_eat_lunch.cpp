class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        
        for(int student: students) {
            q.push(student);
        }

        for(int sandwich: sandwiches) {
            int size = q.size();

            while(q.front() != sandwich && size--) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
            
            if(q.front() == sandwich) {
                q.pop();
            } else {
                return q.size();
            }
        }
        return 0;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
