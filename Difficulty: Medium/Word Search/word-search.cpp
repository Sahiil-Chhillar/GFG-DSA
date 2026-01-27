class Solution {
  public:
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    bool f(int r,int c, int idx,vector<vector<char>> &mat, string &word,vector<vector<bool>>& visitedCell,int m,int n){
        if(idx >= word.size() || mat[r][c] != word[idx]) return false;
        if(idx == word.size()-1) return true;
        
        visitedCell[r][c] = true;
        for(auto& d : dir){
            int nr = r + d.first;
            int nc = c + d.second;
            if((nr < m && nr >= 0) && (nc < n && nc >= 0) && !visitedCell[nr][nc]){
                if(f(nr,nc,idx+1,mat,word,visitedCell,m,n)) return true;
            }
        }
        visitedCell[r][c] = false;
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visitedCell(m,vector<bool>(n,false));
        
        for(int r = 0; r <m;r++){
            for(int c = 0 ; c < n ;c++){
                if(mat[r][c] == word[0]){
                    visitedCell[r][c] = true;
                    if(f(r,c,0,mat,word,visitedCell,m,n)) return true;
                    visitedCell[r][c] = false;
                }
            }
        }
        
        return false;
    }
};