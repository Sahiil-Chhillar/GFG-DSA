class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int,int> mp;//sum -> idx
        int maxLength = 0;
        int currSum = 0;
        
        for(int i = 0; i< arr.size();i++){
            currSum += arr[i];
            if(currSum == 0) maxLength = i+1;
            if(mp.find(currSum) != mp.end()) maxLength = (maxLength < i - mp[currSum]) ? i-mp[currSum]: maxLength;
            else mp[currSum] = i;
        }
        return maxLength;
    }
};
// class Solution {
//   public:
//     int maxLength(vector<int>& arr) {
//         int maxLength = 0;
//         for(int i = 0 ; i< arr.size();i++){
//             int currSum = 0;
//             for(int j = i;j < arr.size();j++){
//                 currSum += arr[j];
//                 if(currSum == 0) maxLength = (j-i+1 > maxLength) ? j-i+1 : maxLength;
//             }
//         }
//         return maxLength;
//     }
// };