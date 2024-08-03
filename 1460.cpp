//Time Complexity : O(n)
//Space Complexity : O(n)


// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         if(arr.size() != target.size()) return false;

//         unordered_map<int, int> mp;

//         for(auto it : target){
//             mp[it]++;
//         }

//         for(auto itt : arr){
//             if(mp.find(itt) != mp.end()){
//                 mp[itt]--;

//                 if(mp[itt] == 0){
//                     mp.erase(itt);
//                 }
//             }
//             else{
//                 return false;
//             }
//         }
//         if(mp.size()==0){
//             return true;
//         }

//         return false;
        
//     }
// };






//Time Complexity : O(nlog(n))
//Space Complexity : O(1)



class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(arr.size() != target.size()) return false;

        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());

        for(int i =0; i<arr.size(); i++){
            if(arr[i] != target[i]) return false;
        }


        return true;
        
    }
};





