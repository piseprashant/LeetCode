class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        //get that vector over which we have to apply binary search
        vector<pair<string,int>> &arr = mp[key];
        int n=arr.size();
        
        //no pair is attached with given key
        if(n==0) return "";
        
        //apply binary search
        int low =0,high=n-1,mid;
        
        //predicate: arr[mid].second > timestamp
        
        while(low < high){
            mid = low + (high - low + 1)/2;
            if(arr[mid].second > timestamp )
                high=mid-1;
            else
                low = mid;
        }
        
        //sanity check
        if(arr[low].second <= timestamp)
            return arr[low].first;
        else
            return "";
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
