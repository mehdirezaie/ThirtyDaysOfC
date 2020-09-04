/*

Given a sorted array nums, remove the duplicates 
in-place such that each element appear only 
once and return the new length.

Given nums = [1,1,2],
Your function should return length = 2, 
with the first two elements of nums being 1 and 2 respectively.

*/

int removeDuplicates(int* nums, int numsSize){    
    if (numsSize == 0) return 0;

    int i=0, j=0;
    
    while(++j < numsSize){
        if (nums[j] != nums[i]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}

