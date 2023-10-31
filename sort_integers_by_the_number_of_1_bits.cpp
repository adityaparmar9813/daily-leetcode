class Solution {
public:
    static int oneCount(int num) {
        int count = 0;

        while(num != 0) {
            if(num%2 == 1) count++;
            num = num/2;
        }
        return count;
    }
    static bool oneSort(int num1, int num2) {
        return oneCount(num1) == oneCount(num2) ? num1 < num2 : oneCount(num1) < oneCount(num2);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), oneSort);
        return arr;
    }
};

// Time Complexity : O(nlogn)
// Space Complexity : O(1)