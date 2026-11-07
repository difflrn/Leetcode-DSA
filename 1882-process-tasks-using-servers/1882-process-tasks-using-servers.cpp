class Solution {
public:
    typedef pair<int, int> P; 
    // weight, index
    typedef tuple<long long, int, int> T;
    // finishTime, weight, index
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Free servers: minimum weight, then minimum index
        priority_queue<P, vector<P>, greater<P>> freeServers;
        // Busy servers: minimum finishTime, then weight, then index
        priority_queue<T, vector<T>, greater<T>> busyServers;
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> result(m);
        for (int i = 0; i < m; i++) {
            // Move all available servers to freeServers
            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            // Case 1: Free server available
            if (!freeServers.empty()) {
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }

            // Case 2: No free server available
            else {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            }
        }
        return result;
    }
};