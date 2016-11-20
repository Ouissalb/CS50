/* Welcome to the greedy program
 *
 * BY : Ouissal Benameur
 *
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{       
    int quar = 0;
    int penn = 0;
    int dim = 0;
    int nick = 0;
    float cash;
    int cents;
    float quarter = 25;
    float dime = 10;
    float nickel = 5;
    float penny = 1;
    printf("Enter an amount of cash : ");
    cash = GetFloat();
    /*When the value entred is negative*/
    while (cash <= 0)
    {
        printf("Enter an amount of cash : ");
        cash = GetFloat();    
}
    cents = round(cash * 100);
    /* for quarters */  
    while (quarter <= cents )
    {
        quar++;
        cents = cents - quarter;       
}   
    /* for dimes */     
    while (dime <= cents )
    {
        dim++;
        cents = cents - dime ;    
}   
    /* for nickels */ 
    while (nickel <= cents )
    {
        nick++;
        cents = cents - nickel;
}    
    /* for pennies */  
    while (penny <= cents )
    {
        penn++;
        cents = cents - penny;
}    
    printf("%d\n",nick + quar + penn + dim);
    







}
