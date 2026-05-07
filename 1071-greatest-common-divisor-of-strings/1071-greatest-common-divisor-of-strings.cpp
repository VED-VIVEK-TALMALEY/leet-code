class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       int len1 = str1.length();
       int len2 = str2.length();
       int gdd= gcd(len1,len2);
       int i = 0 ; 
       string result="";
       if(str1+str2!=str2+str1){
        result="";
       }
       else{
       while(i<gdd){
        result+=str1[i];
        i++;
       }
    }
       return result;
    }
};