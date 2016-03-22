From leetcode 136. Single Number  
Problem: Given an array of integers, every element appears twice except for one. Find that single one.  
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?  
  
Key: known that A XOR A = 0 and the XOR operator is commutative, the solution will be very straightforward.  
解释：A 异或 A 是 0，A 异或 0 是 A，那么 A 异或 A 再异或 B 就是 B 咯。  
Code: C  

    int singleNumber(int* nums, int numsSize) {
        int result = 0;
        for(int i=0;i<numsSize;i++) {
        result ^= nums[i];
        }
        return result;
    }