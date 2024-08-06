// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<int, int> mp;
//         int curr_key = 2;
//            int result = 0;

//         for(auto it : word){
//             if(curr_key>9){
//                 curr_key = 2;
//             }

//             mp[curr_key]++;
//             result+=mp[curr_key];
            
//             curr_key++;
//         }

        

//         return result;
        
//     }
// };
















class Solution {
public:
    int minimumPushes(string word) {

      vector<int> mp(26,0);

      for(auto it : word){
        mp[it-'a']++;
      } 

      //sort frequency in descending order
      sort(mp.begin(), mp.end(), greater<int>());

      int result = 0;

      for(int i=0; i<26; i++){
        int freq = mp[i];

        int press = i/8+1;

        result += press* freq;

      }

      return result;
        
    }
};
