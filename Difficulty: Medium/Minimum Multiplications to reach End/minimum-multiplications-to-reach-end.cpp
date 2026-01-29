class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;

        const int MOD = 100000;
        vector<int> dist(MOD, -1);

        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int x : arr) {
                int next = (curr * x) % MOD;

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    if (next == end) return dist[next];
                    q.push(next);
                }
            }
        }
        return -1;
    }
};