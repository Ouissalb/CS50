#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{  
    string name; 
    name = GetString(); 
    if ( name != NULL ) 
    {   
        // printing the first letter of the first word.
        printf("%c",toupper(name[0]));
        // printing the first letter of the other words                
        for (int i = 0, n = strlen(name); i < n; i++)
        {   
            if (name[i] == ' ') 
            {   
         // printing the first letter      
                printf("%c",toupper(name[i + 1]));
        } 
        }          
        printf("\n"); 
        return 0; 
}
else 
        return 1;                      
}

