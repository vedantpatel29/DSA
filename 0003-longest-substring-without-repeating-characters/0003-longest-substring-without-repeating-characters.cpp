class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];

            // 1. Check if character exists in map
            // 2. Ensure its last seen index is INSIDE the current active window (>= left)
            if (lastSeen.find(current) != lastSeen.end() && lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }

            // Update/insert the last seen index for current character
            lastSeen[current] = right;

            // Recalculate max window length
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};