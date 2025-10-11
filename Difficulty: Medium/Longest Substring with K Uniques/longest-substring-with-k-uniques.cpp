class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> freq;
        int leftPos = 0;
        int maxLen = -1;
        
        for(int i = 0 ; i< s.size();i++){
            freq[s[i]]++;
            while(freq.size() > k){
                freq[s[leftPos]]--;
                if(freq[s[leftPos]] == 0) freq.erase(s[leftPos]);
                leftPos++;
            }
            if(freq.size() == k) maxLen = max(maxLen, i - leftPos +1);
        }
        
        return maxLen;
    }
};