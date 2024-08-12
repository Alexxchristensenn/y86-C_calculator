#include <stdio.h>

/*
Alex Christensen
4.18.2024
Recursive Program
Includes a function which multiplies two numbers
using addition, and a recursive function which utilizes
the multiplication function. 
*/

int ab(int n){
    if (n < 0)      //If negative, 'negate' to make positive
        return -n;
    else
        return n;   //If positive, return as is
}

int mult(int x, int y){

    int i = 0;
    int ret = 0;

    while(y-i > 0){  //For i to y, add x to return value
        ret+=x;
        i++;
    }
    return ret;
}

int rf(int n){
    if (n==0)
        return 1;
    
    if (n==1)
        return 2;
    
    return mult(rf(n-1), rf(n-2));
}

int main(){
    int input[] = {-6, 4, 5, -7, 8, 0};
    int *index = input;
    int x;
    int absx;
    int num;

    x = *index;

    while (x!=0){
        printf("%8d   0x%08x\n", x, x);

        absx = ab(x); //Store the absolute value of the current number

        if ((x & 1) == 0)           //If even, call rf
            num = rf(absx);
        else                        //Otherwise if odd call mult
            num = mult(absx, absx);

        printf("%8d   0x%08x\n", num, num);

        index++;                   //Retreives next item in array
        x = *index;
    }

}