#ifndef _TOKENIZER_
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

  while (*str != '\0' && space_char(*str)) {
            str++;
  }

  // Checks that it is not the end of string
  if (*str != '\0') {
     counter++; // Increment counter

      // Move to the end of the current token
      while (*str != '\0' && !space_char(*str)) {
            str++;
      }
   }
   return counter;
}

/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated
      space-separated tokens from zero-terminated str.

         For example, tokenize("hello world string") would result in:
	      tokens[0] = "hello"
	           tokens[1] = "world"
		        tokens[2] = "string"
			     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

~
