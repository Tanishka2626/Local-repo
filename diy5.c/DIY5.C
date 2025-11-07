#include <stdio.h>
//function prototype
int sum (int,int);
//fumction defination
int sum (int x, int y){
    printf("the sum is %d\n",x+y);
    return x+y;

}
int main(){
    int a =1;
    int b = 2;
    int c = sum(a,b);

    int a1 =12;
    int b1 = 23;
    sum(a1, b1);
    

    int a2 = 2;
    int b2 = 27;
    sum(a2, b2);
    return 0;
}

