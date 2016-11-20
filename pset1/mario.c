/**
 * mario.c
 *
 * Ouissal Benameur
 * ouissalbenameur@yahoo.com
 *
 * mario pyramid.
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int line; 
    int height; 
    int position; 
    printf("Write a positive integer non greater than 23\n");
    height = GetInt();

    while (height > 23 || height < 0) 
    {
        printf("Write a positive integer non greater than 23\n");
        height = GetInt();
}
    /*This will generate the Mario pyramid*/
    for (line = 2; line <= (height + 1); line++)
    {
        for (position = 0; position <= height; position++)
        {
            if (position >= height + 1 - line)
            {
                printf("#");
} 
             else
            {
            // print a space
                printf(" ");
}                 
              
} 
        printf("\n");
                }}
         
