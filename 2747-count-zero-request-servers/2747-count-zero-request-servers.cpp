
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        
        int m = queries.size();

        // Store queries with their original indices
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        // Sort queries by time
        sort(q.begin(), q.end());

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> ans(m, 0);
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int activeServers = 0;

        for (auto& [time, idx] : q) {

            // Add logs in the window [time-x, time]
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0)
                    activeServers++;

                freq[server]++;
                right++;
            }

            // Remove logs older than time-x
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    activeServers--;

                left++;
            }

            // Servers with zero requests
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};
