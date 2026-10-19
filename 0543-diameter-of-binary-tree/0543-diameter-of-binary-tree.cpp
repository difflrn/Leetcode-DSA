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
pair<int,int> diameterFast(TreeNode* root ){

    pair<int,int> p = make_pair(0 , 0) ; // pair ( diameter , height ) 
    // base case
    if ( root == NULL ) return p ;
    
    // function call 

    pair<int,int> left =  diameterFast( root -> left ) ;
    pair< int,int> right = diameterFast( root -> right ) ;

    int diaLeft  = left.first;                 // diameter only left subtree se aa rha hai 
    int diaRight = right.first ;               // diameter only right subtree se aa rha hai 
    int diameter = left.second+ right.second ; // diamtere current node se hokar ja rha hai 

    pair<int,int> ans ;
    ans.first = max(diameter ,max( diaLeft , diaRight)) ;  // Now tino possibilities ka max le lem=nge do that longest diameter jisase v aa rha ho vo mil jaye .
    ans.second = max( left.second, right.second) +1 ;      // current node ka height calculate kr rha hai 

    return ans ;
}
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast( root ).first ;  // diameter current node ka return kr rha haai  
    }
};