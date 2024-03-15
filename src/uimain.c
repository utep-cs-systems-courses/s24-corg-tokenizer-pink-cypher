#include <stdio.h>
#include "tokenizer.h"

int main() {
    puts("Welcome to Isabella's Tokenizer!");

    while (1) { // Infinite while loop
        fputs("Please input a sentence, 'h' to see your history or 'q' to quit\n> ", stdout);
        fflush(stdout);             /* stdout only flushes automatically on \n */
        int c = getchar();
	
        while (getchar() != '\n'); /* ignore newlines */

        if (c == EOF)                    /* terminate on end-of-file */
            break;

        // Given the user answer, as long as it is one of the options, it will call the function
        else if (c == 'h'){
	  puts("Functionality for viewing history will be implemented here.");
            //return history
        }
        else if (c == 'q'){
            puts("Bye!");
            break;                /* terminate */
        }
        else{
            char sentence[100]; // Assuming maximum sentence length is 100 characters
	    fputs("Please input a sentence: ", stdout);
	    fflush(stdout);
            fgets(sentence, sizeof(sentence), stdin); // Read user input
            char **tokens = tokenize(sentence); // Tokenize the sentence
            print_tokens(tokens); // Print the tokens
            free_tokens(tokens); // Free memory allocated for tokens

        }
    }

    // To exit from program
    return 0;
}
