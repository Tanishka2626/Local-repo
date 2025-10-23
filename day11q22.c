//Write  program to find profit or loss percentage given cost price and selling price.
#include <stdio.h>
int main(){
    float cp, sp;
    printf("Enter cost price and selling price: ");
    scanf("%f %f", &cp, &sp);
    if(sp > cp)
    printf("Profit = %.2f%%", ((sp-cp)/cp * 100)); //%.2f%% double%% to print actual % sign
    else if (sp < cp)
    printf("Loss = %.2f%%", ((cp-sp)) / cp * 100);
    else 
        printf("No profit, no loss");
        return 0;

}