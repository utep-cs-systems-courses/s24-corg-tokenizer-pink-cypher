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
        fputs("Please input 's' to enter a sentence, 'h' to see your full history, 'i' to see a specific history, or 'q' to quit\n> ", stdout);
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

	case 'i':
	  fputs("Please enter the id of the history you would like to see: ", stdout);
	  fflush(stdout);
	  int id_value;
	  scanf("%d", &id_value);
	  printf("History:%d %s\n", id_value, get_history(history, id_value));
	  break;
	  
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
