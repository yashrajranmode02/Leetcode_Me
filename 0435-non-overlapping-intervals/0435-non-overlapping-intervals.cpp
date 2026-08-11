class Solution {
public:
    void swapy(vector<vector<int>>& intervals){
        for(int i=0;i<intervals.size();i++){
            swap(intervals[i][0],intervals[i][1]);
        }
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        swapy(intervals);
        sort(intervals.begin(), intervals.end());
        swapy(intervals);
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = 0; j < intervals[i].size(); j++) {
                cout << "{ " << intervals[i][j] << " }";
            }
            cout << endl;
        }
        int count = 0;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (second > intervals[i][0]) {
                // cout<<intervals[i][0]<<"->"<<intervals[i][1]<<endl;
                count++;
            } else {
                second = (intervals[i][1]);
            }
        }
        return count;
    }
};