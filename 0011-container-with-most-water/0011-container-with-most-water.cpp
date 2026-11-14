class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwell=0;
        vector<int>ans(height.size(),0);

        int start=0;int end=height.size()-1;
             while(start<end) {
                  maxwell=max(maxwell,((end-start)*(min(height[start],height[end])))); 
                  if(height[start]<=height[end]){
                    start++;
                  }
                  else{end--;}
               }
           
        return maxwell;
    }
};