class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> solver;
        int ans;
        if(tokens.size() == 1) return stoi(tokens[0]);

        for(auto token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = solver.top();
                solver.pop();
                int a = solver.top();
                solver.pop();

                if(token == "+") ans = a+b;
                else if(token == "-") ans = a-b;
                else if(token == "*") ans = a*b;
                else ans = a/b;

                solver.push(ans);
            }
            else solver.push(stoi(token));
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
