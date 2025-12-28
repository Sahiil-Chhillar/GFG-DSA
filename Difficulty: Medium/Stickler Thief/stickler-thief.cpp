class Solution {
  public:
    int f(int idx,vector<int>& arr,vector<int>& dp){
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        int p = arr[idx] + f(idx+2,arr,dp);
        int np = f(idx+1,arr,dp);
        
        return dp[idx] = max(p,np);
    }
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size()+1,-1);
        return f(0,arr,dp);
    }
};