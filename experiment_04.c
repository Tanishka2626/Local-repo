 #include <stdio.h>

 int main(){
    double population = 100000.0;
    double rate = 0.10; // 10% = 0.10

    printf("Year\tpopulation\n");
    for (int year = 1; year <= 10;
    year++) {
        population = population * (1 +
        rate);
              printf("%d\t%.0f\n", year,
     population);
    }
    return 0;
 }