class Solution {
public:
    long long sumAndMultiply(int n) {
        int number=0;
        while(n){
            if(n%10!=0)
            number=number*10+(n%10);
            n/=10;
        }
        long long sum=0;long long r=0;
        
         while(number){ 
            r=r*10+(number%10);
            number/=10;
        }
        //    cout<<r;
           number=r;
        while(number){
            sum=sum+(number%10);number/=10;
        }
        cout<<sum;
        return 1LL*sum*r;
    }
};