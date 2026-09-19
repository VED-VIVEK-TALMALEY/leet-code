#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false); 
       cin.tie(NULL);
        unordered_map<int, int> hashMap;
        for(int& x : arr) {
            hashMap[x]++; 
        }

        unordered_set<int> freqSet;
        for(auto& [key, val] : hashMap) {
            freqSet.insert(val); 
        }

      
        return hashMap.size() == freqSet.size();
    }
};