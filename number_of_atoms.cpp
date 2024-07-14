class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});

        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                map<string, int> innerMap = st.top(); 
                st.pop();
                int start = ++i;

                while(i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplier = (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                for (auto& element: innerMap) {
                    string atom = element.first;
                    int count = element.second * multiplier;

                    st.top()[atom] += count;
                }
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string atom = formula.substr(start, i - start);

                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                st.top()[atom] += count;
            }
        }

        map<string, int> res = st.top();
        string ans;

        for (const auto& element: res) {
            ans += element.first;
            if (element.second > 1) {
                ans += to_string(element.second);
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
