class Solution {
public:
    typedef  long long ll ;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // if individual sum of both costs are less than the costBoth
        if( cost1 + cost2 <= costBoth ){
            return ( 1ll*need1*cost1) + ( 1ll*need2*cost2 ) ;
        }
        // cost1 + cost2 > costBoth
        int both = min(need1 , need2 ) ;
        ll total = 1ll* both * costBoth ;

        need1 -= both ;
        need2 -= both ;
        if( need1 > 0 ){
             total += 1ll * need1 * min( cost1 , costBoth ) ;  
        }
        else if ( need2 > 0 ){
            total += 1ll * need2 * min( cost2 , costBoth ) ;  
        }
        return total ;
    }
};