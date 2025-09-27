class Solution {
  public: 
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> res;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq;
        
        // pq -> {arr[i][j], {i,j}};
        for(int i = 0;i < arr.size();i++){
            if(!arr[i].empty()) pq.push({arr[i][0],{i,0}});
        }
        
        while(!pq.empty()){
            int val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            res.push_back(val);
            if(j+1 < arr[i].size()) pq.push({arr[i][j+1],{i,j+1}});
        }
        
        return res;
    }
};