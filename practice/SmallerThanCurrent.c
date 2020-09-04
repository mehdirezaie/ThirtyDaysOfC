/*
 * Smaller than Current
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    
    // initialize
    *returnSize = numsSize;
    int* ptr = (int *) malloc(101 *sizeof(int));    
    for (int j; j < 101; j++){
        ptr[j] = 0;
    }
    
    // binning
    for (int i; i<numsSize; i++){
        int j = nums[i];
        ptr[j] += 1;
    }
    
    int previous=0;
    for (int j; j < 101; j++){
        if (ptr[j] !=0){
            int value=ptr[j];
            ptr[j] = previous;
            previous +=value;
        }
    }
    
    
    int* result = (int *) malloc(numsSize * sizeof(int));
    for (int i; i<numsSize; i++){
        int index = nums[i];                
        result[i] = ptr[index];
    }
    return result;
}



