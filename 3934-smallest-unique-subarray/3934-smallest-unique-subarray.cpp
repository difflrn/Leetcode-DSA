class Solution {
public:
    vector<int> buildSuffixArray(vector<int>& nums) {
        vector<int> a = nums;
        a.push_back(0);

        int n = a.size();

        vector<int> p(n), c(n);
        int alphabet = max(n, *max_element(a.begin(), a.end()) + 1);
        vector<int> cnt(alphabet, 0);

        for (int x : a) {
            cnt[x]++;
        }

        for (int i = 1; i < alphabet; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[a[i]]] = i;
        }

        c[p[0]] = 0;
        int classes = 1;

        for (int i = 1; i < n; i++) {
            if (a[p[i]] != a[p[i - 1]]) {
                classes++;
            }
            c[p[i]] = classes - 1;
        }

        for (int h = 0; (1 << h) < n; h++) {
            vector<int> pn(n);

            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);

                if (pn[i] < 0) {
                    pn[i] += n;
                }
            }

            fill(cnt.begin(), cnt.end(), 0);

            for (int x : pn) {
                cnt[c[x]]++;
            }

            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }

            for (int i = n - 1; i >= 0; i--) {
                p[--cnt[c[pn[i]]]] = pn[i];
            }

            vector<int> cn(n);
            cn[p[0]] = 0;

            int newClasses = 1;

            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {
                    c[p[i]],
                    c[(p[i] + (1 << h)) % n]
                };

                pair<int, int> prev = {
                    c[p[i - 1]],
                    c[(p[i - 1] + (1 << h)) % n]
                };

                if (cur != prev) {
                    newClasses++;
                }

                cn[p[i]] = newClasses - 1;
            }

            c = cn;
            classes = newClasses;
        }

        p.erase(p.begin());
        return p;
    }

    vector<int> buildLCP(vector<int>& nums, vector<int>& sa) {
        int n = nums.size();

        vector<int> rank(n);
        vector<int> lcp(n, 0);

        for (int i = 0; i < n; i++) {
            rank[sa[i]] = i;
        }

        int k = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0) {
                k = 0;
                continue;
            }

            int j = sa[rank[i] - 1];

            while (i + k < n && j + k < n &&
                   nums[i + k] == nums[j + k]) {
                k++;
            }

            lcp[rank[i]] = k;

            if (k > 0) {
                k--;
            }
        }

        return lcp;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa = buildSuffixArray(nums);
        vector<int> lcp = buildLCP(nums, sa);

        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            int maxLCP = lcp[i];

            if (i + 1 < n) {
                maxLCP = max(maxLCP, lcp[i + 1]);
            }

            int len = maxLCP + 1;

            if (len <= n - sa[i]) {
                ans = min(ans, len);
            }
        }

        return ans;
    }
};
