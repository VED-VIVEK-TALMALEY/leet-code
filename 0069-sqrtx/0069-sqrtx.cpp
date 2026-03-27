#include <cmath>
#include <iostream>

using namespace std; // Corrected syntax

class Solution {
public:
    int mySqrt(int x) {
        
        return static_cast<int>(floor(sqrt(x))); 
    }
};