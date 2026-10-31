// Intuition 02 : T.C  = O(n)
//  1. Create a map  , and store ( num[i] , index ) { m[nums[i]] , i}
//  2. Traverse each element of nums by for loop 
//  3. Compare  remaining = (target - nums[i]) , if it  is present in map or not 
//  4. if present then return the remaining`s index and current element`s index 
//      else return {}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int, int > m ;
       for ( int i = 0 ; i < nums.size() ; i++ ){
           int remaining = target - nums[i] ;
            if ( m.find(remaining) != m.end() ){ // means map me remaining value found ho chuka hai
                return {m[remaining] , i};
            }
            m[nums[i]] = i; 
        } 
        return {} ;
    }
};

// Intuition 01 -> by 2 loops 
   //  T.C = O(n^2)
