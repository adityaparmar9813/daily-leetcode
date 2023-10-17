class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);

        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                if(parents[leftChild[i]] == -1) parents[leftChild[i]] = i;
                else return false;
            }
            if(rightChild[i] != -1){
                if(parents[rightChild[i]] == -1) parents[rightChild[i]] = i;
                else return false;
            }
        }

        int root = -1;
        for(int i = 0;i < n; i++) {
            if(parents[i] == -1){
                if(root == -1) root = i;
                else return false;
            }
        }
        if(root == -1) return false;

        unordered_set<int> visited;
        queue<int> bfs;

        bfs.push(root);
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();

            if(visited.find(node) != visited.end()) return false;
            visited.insert(node);
            
            if(rightChild[node] != -1) bfs.push(rightChild[node]);
            if(leftChild[node] != -1) bfs.push(leftChild[node]);
        }

        return visited.size() == n;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)