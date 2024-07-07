//Time Complexity : O(n)
//Space Comlexity : o(1)

class Solution {
public:
    int maxBottlesDrunk(int &numBottles, int &numExchange) {


        int fullBottel = numBottles;
        int emptyBottel = 0;
        int drunkBottel = 0;

        while(fullBottel>0 || emptyBottel>=numExchange){
            //agar empty bottel ki value numexchange ki value se jyada or equal hai tbhi exchange karega
            if(emptyBottel>=numExchange){
                //pahli baar to ek baar me ek hi bottel exchange karega
                //agr ek bottel exchane ki to full botel ki quatity ek badh javegi
                fullBottel++;
                //aur empty bottel ki quantity kam ho javegi
                emptyBottel = emptyBottel-numExchange;
                numExchange++;
            }
            else{
                drunkBottel += fullBottel;
                
                emptyBottel += fullBottel; 
                fullBottel = 0; 
            }
        }

        return drunkBottel;
        
    }
};