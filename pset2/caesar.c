/* Caesar Algorithm
 * BY OUISSAL BENAMEUR
 * Ouissalbenameur@yahoo.com
 */ 
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checking the number of inputs after the path
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string plaintext;
        plaintext = GetString();
        char p, c;  
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            p = plaintext[i];
            // Checking for alphabets only
            if (isalpha(plaintext[i]))
            {    
                // Checking for upper case letters
                if (isupper(p))
                {
                    c = p - 65;
                    c = (c + key) % 26;
                    c += 65;
                    printf("%c",c);                 
}          
                  // Checking for lower case letters
                else if (islower(p))
                {
                    c = p - 97;
                    c = (c + key) % 26;
                    c += 97;
                    printf("%c", c);
}             
}   
        else
            {
               // In case it's not a letter
                printf("%c", plaintext[i]);
}              
}
        printf("\n"); 
        return 0;
}
else 
    {
        printf("ERROR\n");
        return 1;
}
}

