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
    bool checkSame(TreeNode*one, TreeNode*two){
        if(!one && !two) return true;
        if(!one || !two) return false;

        return (
            (one->val == two->val) 
            && checkSame(one->left, two->left)
            && checkSame(one->right, two->right)
        );
    }

    void helper(TreeNode*one, TreeNode *two, bool &isSame){
        if(!one) return;

        if(isSame) return;
        if(one->val == two->val){
            // could be 
            isSame = checkSame(one, two);
            if(isSame) return;
        }

        helper(one->left, two, isSame);
        helper(one->right, two, isSame);
    }

    string serialize(TreeNode*root){
        if(!root){            
            return "$#";
        }
        return "$"+to_string(root->val)+serialize(root->left)+serialize(root->right);
    }

     vector<int>kmpAlgo(string &a, string &b){
        int n = a.size();
        int m = b.size();

        // build lps for pattern --
        /*
        length of the longest proper prefix of pattern[0…i]
        that is also a suffix of pattern[0…i]
        *Proper prefix = cannot be the whole string.
        *suffix from behind

        build the LPS array for the pattern(b): A B A B C
        --abc then ProperPrefixes(similarly proper suffix) - a,ab (all prefix except the entire array)
        Index   Substring   ProperPrefixes      ProperSuffixes        LPS Value   
        0       A           -                       -                     0
        1       AB          A                       B,                    0
        2       ABA         A, AB                   A, BA                 1 (match is A)
        3       ABAB        A, AB, ABA              B, AB, BAB            2 (match is AB)
        4       ABABC       A, AB, ABA, ABAB        C, BC, ABC,BABC       0
        */
        vector<int>lps(m,0);
        int i = 1;
        int len = 0;
        while(i<m){
            if(b[i]==b[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

        // pattern matching
        i=0;
        int j=0;
        vector<int>ans;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            if(j==m){
                // starting index will be i-m -- i++ and j++ already happned
                ans.push_back(i-m);
                j=lps[j-1];
            }

            else if(i<n && a[i]!=b[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // good ---
        /*
        bool isSame = false;
        helper(root, subRoot, isSame);
        return isSame;
        */

        // optimal --- using seriallization ---
        string main=serialize(root);
        string sub=serialize(subRoot);   

        // replace with kmp function/z/or rabin karp --- (i know kmp see from needle and 
        //haystack problem leetcode)
        /*
        if(main.find(sub)!=string::npos){
            return true;
        }
        else return false;
        */
        vector<int>ans = kmpAlgo(main,sub);
        return ans.empty()? false : true;
    }
};