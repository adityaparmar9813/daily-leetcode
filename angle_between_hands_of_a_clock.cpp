class Solution {
   public:
	double angleClock(int hour, int minutes) {
		double hourAngle = (hour * 30) % 360 + (minutes / 2.0);
		double minuteAngle = minutes * 6;
		double angle = max(hourAngle - minuteAngle, minuteAngle - hourAngle);
		return min(angle, 360 - angle);
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)