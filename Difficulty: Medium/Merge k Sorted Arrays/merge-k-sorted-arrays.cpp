class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> res;
        for(auto& a : arr) res.insert(res.end(),a.begin(),a.end());
        sort(res.begin(),res.end());
        return res;
    }
};