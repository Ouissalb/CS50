/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
  
    if ( n < 0 )
    {
        return false;
}  
    for (int i = 0; i < n; i++)
    {
        if ( value == values[i] )
        {
            return true;
} 
}      
            return false;
   
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for ( int i = 0; i < n; i++)
    {
        for ( int j = i+1; j < n; j++) 
        {
            if (values[i] > values[j])
            {
                 int temp = values[i];
                 values[i] = values[j];
                 values[j] = temp;
 
 }
}
} 
 
 
}




