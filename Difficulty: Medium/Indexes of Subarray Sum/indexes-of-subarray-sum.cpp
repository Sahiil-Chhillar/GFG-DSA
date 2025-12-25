class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int totalSum = 0;
        int startIndex = 0;
        int endIndex = 0;
        
        while(endIndex < arr.size()){
            totalSum += arr[endIndex];
            while (totalSum > target && startIndex < endIndex){
                totalSum -= arr[startIndex];
                startIndex++;
            }
            if(totalSum == target) return {startIndex+1,endIndex+1};
            endIndex++;
        }
        return {-1};
    }
};