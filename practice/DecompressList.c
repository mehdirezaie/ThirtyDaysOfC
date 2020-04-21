/**
 * Note: The returned array must be malloced, assume caller calls free().
 * We are given a list nums of integers representing a list compressed
 with run-length encoding. Consider each adjacent pair of elements
[freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  
For each such pair, there are freq elements with value val 
concatenated in a sublist. Concatenate all the sublists from 
left to right to generate the decompressed list. Return the decompressed list.
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    
    *returnSize=0; // returning arraySize
    
    // find the size of the output
    for (int i=0; i<numsSize; i+=2){
        *returnSize += nums[i];
    }
    
    // allocate
    int* ptr = (int*) malloc(*returnSize * sizeof(int));    
    if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    
    // build the output array
    int j = 0;
    for (int i=0; i<numsSize; i+=2){
        for (int k=0; k<nums[i]; k++){
            ptr[j] = nums[i+1];
            j++;
        }        
    }      
    return ptr;
}



