class Solution {
public:
    int largestInteger(int n, int us) {
        int s=pow(10,n)-1;int p=-1;
        for(int i=s;i>=0;i--){
            int index=i;
            int ans=0;
            while(index){
                ans+=(index%10);index/=10;
            }
            if(ans==us){
                p=i;break;
            }
        }
        cout<<s;
        return p;
    }
};