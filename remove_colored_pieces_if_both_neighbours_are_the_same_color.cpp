class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceCount = 0, bobCount = 0;
        int aCount = 0, bCount = 0;

        for(int i=0; i<colors.size(); i++) {
            if(colors[i] == 'A') {
                // In case we encounter an A after a set of B's
                if(bCount != 0) {
                    // Number of moves Bob can make when he gets bCount B's in a row
                    bobCount += max(bCount - 2, 0);
                    bCount = 0;
                }
                aCount++;
            }
            else {
                // In case we encounter a B after a set of A's
                if(aCount != 0) {
                    // Number of moves Alice can make when he gets aCount A's in a row
                    aliceCount += max(aCount - 2, 0);
                    aCount = 0;
                }
                bCount++;
            }
        }

        // In case there were unprocessed letters at the end of the string
        if(aCount != 0) aliceCount += max(aCount - 2, 0);
        if(bCount != 0) bobCount += max(bCount - 2, 0);
        return aliceCount > bobCount;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)