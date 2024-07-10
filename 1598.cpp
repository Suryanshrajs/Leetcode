//Time Complexity : O(n)
//Space Complexity : O(1)



class Solution {
public:
    int minOperations(vector<string>& logs) {
        if(logs.size()==0){
            return 0;
        }
        int count = 0; 

        for(auto it :logs){

            if(count<0){
                count = 0;
            }
            if(it=="../") count--;
            else if(it == "./") continue;
            else count++;
        }

    if(count<=0)    return 0;

    return count;

    }
};