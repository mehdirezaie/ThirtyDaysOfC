/*
    
    Code to compute the Legendre functions

*/
#include<stdio.h>
#include<math.h>
 
double P0(double x){
    return 1;
}
 
double P1(double x){
    return x;
}
//The following is a general functoin that returns the value of the Legendre Polynomial for any given x and n=0,1,2,3,...
double Pn(double x, int n){
    if(n==0){
        return P0(x);
    }else if(n==1){
        return P1(x);
    }else{
        return (double)((2*n-1)*x*Pn(x,n-1)-(n-1)*Pn(x,n-2))/n;
    }
}
int main(){
    //We will create a data-file and store the values of first few Legendre polynomials for -1<x<1
    FILE *fp=NULL;
    //create data-file
    fp=fopen("legendre1.txt","w");
    double x;
    //write the values of first 5 Legendre polynomials to data-file
    for(x=-1;x<=1;x=x+0.1){
        fprintf(fp,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",x,Pn(x,0),Pn(x,1),Pn(x,2),Pn(x,3),Pn(x,4));
    }
    return 0;
}
