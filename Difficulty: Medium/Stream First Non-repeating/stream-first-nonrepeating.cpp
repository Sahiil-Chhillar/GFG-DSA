class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans = "";
        unordered_map<char,int> prefixFreq;
        queue<char> q;
        for(auto& ch : s){
            prefixFreq[ch]++;
            q.push(ch);
            
            while(!q.empty() && prefixFreq[q.front()] > 1) q.pop();
            
            if(q.empty()) ans+="#";
            else ans += q.front();
        }
        return ans;
    }
};