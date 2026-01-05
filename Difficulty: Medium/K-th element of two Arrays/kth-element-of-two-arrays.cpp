class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();

        int i = 0, j = 0;
        int cnt = 0;

        while (i < n && j < m) {
            int val;
            if (a[i] <= b[j]) {
                val = a[i++];
            } else {
                val = b[j++];
            }

            cnt++;
            if (cnt == k) return val;
        }

        while (i < n) {
            cnt++;
            if (cnt == k) return a[i];
            i++;
        }

        while (j < m) {
            cnt++;
            if (cnt == k) return b[j];
            j++;
        }

        return -1;
    }
};