class Solution {
  public:
    int minProd(vector<int>& arr) {
     int no_of_Neg=0;int p=1;
        int max_Neg=-11;int min_pos=10;
        int n=arr.size();int mini=1e9;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                no_of_Neg++;
                max_Neg=max(max_Neg,arr[i]);
                mini=min(mini,arr[i]);
            }
            else{
                min_pos=min(min_pos,arr[i]);
            }
            if(arr[i]!=0)
            p*=arr[i];
        }
        if(no_of_Neg==0){
            return min_pos;
        }
        
        // if(n==no_of_Neg){
        //     return mini;
        // }
        if(no_of_Neg%2==1){
            return p;
        }
        
        return p/max_Neg;
        
    }
};