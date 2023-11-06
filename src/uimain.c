#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char* histo;
  char** toks;
  List* hist = init_history();
  puts("Welcome!");

  while(1){
    
    fputs("Insert string or q to quit or h for history or ! for a specific history\n>", stdout);
    fflush(stdout);
    char k[500];
    fgets(k, 500, stdin);
    //fputs(k, stdout);
    fflush(stdout);
      
    k[strcspn(k, "\n")] = '\0';
    //printf(k);

    toks = tokenize(k);
    print_tokens(toks);
    free_tokens(toks);
     
    switch(k[0]){
      case 'q':
	printf("Bye!\n");
	return 0;
      case 'h':
	print_history(hist);
	break;
      case '!':
	histo = get_history(hist, atoi(k + 1));
	if(histo != NULL){
	  toks = tokenize(histo);
	  printf("History %s\n", histo);
	  printf("Tokenized hist: \n");
	  print_tokens(toks);
	    
	}
	else{
	  printf("Invalid history index \n");
	}
	break;
    default:
      add_history(hist, k);
      
    }
    
  }
  // free_tokens(toks);
  free_history(hist);
  return 0;
}
