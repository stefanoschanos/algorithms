#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) 
{
    stack_type stack1,stack2;
    stack_element_type item1,item2;
    int n=0, i=0, y=0,z=0;
    char string[n];

    printf("Give the string : \n");
    scanf("%s" , string);

    //String length calculation
    y=strlen(string); 


    initialize(&stack1);
    initialize(&stack2);

    for(i=0; i<y; i++)
    {
        push (&stack1 , string[i]);
    }

    for(i=0; i<y/2; i++)
    {
        if(!is_empty(stack1))
        {
            pop (&stack1 , &item1);
            push (&stack2 , item1);
        }
    }

    display (stack1);
    display (stack2);

    //If the word has even number of letters  we extract the letter thats in the middle of the word , so we can compare the letters beside it 
    if (y%2!=0)
        pop (&stack1 , &item1);

    for(i=0; i<y/2; i++)
    {
        if(!is_empty(stack1))
        {
            pop (&stack1 , &item1);
            pop (&stack2 , &item2);

            //Every time that a letter from the first pile is the same with a letter from the second pile , z increases by one
            if(item1==item2)
                z=++z;
        }
    }

    //If z is the same with the number of comparisons then the word is reciprocating
    if(z==y/2)
        printf("\n The word is reciprocating ");
    else
        printf("\n The word isn't reciprocating");




    return 0;
}
