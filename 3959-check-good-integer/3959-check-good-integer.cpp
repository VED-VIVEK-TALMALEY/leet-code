class Solution {
public:
    bool checkGoodInteger(int n) {
      int digitSum=0;
       int squareSum=0;
        int digit = 0 ; 
          while(n>0){
         digit = n%10;
         n=n/10;
         digitSum+=digit;
         squareSum+=(digit*digit);
        }
         return(squareSum - digitSum >= 50);
    }
};