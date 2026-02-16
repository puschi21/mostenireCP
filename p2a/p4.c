#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    char text[256];
    int openTag, closeTag;
}html;


void writeHeadings(char *input, int dig){
    FILE *fp=fopen(input, "r");
    if (!fp) 
        return;
    html v;
    int c;
    while(((c=fgetc(fp))!=EOF)){
        if(c=='<'){
            if(fscanf(fp, "h%d>", &v.openTag)==1){
                int i=0;
                while(((c=fgetc(fp))!=EOF) && c!='<'){
                    if(c=='\n' || c=='\r'){
                        v.text[i]=' ';
                        i++;
                    }
                    else if(!isspace(c)){
                        v.text[i]=(char)c;
                        i++;
                    }
                }
                v.text[i] = '\0';
                if(fscanf(fp, "/h%d>", &v.closeTag))
                    if(v.closeTag==v.openTag && v.closeTag==dig)
                        printf("%s\n", v.text);
            }
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Error");
        return 0;
    }
    int digit=atoi(argv[2]);
    if(digit<1 || digit>6){
        printf("Error");
        return 0;
    }
    writeHeadings(argv[1],digit);
    return 0;
}