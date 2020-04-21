/*
Given an integer number n, 
return the difference between
the product of its digits 
and the sum of its digits.
*/

int subtractProductAndSum(int n){
    int product = 1;
    int sum = 0;
    int element;
    
    while(n){       
        element = n%10;    
        product *= n%10;
        sum += element;
        n = n / 10;
    };
    return (product - sum);
}



