class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        // code here
        int cnt = 0;
        // for(int i = 0; i < nums.size();i++){
        //     int Xor = 0;
        //     for(int j = i ; j < nums.size();j++){
        //         Xor ^= nums[j];
        //         if(Xor == k) cnt++;
        //     }
        // }
        
        unordered_map<int,int> prefixXOR;
        prefixXOR[0] = 1;
        int xr = 0;
        for(auto& num : nums){
            xr ^= num;
            if(prefixXOR.find(xr^k) != prefixXOR.end()) cnt += prefixXOR[xr^k];
            prefixXOR[xr]++;
        }
        return cnt;
    }
};