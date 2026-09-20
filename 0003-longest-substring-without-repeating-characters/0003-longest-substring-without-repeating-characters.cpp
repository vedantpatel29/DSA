class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(256,-1);

        int left = 0; int right = 0;
        int maxln = 0;

        for(int i=right ; right< s.size();right++){
            char current = s[right];

            if(lastseen[current]>=left){
                left = lastseen[current]+1;
            }

            lastseen[current]=right;

            maxln = max(maxln,right-left+1);
        }
        return maxln;
        
    }
};