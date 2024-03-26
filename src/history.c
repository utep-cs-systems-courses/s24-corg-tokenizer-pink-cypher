#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


/* Initialize the linked list to keep the history. */
List* init_history(){
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}


/* Add a history item to the end of the list.
 List* list - the linked list
 char* str - the string to store                                                                                                                                                                       
*/
void add_history(List *list, char *str){
  //to be able to create node with new entry and pointer to the head
  Item *head = list->root;
  Item *newNode = (Item*)malloc(sizeof(Item));
  newNode->next = NULL;
  
  if (head == NULL) {
    list->root = newNode;
    newNode -> counter = 0;  
  }
  
  else {
    while (head -> next != NULL){
      head = head -> next;
    }
    head -> next = newNode;
    newNode-> counter = head -> counter + 1;
  }

  int length = 0;

  while (*str != '\0') {
    length++;
    str++;
  }

  str = str - length;
  char *histString = copy_str(str,length);
  newNode->str = histString;

}

/* Retrieve the string stored in the node where Item->id == id.                                                                                                                                         
List* list - the linked list
int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *head = list->root;

  if (head == NULL) {
    return "There is no history at the moment!";
  }
  
  while (head != NULL) {
    if (head->id == id){
      return head->str;
    }
    head = head->next;
  }
  return "Error. Try again.";
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *head = list->root;

  while (head != NULL) {
    printf("You entered:%d %s\n", head->id, head->str);
    head = head->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *head;

  while (list->root != NULL) {
    head = list->root;
    list->root = list->root->next;
    free(head->str);
    free(head);
  }
  free(list);
}

