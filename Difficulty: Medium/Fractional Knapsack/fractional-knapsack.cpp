class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double,pair<int,int>>> items; // val/wt , wt , val;
        for(int i = 0 ; i< val.size();i++) items.push_back({ (double)val[i]/wt[i] , {wt[i],val[i]} });
        sort(items.begin(),items.end(), greater<pair<double,pair<int,int>>>());
        
        double maxVal = 0;
        for(int i = 0 ; i < items.size();i++){
            if(items[i].second.first <= capacity){
                maxVal += items[i].second.second;
                capacity -= items[i].second.first;
            }
            else if(capacity > 0) {
                maxVal += (double) capacity * items[i].second.second / items[i].second.first;
                break;
            }
        }
        
        return maxVal;
    }
};
