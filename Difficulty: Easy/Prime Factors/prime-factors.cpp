class Solution {
  public:
    vector<int> primeFac(int n) {
        int x = n;
        vector<int> isPF(x+1,false);
        for(int i = 2 ; i*i <= x;i++){
            if(x%i == 0){
                isPF[i] = true;
                while(x%i == 0) x/=i;
            }
        }
        if(x>1) isPF[x] = true;
        
        vector<int> ans;
        for(int i = 0 ; i <= n;i++) if(isPF[i]) ans.push_back(i);
        
        return ans;
    }
};