// Read a string, S, and print its integer value; 
// if S cannot be converted to an integer, print Bad String.


#include <iostream>

using namespace std;


int main()
{
    string S;
    cin >> S;
    
    try{
        cout << stoi(S) << endl;
    }
    catch(const invalid_argument& ia){
        cout << "Bad String" << endl;
    }
        
    return 0;
}


