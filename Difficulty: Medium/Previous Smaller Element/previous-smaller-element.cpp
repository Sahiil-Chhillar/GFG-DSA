class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n,-1);
        
        for(int i = 0;i< n;i++){
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};