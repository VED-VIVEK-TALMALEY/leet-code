#include<cmath>
#include <iostream>
#include <algorithm>
using namespace std ;
class Solution {

public:
    int mySqrt(int x) {
        return static_cast <int>(floor(sqrt(x)));
    }
};