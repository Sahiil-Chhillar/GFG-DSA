class Solution {
  public:
    int hcf ( int a,int b){
        if(b == 0) return a;
        return hcf(b,a%b);
    }
    int lcm(int a, int b) {
        // a*b = lcm(a,b) * hcf(a,b)
        return a*b/hcf(a,b);
    }
};