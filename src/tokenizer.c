#include <stdio.h>
#include <stdlib.h>
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer                                                                                                                                                    
   ('\t' or ' ').                                                                                                                                                                                          
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return c == '\t' || c == ' ';
}

/* Return true (non-zero) if c is a non-whitespace                                                                                                                                                         
   character (not tab or space).                                                                                                                                                                           
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  return c != '\0' && !space_char(c);
}

/* Returns a pointer to the first character of the next
      space-separated token in zero-terminated str.  Return a zero pointer if
      str does not contain any tokens. */
char *token_start(char *str){
  while (*str != '\0' && space_char(*str)) {
        str++;
  }
  if (*str == '\0') {
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
    while (*token != '\0' && !space_char(*token)) {
        token++;
    }
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int counter = 0;
  char *token = token_start(str); // puts pointer in the first token
  
  while (token != NULL) {
    counter++; 
    
    // moves to next token
    token = token_terminator(token); // moves to end of current token
    token = token_start(token); // puts pointer to next token
  }
  
  return counter;
}


/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
   // allocates a place in memory with num of char from the original string + 1
  char *string1 = (char *)malloc((len + 1));

    // copies all the chars from inStr to string1
    for (int i = 0; i < len; i++) {
        string1[i] = inStr[i];
    }

    //  marks the end of the string
    string1[len] = '\0';

    return string1;

}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
      space-separated tokens from zero-terminated str.

         For example, tokenize("hello world string") would result in:
	      tokens[0] = "hello"
	           tokens[1] = "world"
		        tokens[2] = "string"
			     tokens[3] = 0
*/
char **tokenize(char *str) {
    // # of tokens
    int num_tokens = count_tokens(str);

    // allocates memory for the array of tokens
    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));

    int i = 0;
    // iterates through input string to extract tokens
    while (*str != '\0') {
        // get start and terminator of current token
        char *start = token_start(str);
        char *terminator = token_terminator(start);
        
        // allocates memory for token string
        tokens[i] = (char *)malloc(terminator - start);
	
        str = terminator; //  next token
        i++;
    }
    
    tokens[num_tokens] = NULL; // Null = terminate the array of tokens
    return tokens;
}
      

/* Prints all tokens and teminates when empty */
void print_tokens(char **tokens){
   for (int i = 0; tokens[i] != NULL; i++) {
    printf("%s ", tokens[i]);
    }
}
/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {
    // iterates array of tokens and frees them
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    //uses the free funtion that frees the array of tokens
    free(tokens);
}
