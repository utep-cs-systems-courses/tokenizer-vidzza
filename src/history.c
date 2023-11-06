#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  return calloc(1, sizeof(List));
}

void add_history(List *list, char *str){
  Item *nh = (Item*)calloc(1, sizeof(Item));
  nh->id = 1;
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  nh->str = copy_str(str, i);

  if(list->root == NULL){
    list->root = nh;
  }
  else{
    Item *temp = list->root;
    while(temp->next != NULL){
    nh->id += 1;
    temp = temp->next;
    }
  temp->next = nh;
  nh->id += 1;
  }
}

char *get_history(List *list, int id){
  Item *find = list->root;
  while(find != NULL){
    if(find->id == id){
      return find->str;
    }
    find = find->next;
  }
  return "Doesn't exist";
}

void print_history(List *list){
  Item *find = list->root;
  if(list == NULL){
    printf("nothing was found/list was empty\n");
    return;
  }
  printf("Item in the list: \n");
  for(int i = 1; find != NULL; i++){
    printf("[%d]%s\n", find->id, find->str);
    find = find->next;
  }
}

void free_history(List *list){
  if(list == NULL){
    printf("Cannot free, list is empty");
    return;
  }
  while(list->root != NULL){
    Item *find = list->root;
    list->root = find->next;
    free(find);
  }
}
