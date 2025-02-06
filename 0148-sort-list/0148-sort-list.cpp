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

    ListNode *findmiddle(ListNode *head){
        if(head==NULL || head->next == NULL) return head;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode*right){
        ListNode *newhead = new ListNode(-1);
        ListNode *temp = newhead;
        while(left && right){
            if(left->val > right->val){
                temp->next = right;
                right = right->next;
            }
            else{
                temp->next = left;
                left = left->next;
            }
            temp = temp->next;
        }

        if(left!=NULL){
            temp->next = left;
        }
        if(right!=NULL){
            temp->next = right;
        }

        return newhead->next;

    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;

        // brute ---
        /*
        vector<int>v;
        ListNode *temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }   
        sort(v.begin(), v.end());
        ListNode *newhead = new ListNode(v[0]);
        temp = newhead;
        for(int i=1; i<v.size(); i++){
            ListNode*newnode = new ListNode(v[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return newhead;
        */
        
        // best --- mergesort
        ListNode *middle = findmiddle(head);
        ListNode *right = middle->next;
        middle->next = NULL;
        ListNode *left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);

    }
    
};