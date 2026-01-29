class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i< arr.size();i++){
            pq.push({arr[i],i});
            
            while(pq.size() > k && pq.top().second <= i-k) pq.pop();
            
            if(pq.size() >= k) ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};