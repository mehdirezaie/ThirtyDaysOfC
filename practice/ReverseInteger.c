/*
Given a 32-bit signed integer, 
reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321

Note:
Assume we are dealing with an environment 
which could only store integers within 
the 32-bit signed integer range: [−2**31,  2**31 − 1]. 
For the purpose of this problem, assume that 
your function returns 0 when the reversed integer overflows.
*/

int reverse(int x){
            
    long n = 0;
    long y = x;
    int s = 1;
    if(y<0){
        y = -y;
        s = -1;
    }
    int rem;
    while(y>0){
        rem = y%10;
        n = n*10 + rem;
        if(n>INT32_MAX){
            return 0;
        }
        y /= 10;
    }
    return n*s;
}







