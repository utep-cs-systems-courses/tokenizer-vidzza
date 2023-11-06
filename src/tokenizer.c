#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  return (c== ' ' || c== '\t');
}

int non_space_char(char c){
  return (c == '\0') ? 0 : !space_char(c);
}

char *token_start(char *str){
  if(non_space_char(*str)){
    return str;
  }else if(space_char(*str)) {
    return token_start(++str);
  }else{
    return NULL;
  }
}

char *token_terminator(char *token){
  if(non_space_char(*token)){
    return token_terminator(token + 1);
  }else{
    return token;
  }
}

int count_tokens(char *str){
  if(token_start(str) == NULL){
    return 0;
  }else{
    return 1 + count_tokens(token_terminator(token_start(str)));
  }
}

char *copy_str(char *inStr, short len){
  //char *nwStr= calloc();
  //nwStr = inStr(len)
    //return nwStr

  char *nwStr = calloc(len + 1, sizeof(char));
  for(int i = 0; i < len; i++){
    nwStr[i] = inStr[i];
    if(nwStr[i] == '\0'){
      return nwStr;
    }
  }
  return nwStr;
}

char **tokenize(char *str){
  int word_length = count_tokens(str); // takes the length of how many words are in a string as a number
  char **word = calloc((word_length + 1) * sizeof(char*), 1); // taking unused memory and allocs as used memory and return the first add of that memory
  for(int i = 0; i < word_length; i++){
    char* start = token_start(str);
    str = token_terminator(start);
    word[i] = copy_str(start, str - start);
    if(word[i] == NULL){
      return word;
    }
  }
  return word;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
