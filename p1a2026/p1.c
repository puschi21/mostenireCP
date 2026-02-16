#include <stdio.h>
#include <string.h>
 
char* switchNumbers(char *buffer, int buffersize, int v[], int nr){
    char temp[buffersize];
    int i=0, j=0, currentNr=0;
    while(buffer[i]!='\0'){
        if(buffer[i]=='%' && buffer[i+1]=='d' && currentNr<nr){
            j=j+snprintf(&temp[j],buffersize-j,"%d",v[currentNr]);
            i+=2;
            currentNr++;
        }
        else{
            temp[j]=buffer[i];
            j++;
            i++;
        }
    }
    temp[j]='\0';
    strncpy(buffer,temp,buffersize);
    return buffer;
}

int main(){
    char s[90] = "x=%d; y=%d; z=%d";
    int v[] = {10, -3};
    printf("%s\n",switchNumbers(s,90,v,2));
}