/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;vector<int>as;
        ListNode* d=head->next;int index=1;
        while(d&&d->next){
            if(d->val < d->next->val&&d->val<temp->val ){
                as.push_back(index);
            }else if(d->val > d->next->val&&d->val>temp->val){
               as.push_back(index); 
            }
            temp=d;
            d=d->next;index++;
        }
        if(as.size()==0)return {-1,-1};
        int a=INT_MAX;
    for(int i=0;i<as.size()-1;i++){
        int d=as[i+1]-as[i];
        a=min(a,d);
    }
    int b=0;
    int l=0;int r=as.size()-1;
    while(l<r){
        b=max(b,as[r]-as[l]);l++;r--;
    }
    cout<<a<<b;
    if(a==INT_MAX&&b==0)return {-1,-1};
return {a,b};

    }
};