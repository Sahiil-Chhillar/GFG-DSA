// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int sum = 0;
        int N = n;
        while(n != 0){
            int digit = n %10;
            sum += digit*digit*digit;
            n/=10;
        }
        
        return sum == N;
    }
};