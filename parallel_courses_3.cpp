class Solution {
public:
    vector<vector<int>> adjacencyList;
    vector<int> inDegrees;
    int calculateMinimumTime(int n, vector<int>& time) {
        vector<int> waitTime(n + 1) ;
        queue<int> q;
        int maxWaitTime = 0;

        for (int i = 1; i <= n; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
                waitTime[i] = time[i - 1] ;
                maxWaitTime = max(maxWaitTime, waitTime[i]);
            }
        }

        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();

            for (auto childCourse : adjacencyList[currentCourse]) {
                inDegrees[childCourse]--;
                waitTime[childCourse] = max(time[childCourse - 1] + waitTime[currentCourse], waitTime[childCourse]);
                maxWaitTime = max(maxWaitTime, waitTime[childCourse]);

                if (inDegrees[childCourse] == 0) 
                    q.push(childCourse);
            }
        }

        return maxWaitTime;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adjacencyList.resize(n + 1);
        inDegrees.resize(n + 1);

        for (int i = 0; i < relations.size(); i++) {
            auto prerequisitePair = relations[i];
            adjacencyList[prerequisitePair[0]].push_back(prerequisitePair[1]);
            inDegrees[prerequisitePair[1]]++;
        }

        return calculateMinimumTime(n, time);
    }
};

// Time Complexity : O(N + E)
// Space Complexity : O(N + E)