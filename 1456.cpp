class Solution {
public:

    bool isVowel(char ch){
        if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u' ){
            return true;
        }

        return false;
    }
    int maxVowels(string s, int k) {
        //k size ki window;
        int i = 0;
        int j = 0;
        int count = 0;
        int maxCount = INT_MIN;

        while(j<s.size()){
            if(isVowel(s[j])){
                count++;
            }
            if(j-i>=k ){
                if( isVowel(s[i])) count--;
                
                i++;
            }
            j++;

            maxCount = max(maxCount, count);
        }
    return maxCount;
        
    }
};
