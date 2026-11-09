class Solution {
public:
    typedef pair<int, int> P ;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avaliableServers ;
        for( int i = 0 ; i < k ; i++ ){
            avaliableServers.insert(i);
        }

        priority_queue<P, vector<P>, greater<P>> busyServers ;

        vector<int> countRequests(k, 0 ) ;

        for ( int i = 0 ; i <arrival.size() ; i++ ){
            int time  = arrival[i] ;

            while  (!busyServers.empty()  &&  busyServers.top().first <= time ){
                int server = busyServers.top().second ;

                busyServers.pop() ;

                avaliableServers.insert(server);
            }

            int target = i % k ;
            
            auto it = avaliableServers.lower_bound(target) ;

            if ( it  ==  avaliableServers.end() ){
               it = avaliableServers.begin() ;
            }
            
            if ( avaliableServers.empty() ){
               continue ;
            }

            int targetServer  = *it ;

            avaliableServers.erase(it) ;

            busyServers.push({ time+load[i] , targetServer  });
            countRequests[targetServer]++ ;
        }

        int maxNumberOfRequest = *max_element( begin(countRequests), end(countRequests)) ;
         vector<int> result;
        for ( int i = 0  ; i < k ; i++ ){
            if(countRequests[i] == maxNumberOfRequest ){
                result.push_back(i) ;
            }
        }
        return result ;

    }
};