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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if ( root == NULL )  return {} ;
        
        vector<vector<int>> ans ;
        vector<int> x ;

        queue<TreeNode*> q ;
        q.push( root) ;
        q.push(NULL );

        while ( !q.empty() ){
           TreeNode* temp = q.front() ;
           q.pop() ;

            if ( temp == NULL ){ // ek level complete ho gya 
               ans.push_back(x) ;
               x.clear() ;
                 
                if(!q.empty()){ /// still queue me some element hai to push NULL for nect separator
                    q.push(NULL ) ;
                }
            }
            else{
                x.push_back(temp->val) ;
                if( temp -> left ){
                    q.push( temp -> left );
                }
                if( temp -> right ){
                    q.push( temp -> right );
                }
            }
           
        }
         int s = 0 ;
            int e = ans.size() -1 ;
            while ( s<e) {
                swap(ans[s] , ans[e] ) ;
                s++;
                e--;
            }
        return ans ;
    }
};