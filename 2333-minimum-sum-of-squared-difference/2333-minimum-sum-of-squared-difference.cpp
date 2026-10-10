class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long totalK = (long long)k1 + k2;
        long long totalDiffSum = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            totalDiffSum += diff[i];
        }

        if (totalDiffSum <= totalK) return 0;

        map<long long, long long, greater<long long>> counts;
        for (long long d : diff) {
            counts[d]++;
        }

        while (totalK > 0 && !counts.empty()) {
            auto it = counts.begin();
            long long curMax = it->first;
            long long count = it->second;

            if (curMax == 0) break;

            auto nextIt = std::next(it);
            long long nextMax = (nextIt != counts.end()) ? nextIt->first : 0;

            long long reductionPerItem = curMax - nextMax;
            long long totalCanReduce = reductionPerItem * count;

            if (totalK >= totalCanReduce) {
                counts.erase(it);
                if (nextMax > 0) {
                    counts[nextMax] += count;
                }
                totalK -= totalCanReduce;
            } else {
                long long itemsToDrop = totalK / count;
                long long remainder = totalK % count;
                long long newMax = curMax - itemsToDrop;

                counts.erase(it);
                counts[newMax] += (count - remainder);
                counts[newMax - 1] += remainder;
                totalK = 0;
            }
        }

        long long ans = 0;
        for (auto& p : counts) {
            ans += p.second * p.first * p.first;
        }

        return ans;
    }
};