class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return {left + 1, right + 1}; // 1-indexed output
            } else if (currentSum < target) {
                left++;  // Need a larger sum
            } else {
                right--; // Need a smaller sum
            }
        }

        return {};
        
    }
};