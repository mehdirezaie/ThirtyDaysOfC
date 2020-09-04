

bool isPalindrome(int x){
    long result = 0;
    int y = x;
    
    while (x > 0){
        result = result*10 + x%10;
        x = x/10;
    }
    return result == y;
}



