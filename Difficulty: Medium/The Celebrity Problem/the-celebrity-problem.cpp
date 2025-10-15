class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        // vector<vector<int>> graph(n);
        vector<int> outDegree(n,0);
        vector<int> inDegree(n,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if(i != j && mat[i][j] == 1){
                    outDegree[i]++;
                    inDegree[j]++;
                } 
            }
        }
        
        for(int i = 0 ; i < n ;i++) if(outDegree[i] == 0 && inDegree[i] == n-1) return i;
        return -1;
    }
};