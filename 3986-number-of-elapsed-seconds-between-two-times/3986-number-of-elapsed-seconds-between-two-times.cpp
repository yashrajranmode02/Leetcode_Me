class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int a=(startTime[0]-'0')*10+(startTime[1]-'0');
        int b=(endTime[0]-'0')*10+(endTime[1]-'0');
        int c=(startTime[3]-'0')*10+(startTime[4]-'0');
        int d=(endTime[3]-'0')*10+(endTime[4]-'0');
        int e=(startTime[6]-'0')*10+(startTime[7]-'0');
        int f=(endTime[6]-'0')*10+(endTime[7]-'0');
       cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
        return (b-a)*3600+ (d-c)*60+ (f-e);
    }
};