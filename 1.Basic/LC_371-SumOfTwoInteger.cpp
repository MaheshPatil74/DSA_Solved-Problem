// Original Approach
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1; // carry nikaala
            a = a ^ b;               // sum without carry
            b = carry;               // carry ko add karna baaki
        }
        return a;
    }
};


// Approach: Simple Addition (Time Complexity: O(1), Space Complexity: O(1))
// Wrong approach bcoz Problem tells to not use + or - operators.
class Solution {
public:
    int getSum(int a, int b) {
        return a+b ;
    }
};
