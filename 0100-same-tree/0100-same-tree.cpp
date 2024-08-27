/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==NULL && p==NULL) return true;
        
        if(q==NULL && p!=NULL) return false;
        if(q!=NULL && p==NULL) return false;

        queue<TreeNode*>one;
        queue<TreeNode*>two;
        one.push(p);
        two.push(q);

        while(!one.empty() && !two.empty()){
            int len1 = one.size();
            int len2 = two.size();

            if(len1!=len2) {
                cout<<"line1"<<endl;
                return false;
            }

            for(int i=0; i<len1; i++){
                TreeNode *current1 = one.front();
                one.pop();
                TreeNode *current2 = two.front();
                two.pop();

                
                if(current1->val != current2->val) {
                    cout<<"line2"<<endl;
                    return false;
                }

                int x=0,y=0;
                if(current1->left!=NULL) {
                    x++;
                    one.push(current1->left);       
                }

                if(current2->left!=NULL){
                    y++;
                    two.push(current2->left);
                }

                if(x!=y) return false;
               
                
                if(current1->right!=NULL) {
                    x++;
                    one.push(current1->right);       
                }

                if(current2->right!=NULL) {
                    y++;
                    two.push(current2->right);
                }
                
                if(x!=y) return false;
            }
        }

        return true;
    }
};