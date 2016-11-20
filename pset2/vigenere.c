/* Vigenere Algorithm
 * BY OUISSAL BENAMEUR
 *
 */ 
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checking the number of inputs after the path
    if (argc != 2)
    {
        printf("Error!\n");
        return 1;
}
    // Checking if the key entered is composed only by alphabets
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if ( !(isalpha(argv[1][i])))
        {
            printf("ERROR\n");
            return 1;
}
}
    string p = GetString();
    string k = argv[1];
    int shift;
    int KEY;
    for ( int i = 0, j = 0, n = strlen(p); i < n; i++, j++)
    {   
        // making a new lap around the key when reaching the last letter
        if ( j >= strlen(k) )
        {
            j = 0;
}
        KEY = k[j];
        // skip non alphabetical characters
        if ( !(isalpha(p[i])) )
        {
            j--;
}
    
        if ( (KEY <= 'Z') && (KEY >= 'A'))
        {    
            KEY = KEY - 'A';
}
   
        if ( (KEY <= 'z') && (KEY >= 'a'))
        {
            KEY = KEY - 'a';
}
        shift = p[i] + KEY;
        // Le chiffrement des caractere uppcase
        if (isupper(p[i]) && (shift > 'Z'))
        {
            shift = shift - 26;
}   
        // Chiffrement des caractères downcase
        if (islower(p[i]) && (shift > 'z'))
        {
            shift = shift - 26;
} 
        if (isalpha(p[i]))
        {
         // printing ciphered text
            printf("%c", shift);
}
        else 
        {
            // printing non alphabetical characters
            printf("%c", p[i]);
}
}
    printf("\n");
    return 0;
}




