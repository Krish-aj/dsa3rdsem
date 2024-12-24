#include <stdio.h>
#include <string.h>

int checkpattern(const char *str,const char *pat){
    int i=0,j=0;
    while(str[i] !='\0'){
        j=0;
        while(pat[j] !='\0' && str[i+j]==pat[j]){
            j++;
        }
        if(pat[j]=='\0'){
            return i; //returns index
        }
        i++;
    }
    return -1; //not found
}

void findandreplace(char *str,const char *pat,const char *rep ){
    int strlength=strlen(str);
    int patlength=strlen(pat);
    int replength=strlen(rep);

    int index=checkpattern(str,pat);

    while(index != -1){
        for(int i=index+patlength;str[i-1]1='\0';i++){
            str[i+replength-patlength]=str[i];
        }
        for(int i=0;i<replength;i++){
            str[index+i]=rep[i];
        }
        strlength=strlen(str);
        index=checkpattern(str,pat);
    }


}

int main (){
    char mainstring[100],patstring[50],repstring[50];
    printf("enter main string: ");
    scanf("%s",mainstring);
    printf("enter pattern string: ");
    scanf("%s",patstring);
    printf("enter replace string: ");
    scanf("%s",repstring);

    findandreplace(mainstring,patstring,repstring);
    printf("the updated string is: %s",mainstring);
    return 0;
}
