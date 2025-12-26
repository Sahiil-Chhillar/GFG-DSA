class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dept) {
        
        // Wrong Solution 
        // vector<pair<int,int>> arr;
        // for(int i=0 ;i< arri.size();i++) arr.push_back({arri[i],dep[i]});
        // sort(arr.begin(),arr.end());
        
        // int cnt = 1;
        // int minDepTime = arr[0].second;
        // for(int i = 1; i < arr.size();i++){
        //     if(minDepTime > arr[i].first){
        //         cnt++;
        //         minDepTime = min(minDepTime,arr[i].second);
        //     }
        //     else minDepTime = arr[i].second;
        // }
        
        // return cnt;
        
        sort(arr.begin(),arr.end());
        sort(dept.begin(),dept.end());
        
        int maxPlatforms = 0;
        int occupiedPlatforms = 0;
        int i = 0, j = 0;
        while(i < arr.size()){
            if(arr[i] <= dept[j]){
                occupiedPlatforms++;
                i++;
            }else{
                occupiedPlatforms--;
                j++;
            }
            
            maxPlatforms = max(maxPlatforms,occupiedPlatforms);
        }
        return maxPlatforms;
    }
};
