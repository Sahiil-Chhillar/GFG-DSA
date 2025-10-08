class Solution {
  public:
    bool f(int currNode,int v, vector<vector<int>>& graph, int m, vector<int>& isColored){
        if(currNode == v) return true;
        
        for(int i = 1 ; i <= m ; i++){
            bool isSafe = true;
            for(auto& v : graph[currNode]){
                if(isColored[v] == i){
                    isSafe = false;
                    break;
                }
            }
            
            if(isSafe){
                isColored[currNode] = i;
                if(f(currNode+1,v,graph,m,isColored)) return true;
                isColored[currNode] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        if(m >= v) return true;
        
        vector<vector<int>> graph(v);
        for(auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> isColored(v,0);
        return f(0,v,graph,m,isColored);
    }
};