class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map < int , int > mp ;
        for( int i = 0 ; i < arr.size() ; i++ ){
            mp[arr[i]]++;
        }
        //find unique 
        set<int> s ;
        for ( auto i : mp ){
            s.insert(i.second) ;
        }
        
        return s.size() == mp.size() ;
    }
};