// Pass The Pillow


// 1. Time Complexity : O(n)

class Solution {
public:
    int passThePillow(int n, int time) {
        if(n==1){
            return 1;
        }
        char dir = 'r';
        int index = 1;
        for(int i=0; i<time; i++){
            if(index == 1){
                dir = 'r';
            }
            else if(index == n){
                dir = 'l';
            }


            if(dir == 'r'){
                index++;
            }
            else{
                index--;
            }
        }
        return index;
        
    }
};



//2. Time Complexity : O(1)

class Solution {
public:
    int passThePillow(int n, int time) {
        //agar n ki value 1 hai to jahe jitni baar travel kar lo pilow always same place p hogi 
        if(n==1){
            return 1;
        }
        //yha hum ye calculate karege ki vo left jayega ya right
        // agar modulus ki value 0 ya to even hai to vo left to right jayega
        // agar odd hai to vo right to left jayega
        //aur jitna remainder hoga utna use travel karna hoga 
        int nn = n-1;
        int index;

        int m = time/nn;
        int r = time%nn;

        if(m%2==0 || m==0){
            //left to right
            // yadi hai left to right jayega to iski iitial position 1 hogi
            index = 1;
            index+=r;
        }
        else{
            //right to leftogi
            //yadi right to left jayega to initial position n h
            index = n;
            index-=r;
        }

        return index;
        
    }
};