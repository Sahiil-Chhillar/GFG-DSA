class Solution {
  public:
    int f(int idx ,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>& dp){
        if(idx == wt.size()) return 0;
        if(dp[idx][W] != -1) return dp[idx][W];
        int p = (wt[idx] <= W) ? val[idx] + f(idx+1,W - wt[idx],val,wt,dp) : 0;
        int np = f(idx+1,W,val,wt,dp);
        return dp[idx][W] = max(p,np);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(wt.size()+1,vector<int>(W+1,-1));
        return f(0,W,val,wt,dp);
    }
};