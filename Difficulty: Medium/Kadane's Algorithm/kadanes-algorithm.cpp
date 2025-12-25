class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(auto& num : arr){
            currSum += num;
            maxSum = (currSum > maxSum) ? currSum : maxSum;
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};