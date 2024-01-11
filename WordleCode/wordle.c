#include "wordle.h"
#include <stdio.h>
#include <string.h>
/**
 * Play the wordle game.
 *
 * key          The answer word. Should be lowercase only.
 * nattempts    The total number of attempts allowed.
 * attempts     An array of string buffers to keep track of each attempt.
 * return       Number of guesses the player took to guess the right word,
 *              return 0 if player failed to guess the word.
 */

 
int wordle(const char *key, int nattempts, char attempts[][WORDBUFSZ])
{
    /*
    * TODO:
    * Implement this function. Feel free to create any
    * helper functions you need. But do NOT change the
    * parameters of this function.
    */
    
    int currAttempt = 0;
    const char *pter = NULL;
    
    char newLine[6] = "_____";
    // printf("Word is: %s\n", key);

    printf("_____\r");
    while(nattempts>0)
    {
        get_input(attempts[currAttempt],strlen(key));

        if(strcmp(attempts[currAttempt],key)==0){
            break;
        }  

        for(int i = 0; i < strlen(key); i++)
        {
            for(int j = 0; j < strlen(key);j++)
            {
                if(key[i] == attempts[currAttempt][j])
                {
                    pter = &key[i];
                }
            }
            if(pter == &key[i])
            {
                newLine[i] = *pter;
            }

        }

        currAttempt++;
        nattempts--;
        if(nattempts == 0)
        {
            break;
        }
        
        for(int i = 0; i < strlen(key);i++)
        {
            printf("%c", newLine[i]);
        }
        
        printf("\r");
    }

    if(nattempts == 0)
    {
        return nattempts;
    }
    else
    {
        return currAttempt+1;
    }

}
