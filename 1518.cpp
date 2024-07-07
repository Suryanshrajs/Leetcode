
//Time Complexity : O(n)
//Space Comlexity : O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        if(numBottles<numExchange){
            return numBottles;
        }
        
        int drink = numBottles;
        int free = numBottles;

        while(free>=numExchange){
            drink += (free/numExchange);
            free = (free/numExchange)+(free%numExchange);
        }

        return drink;
        
    }
};



//Using Recursion
//Time Complexity : O(logN)
//Space Complexity : O(1)

class Solution {
public:

    int solveUsingRecursion(int &numBottles, int &numExchange, int &drink, int &free){
         if(numBottles<numExchange){
            return numBottles;
        }

        if(free<numExchange){
            return drink;
        }

        drink += (free/numExchange);
        free = (free/numExchange)+(free%numExchange);

    return solveUsingRecursion(numBottles, numExchange, drink, free);
    }
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles;
        int free = numBottles;
        int ans = solveUsingRecursion(numBottles, numExchange,drink, free);
        return ans;
        
    }
};
