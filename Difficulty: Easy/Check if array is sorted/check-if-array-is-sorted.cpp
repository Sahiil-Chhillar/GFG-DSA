class Solution {
  public:
    bool f(int idx , vector<int>& arr){
        if(idx == 0 || idx == 1) return true;
        return arr[idx] >= arr[idx-1] && f(idx-1,arr);
    }
    bool isSorted(vector<int>& arr) {
        return f(arr.size()-1,arr);
    }
};