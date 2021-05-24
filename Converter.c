#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
typedef unsigned short int boolean;
struct list_linked{
    char value;
    struct list_linked * next_ptr;
};
void init(struct list_linked ** ptrptr);
boolean visit(struct list_linked ** ptrptr);
boolean suf_insert(struct list_linked ** ptrptr, char value);
boolean founder(struct list_linked ** ptrptr);

void init(struct list_linked ** ptrptr){
    *ptrptr = NULL;
};

boolean visit(struct list_linked ** ptrptr){
    boolean esit;
    if(*ptrptr == NULL){
        esit = false;
        printf("empity");
    }
    while( *ptrptr != NULL ){
        printf("%c",(*ptrptr)->value);
        ptrptr = &(*ptrptr)->next_ptr;
    }
    esit = true;
    return esit;
};

boolean suf_insert(struct list_linked ** ptrptr, char value){
    struct list_linked * tmp;
    tmp = (struct list_linked*)malloc(sizeof(struct list_linked)*1);
    boolean esit;
    /*if(*ptrptr == NULL){
        esit = false;
        printf("empity");
    }*/
    while(*ptrptr != NULL){
        ptrptr=&(*ptrptr)->next_ptr;
    }
    *ptrptr = tmp;
    tmp->value = value;
    tmp->next_ptr = NULL;
}

boolean founder(struct list_linked ** ptrptr){

    char V[10][5] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    char * convert;
    convert = (char*)malloc(sizeof(char)*10);
    convert = "0123456789";
    int ref;
  
    boolean esit;
    if(*ptrptr == NULL){
        esit = false;
        printf("empity");
    }

 
while((*ptrptr) != NULL ){
        for(int i =0; i < 10; i++){
            if( (*ptrptr)->value == convert[i] ){
                (*ptrptr)->value = V[i][0];
                    for(int j=1; j<5; j++){
                            struct list_linked * tmp;
                            tmp = (struct list_linked*)malloc(sizeof(struct list_linked)*1); 
                            tmp->value = V[i][j];
                            tmp->next_ptr = (*ptrptr)->next_ptr;
                            (*ptrptr)->next_ptr = tmp;
                            ptrptr = &(*ptrptr)->next_ptr;
                    }   
            }
        }
    ptrptr = &(*ptrptr)->next_ptr;
}


}



/*---------------------MAIN------------------------------*/
int main() {
struct list_linked * B;
init(&B);
int i;
int counter;

char * input;
input = (char*)malloc(sizeof(char)*200);
printf("\ninserisci una stringa di testo:");
//scanf("\n %s",&(*input)); Ricorda di usare fgets con la libreria string.h per poter immettere una stringa con spazi
fgets(&(*input),200,stdin);

for(i=0; i<200; i++){
    suf_insert(&B,input[i]);
}

founder(&B);

printf("\n");
visit(&B);
printf("\n");
return 0;
} 
