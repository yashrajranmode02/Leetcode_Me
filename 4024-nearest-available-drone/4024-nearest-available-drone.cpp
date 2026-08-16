class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
   int d=0;    bool p=0; int count=1e9;
        for(int i=0;i<drones.size();i++){
            if((abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]))<=drones[i][2]){
                if(count>(abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]))){
                    d=i;p=1;
                }
                count=min(count,(abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1])));

            }
        }
        if(p)
        return d;
        return -1;
    }
};