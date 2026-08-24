class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        sort(nums.begin(), nums.end());
        int index1 = 0;
        vector<vector<int>> ans;
        int start = -1;
        int end = lower;
     
        for(int i=0;i<nums.size();i++)
        {
            if(lower>nums[i])index1++;
        }
        int ele = nums[0];
        if(index1<nums.size())
           ele=nums[index1];
cout<<ele;

        for (int i = lower; i <= upper; i++) {
            if (ele != i) {
                if (start == -1)
                    start = i;

                end = i;
            } else {
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                if (start != -1)
                    ans.push_back(temp);

                if (index1 + 1 == nums.size()) {
                    start = ele + 1;
                    ele = upper + 1;
                    end = ele;
                } else {
                    start = -1;
                    end = start;
                    while(index1<nums.size()&&nums[index1]==ele)index1++;
                    if(index1==nums.size())ele = upper + 1;
                    else ele = nums[index1];
                }
            }
            if (i == upper) {
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                if (start != -1&&end<=upper)
                    ans.push_back(temp);
            }
        }

        return ans;
    }
};