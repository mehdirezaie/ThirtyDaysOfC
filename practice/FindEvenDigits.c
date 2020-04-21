/*
    Given an array nums of integers, return how many of them 
    contain an even number of digits
    
    approach 1: find the number of digits
    approach 2: int to str, find the len of str

*/
int findNumbers(int* nums, int numsSize){
    
    // find number of digits
    int n_even = 0;
    for (int i; i<numsSize; i++){
        int num_i = nums[i];
                
        int count = 0;
        while (num_i){
            num_i /= 10;
            count++;                
        }        
        //ptr[i] = count;
        if ((count & 1) == 0)
            n_even++;
        
        /*
        char str[100000];
        sprintf(str, "%d", nums[i]);
        if ((strlen(str) & 1) == 0)
            n_even++;
        */
    }
       
    return n_even;
}



