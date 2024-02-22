#include <stdio.h>
#include "tokenizer.h"

int main() 
{
  puts("Welcome to Isabella's Tokenizer!");

  while (1) { // Infinite while loop

    fputs("Please input a sentence, 'h' to see your history or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, as long as it is one of the options, it will call the function
    if (c == 'h'){
      //return history
    }
    else if (c == 'q'){
      puts("Bye!");
      goto done; 		/* terminate */
    }
    else{
      //tokenize the sentence input

    }

 done: // To exit from program
  return 0;
}
