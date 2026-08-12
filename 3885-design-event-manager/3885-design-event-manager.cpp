class EventManager {
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mpp;
    unordered_map<int, int> mpp2;

    EventManager(vector<vector<int>>& events) {
        for (int i = 0; i < events.size(); i++) {
            pq.push({events[i][1], -events[i][0]});
            mpp[-events[i][0]] = events[i][1];
            mpp2[events[i][1]]++;
        }
    }

    void updatePriority(int eventId, int newPriority) {
        int ans = 0;

        mpp2[mpp[-eventId]]--;

        if (mpp2[mpp[-eventId]] == 0)
            mpp2.erase(mpp[-eventId]);

        mpp.erase(-eventId);
        pq.push({newPriority, -eventId});
        mpp[-eventId] = newPriority;
        mpp2[newPriority]++;
        // cout << pq.size();
    }

    int pollHighest() {
        int ans = -1;
        while (!pq.empty()) {
            int node = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            if (mpp.find(id) != mpp.end() && mpp[id]==node) {
                mpp.erase(id);
                mpp2[node]--;
                if (mpp2[node] == 0)
                    mpp2.erase(node);
                ans = -id;
                break;
            }
        }

        return ans;
    }
};
