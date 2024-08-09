class Solution {
public:


    bool isMagical(vector<vector<int>>& grid, int row, int col){
        //now i will made a matrix which last row will row+2 and col will be col+2

          unordered_set<int> ut;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int r = row+i;
                int c = col+j;

                /* now three conditions 
                    1. if current value is less than 1
                    2. if current value is greater than 9
                    3. if it is not repeated , to check this condition we need an unordered set
                */

              
                int curr = grid[r][c];


                if(curr < 1 || curr > 9 || ut.find(curr) != ut.end()){
                    return false;
                }
                else{
                    ut.insert(curr);
                }
            }
        }

        //till here i have checked some conditions now i have some remaining conditions
        /*
            Remaining Conditions :
            1. check if rowSum == colSum == diagSum == antiDiagSum
        */

        int Sum = grid[row][col]+grid[row][col+1]+grid[row][col+2];
        int rowSum = 0;
        int colSum = 0;
        int diagSum = 0;
        int antiDiagSum = 0;


        for(int k = 0; k<3; k++){
            rowSum = grid[row+k][col]+grid[row+k][col+1]+grid[row+k][col+2];
            colSum = grid[row][col+k]+grid[row+1][col+k]+grid[row+2][col+k];
        
            if(rowSum != Sum){
                return false;
            }
            if(colSum != Sum){
                return false;
            }

        }


        // now check diag and antidiag

        diagSum = grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
        antiDiagSum = grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col];

        if(diagSum != Sum){
            return false;
        }
        if(antiDiagSum != Sum ){
            return false;
        }






        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        //now i have to check that every 3*3 matrix that is  present isMagical or not
        //i observerd that rows can traverse from 0 to rows-3 and also colms 0 to cols-3

        int count = 0;

        for(int row = 0; row <= rows-3; row++){
            for(int col = 0; col<=cols-3; col++){
                bool ans = isMagical(grid,row, col);

                if(ans == 1){
                    count++;
                }
                    
            }
        }

        return count;
        
    }
};
