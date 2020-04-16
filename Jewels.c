/*
You're given strings J representing the types 
of stones that are jewels, and S representing 
the stones you have.  Each character in S is a 
type of stone you have.  You want to know how 
many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and
all characters in J and S are letters.
Letters are case sensitive, so "a" is considered
a different type of stone from "A".

*/
int numJewelsInStones(char * J, char * S){
    int length_J = strlen(J);
    int length_S = strlen(S);    
    int counter = 0;
    
    for (int i=0; i<length_J; i++){
        
        for (int j=0; j<length_S; j++){
            
            if (J[i] == S[j]){
                counter++;
            }
        }
    }
    return counter;

}



