class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xr = 0;
        for(auto& num : arr) xr^= num;
        
        int setBit = xr & -xr;
        
        int num1 = 0, num2 = 0;
        for(auto& num : arr){
            if(num & setBit) num1^=num;
            else num2^=num;
        }
        
        return num1>num2 ? vector<int>{num2,num1} : vector<int>{num1,num2};
    }
};