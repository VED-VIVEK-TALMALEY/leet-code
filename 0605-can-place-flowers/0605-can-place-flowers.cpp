class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int counter=0 ; 
   
for ( int x =0;x<len;x++) {
        if (flowerbed[x] == 0 && 
   (x == 0 || flowerbed[x-1] == 0) && 
   (x == len-1 || flowerbed[x+1] == 0)){
        counter ++;
        flowerbed[x]=1;
         
    }
    
}
return counter>=n;
    }
};