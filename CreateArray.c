/**
 * Note: The returned array must be malloced, assume caller calls free().
 *Given two arrays of integers nums and index. 
 Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], 
insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    
    *returnSize = numsSize;
    
    int* ptr = (int*) malloc(*returnSize * sizeof(int));
    
    if (ptr == NULL){
        printf("could not allocate");
        exit(1);
    }
    
    for (int i; i<numsSize; i++){
        ptr[i] = NULL;
    }

    for (int i; i<numsSize; i++){
        
        int index_i = index[i];
        
        if (ptr[index_i] == NULL){
            ptr[index_i] = nums[i];
        }else{
            for (int j=numsSize-1; j>index_i; j--){
                ptr[j] = ptr[j-1];
            }
            ptr[index_i] = nums[i];
        }
    }    
    return ptr;
}
