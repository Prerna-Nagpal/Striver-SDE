class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      unordered_map<int,int> freq;
    int maxFreq = 0, total = 0;

for (int num : nums) {
    int count = ++freq[num];

    if (count > maxFreq) {
        maxFreq = count;
        total = count;  
    } else if (count == maxFreq) {
        total += count; 
    }
}

   return total;   

    }
};