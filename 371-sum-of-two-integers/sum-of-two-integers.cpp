// SOL2 USING RECURSION
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;  // Base case: No carry left
        int sum = a ^ b;       // Sum without carry
        int carry = (a & b) << 1; // Carry shifted left
        return getSum(sum, carry); // Recursive call
    }
};





//sol
/*
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b; 
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
*/





