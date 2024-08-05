class Solution {
public:
void solve(vector<string>& arr,  unordered_map<string, int> &mp,  vector<string> &vect ){
    
    for(auto it:arr){
        if(mp.find(it) == mp.end()){ //matlab vo element map m nhi mila
            //mp m nhi mila to obviuosly vector m bhi nhi milega
            ///sabse pahle vector m push karte hai
            vect.push_back(it);
        }
        // ab agar map me present nhi hai to use add karna hoga lekin yadi present hai to uski frequency increase karni hogi
        mp[it]++;
    }
}

    string kthDistinct(vector<string>& arr, int k) {
        //here we will use 2 data structure
            // map and vector
           

        unordered_map<string, int> mp;
        vector<string> vect;

        solve(arr, mp, vect);

        for(auto it : vect){
            cout<<it<<" ";
        }

        int count = 0;

        for(auto it : vect){
            if(mp[it]==1){
                count++;
                if(count == k){
                    return it;
                }
            }
         }

        return "";
        
    }
};
