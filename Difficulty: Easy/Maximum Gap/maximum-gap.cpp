class Solution {
  public:
    int maxDiff(vector<int>& arr) {
        if(arr.size() <= 1) return 0;
        sort(arr.begin(),arr.end());
        int maxDiff = -1e9;
        
        for(int i = 0 ; i + 1 < arr.size();i++) maxDiff= max(maxDiff, abs(arr[i+1] - arr[i]));
        return maxDiff;
    }
};