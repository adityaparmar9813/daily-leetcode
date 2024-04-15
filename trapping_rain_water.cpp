class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> st;

        for(int i=0; i < height.size(); i++) {
            while(!st.empty() && height[st.back()] < height[i]){
                int m = st.back();
                st.pop_back();

                if (st.empty()){
                    break;
                }

                int l = st.back();
                int diff = min(height[i]-height[m], height[l]-height[m]);
                int w = i-l-1;
                
                ans += diff*w;
            }
            st.push_back(i);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
