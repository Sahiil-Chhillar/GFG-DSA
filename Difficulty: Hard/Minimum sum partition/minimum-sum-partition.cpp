class Solution {
  public:
    int f(int n,vector<int>& arr,int totalSum,int currSum,vector<vector<int>>& dp){
        if(n == 0) {
            return abs(totalSum - currSum);
        }
        
        if(dp[n][totalSum] != -1) return dp[n][totalSum];
        
        int pick = f(n-1,arr,totalSum - arr[n-1],currSum + arr[n-1],dp);
        int notPick = f(n-1,arr,totalSum , currSum,dp);
        
        return dp[n][totalSum] = min(pick,notPick);
    }
    int minDifference(vector<int>& arr) {
        int totalSum = 0;
        for(auto& num : arr) totalSum += num;
        int n = arr.size();
        int currSum = 0;
        
        vector<vector<int>> dp(n+1,vector<int>(totalSum + 1,-1));
        f(n,arr,totalSum,currSum,dp);
        return dp[n][totalSum];
    }
};
