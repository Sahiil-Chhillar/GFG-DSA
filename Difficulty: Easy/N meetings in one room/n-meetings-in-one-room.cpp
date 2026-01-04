class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> meetings;
        
        for(int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        sort(meetings.begin(), meetings.end());
        
        int count = 1;
        int lastEnd = meetings[0].first;
        
        for(int i = 1; i < meetings.size(); i++) {
            if(meetings[i].second > lastEnd) {
                count++;
                lastEnd = meetings[i].first;
            }
        }
        
        
        return count;
    }
};