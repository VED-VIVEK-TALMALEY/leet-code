class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0 ; 
        int j = 0 ; 
        while (j<chars.size()){
            int k = j ;
    while (k<chars.size()&& chars[k]==chars[j]){
        k++;
    }   
    chars[i++]= chars[j];
    if (k-j>1){
     string s = to_string(k-j);
     for (char c :s ){
        chars[i++]=c ; 
     }
    }
    j=k ;
    
    }
 return i ; 
    }
};