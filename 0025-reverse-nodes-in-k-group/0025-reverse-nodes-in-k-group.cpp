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
    vector<ListNode*>donode(vector<int>v){
        int n = v.size();
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        for(int i=v.size()-1; i>=0; i--){
            ListNode *newNode = new ListNode(v[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return {head->next, temp};
    }

    ListNode *helper(vector<int>v){
        ListNode *head = new ListNode(v[0]);
        ListNode *temp = head;
        for(int i=1; i<v.size(); i++){
            ListNode *newNode = new ListNode(v[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v;
        ListNode *temp = head;
        int x = 0;
        ListNode *newHead = new ListNode(0);
        ListNode *dummy = newHead;
        while(temp){
            if(x<k){
                v.push_back(temp->val);
                x++;
                temp = temp->next;
            }
            else if(x==k){
                vector<ListNode*>node = donode(v);
                dummy->next = node[0];                
                dummy = node[1];                
                x = 0;
                v.clear();
            }
        }
        if(!v.empty()){
            if(v.size()!=k){
                ListNode *makenode = helper(v);
                dummy->next = makenode;
            }
            else{
                vector<ListNode*>node = donode(v);            
                dummy->next = node[0];                
                dummy = node[1];                
                x = 0;
                v.clear();
            }
        }
        return newHead->next;
    }
};