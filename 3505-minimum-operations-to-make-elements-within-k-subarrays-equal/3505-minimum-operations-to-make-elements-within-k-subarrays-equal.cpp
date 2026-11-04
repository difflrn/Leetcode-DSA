class Solution {
public:
    multiset<long long> left, right;
    long long sumL = 0, sumR = 0;
    void balance() {
        while (left.size() > right.size() + 1) {
            long long val = *left.rbegin();
            left.erase(left.find(val));
            sumL -= val;
            right.insert(val);
            sumR += val;
        }

        while (left.size() < right.size()) {
            long long val = *right.begin();
            right.erase(right.find(val));
            sumR -= val;
            left.insert(val);
            sumL += val;
        }
    }

    // Window mein element add karna
    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumL += val;
        }
        else {
            right.insert(val);
            sumR += val;
        }
        balance();
    }

    // Window se element remove karna
    void remove(int val) {
        auto it = left.find(val);
        if (it != left.end()) {
            left.erase(it);
            sumL -= val;
        }
        else {
            auto it2 = right.find(val);
            right.erase(it2);
            sumR -= val;
        }
        balance();
    }

    // Current window ko equal karne ki minimum cost
    long long getCost() {
        long long median = *left.rbegin();
        long long a = median * left.size() - sumL;
        long long b = sumR - median * right.size();
        return a + b;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        // Step 1: Har size x window ki minimum cost
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            // Window size x se bada ho to purana element hatao
            if (i >= x) {
                remove(nums[i - x]);
            }
            // Valid window mil gaya
            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // Step 2: DP
        const long long INF = 1e18;
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);
            for (int i = 1; i <= n; i++) {
                // Option 1: Element skip 
                curr[i] = curr[i - 1];
                // Option 2: Size x ka subarray select
                if (i >= x) {
                    int start = i - x;
                    curr[i] = min(curr[i],prev[start] + cost[start]);
                }
            }
            prev.swap(curr);
        }
        return prev[n];
    }
};
