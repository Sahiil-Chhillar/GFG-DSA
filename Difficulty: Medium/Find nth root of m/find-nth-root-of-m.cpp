class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m == 0) return m;
        if(n == 0) return -1;
        int st = 1;
        int end = m/n;
        
        while(st <= end){
            int mid = st + (end - st)/2;
            
            long long sq = 1;
            for(int i = 1 ; i<= n ;i++){
                sq *= mid;
            }
            
            if(sq == m) return mid;
            else if(sq < m) st = mid +1;
            else end = mid -1;
        }
        return -1;
    }
};