class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
        return false ;
        if (x>=0&&x<10)
        return true;

        vector<int>result;
       int digit=0;
       int count =0;
while (x > 0){
    digit = x % 10 ;
    x/=10;
 
    result.push_back(digit);
}
//reverse(result.begin(),result.end());
for(int i = 0 ; i < result.size()/2 ; i++){
      if(result[i]!=result[result.size()-i-1]){ 
      return false ; 
      }
    
} 
return true;
    }
};