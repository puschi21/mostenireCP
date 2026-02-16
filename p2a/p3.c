#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *text;
    int label;
} WordInfo;


void reconstructString(char *input, char *output){
    char *hashtag, *p = strtok(input, " ");
    WordInfo *list=(WordInfo*) malloc(100*sizeof(WordInfo));
    int n=0, i, j;
    while(p!=NULL){
        hashtag=strchr(p,'#');
        if(hashtag!=NULL){
            list[n].label=atoi(hashtag+1);
            *hashtag='\0';
            list[n].text=p;
            n++;
        }
        p=strtok(NULL, " ");
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(list[i].label>list[j].label || (list[i].label==list[j].label && strlen(list[i].text)> strlen(list[j].text))){
                int aux=list[j].label;
                list[j].label=list[i].label;
                list[i].label=aux;

                char *auxch=list[j].text;
                list[j].text=list[i].text;
                list[i].text=auxch;
            }
        }
    }
    
    output[0]='\0';
    for(i=0;i<n;i++){
        strcat(output, list[i].text);
        strcat(output, " ");
    }
}

int main(){
    char i[]="this#2 is#1 a#3 scrambled#4 sentence#5";
    char out[200];
    reconstructString(i,out);
    printf("%s\n", out);
    return 0;
}