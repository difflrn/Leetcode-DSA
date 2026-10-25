
class Solution {
    static const int MOD = 1e9 + 7;

    vector<long long> sum, sumSq, lazy;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        sumSq[node] += 2LL * val * sum[node]
                     + val * val * len;

        sum[node] += val * len;
        lazy[node] += val;
    }

    void pushDown(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;
        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r,int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        pushDown(node, l, r);
        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        sum[node] = sum[node * 2] + sum[node * 2 + 1];
        sumSq[node] = sumSq[node * 2]+ sumSq[node * 2 + 1];
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n + 5, 0);
        sumSq.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);

        vector<int> last(100001, -1);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];
            update(1, 0, n - 1, prev + 1, i, 1);
            last[nums[i]] = i;
            ans = (ans + sumSq[1]) % MOD;
        }

        return (int)ans;
    }
};
