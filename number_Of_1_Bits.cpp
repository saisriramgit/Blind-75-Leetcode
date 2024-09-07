//Time Complexity: O(log N)
//Space Complexity: O(1)

class Solution {
public:
    int hammingWeight(int n) {
        int i = 0, rem = 0;
        bitset<64> arr(n);
        int count = 0;
        while(n != 0) {
            rem = n % 2;
            arr[i++] = rem;
            n /= 2;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) {
                count++;
            }
        }
        return count;
    }
};