#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

int main() {
    List *history = init_history();
    puts("Welcome to Isabella's Tokenizer!");

    while (1) { // Infinite while loop
        fputs("Please input 's' to enter a sentence, 'h' to see your history or 'q' to quit\n> ", stdout);
        fflush(stdout);/* stdout only flushes automatically on \n */
	int c = getchar();
	getchar();
	
	switch(c){
	  case 's':
	    fputs("Please enter your string: ", stdout);
	    fflush(stdout);
	    char sentence[100];// Assuming maximum sentence length is 100 characters                                                                                                                           
            fgets(sentence, sizeof(sentence), stdin); // Read user input    
	    char **tokens = tokenize(sentence); // Tokenize the sentence     
	    print_tokens(tokens); // Print the tokens
	    free_tokens(tokens);
	    add_history(history, sentence);
	    break;
	    
	  case 'h':
	   // Given the user answer, as long as it is one of the options, it will call the function
	    print_history(history);
	   break; //return history

	case 'q':
	   puts("Bye!");
	   free_history(history);
           break;                /* terminate */
	}
	if (c == 'q'){
	  break;
	}
    }

    // To exit from program
    return 0;
}
