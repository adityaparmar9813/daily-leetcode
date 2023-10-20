class NestedIterator {
public:
    stack<NestedInteger> st;

    NestedIterator(vector<NestedInteger>& nestedList) {
        int n = nestedList.size();
        for(int i=n-1; i >= 0; i--) st.push(nestedList[i]);
    }

    int next() {
        int result = st.top().getInteger();
        st.pop();

        return result;
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger top = st.top();
            if (top.isInteger()) return true;

            st.pop();
            vector<NestedInteger>& nestedList = top.getList();
            
            int n = nestedList.size();
            for (int i=n-1; i >= 0; i--) st.push(nestedList[i]);
        }
        return false;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)