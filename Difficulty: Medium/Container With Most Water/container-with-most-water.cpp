class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int st = 0;
        int end = arr.size()-1;
        int maxW = 0;
        
        while(st < end){
            maxW = max(maxW,min(arr[st],arr[end])*(end-st));
            if(arr[st] < arr[end]) st++;
            else end--;
        }
        
        return maxW;
    }
};