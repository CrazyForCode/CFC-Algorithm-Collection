// Author: @Reigning
// A 异或 A 是 0，A 异或 0 是 A，那么 A 异或 A 再异或 B 就是 B 咯。  

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for(int i=0;i<numsSize;i++) {
    	result ^= nums[i];
    }
    return result;
}