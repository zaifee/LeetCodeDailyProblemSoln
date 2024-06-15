class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++) {
            projects.push_back({profits[i], capital[i]});
        }

        // Sorting by capital required, then by profit
        sort(projects.begin(), projects.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        priority_queue<int> pq;
        int i = 0;
        while (k > 0) {
            while (i < n && projects[i].second <= w) {
                pq.push(projects[i++].first);
            }

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
                k--;
            } else {
                break;
            }
        }
        return w;
    }
};
