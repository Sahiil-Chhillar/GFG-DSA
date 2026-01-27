class Solution {
  public:
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    bool f(int r,int c, int idx,vector<vector<char>> &mat, string &word,int m,int n){
        if(idx >= word.size() || mat[r][c] != word[idx]) return false;
        
        if(idx == word.size()-1) return true;
        
        char temp = mat[r][c];
        mat[r][c] = '#';
        
        for(auto& d : dir){
            int nr = r + d.first;
            int nc = c + d.second;
            if((nr < m && nr >= 0) && (nc < n && nc >= 0) && mat[nr][nc] != '#'){
                if(f(nr,nc,idx+1,mat,word,m,n)) return true;
            }
        }
        
        mat[r][c] = temp;
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int m = mat.size();
        int n = mat[0].size();
        for(int r = 0; r <m;r++){
            for(int c = 0 ; c < n ;c++){
                if(mat[r][c] == word[0]){
                    if(f(r,c,0,mat,word,m,n)) return true;
                }
            }
        }
        
        return false;
    }
};