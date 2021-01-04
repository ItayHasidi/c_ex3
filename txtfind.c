#include <stdio.h> 
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]){//TODO fix
    char c = getchar();
    char *sPtr = &s[0];
    int i = 0;
    // while( i < 250 ){
        for (int j = 0; j < 256; j++)
        {    
            if((c > 31 && c < 127) || c == 9 || c == 10){
                *(sPtr + i) = c;
                i++;
            }
        c = getchar();
    }
    *(sPtr + i) = '\0';
    // puts(s);
    return strlen(s);
}


int getword(char w[]){
    char c = getchar();
    char *wPtr = &w[0];
    int count=0;
    for (int i = 0; i < WORD && c != 32 && c != 10 && c != 9; i++)
    {
        if((c > 32 && c < 127)){
            // w[count] = c;
            *(wPtr + count) = c;
            count++;
        }
        c = getchar();
        
    }
    *(wPtr + count) = '\0';
    // puts(w);
    return count;


}

int substring(char *str1, char *str2){//TODO check if correct
    int len2 = strlen(str2), len1 = strlen(str1);
    int count = 0;
    for (int i = 0; i < len1; i++){
        if (*(str1+i) == *(str2+count)){
            count++;
            if(count == len2){
                return 1;
            }
        }
        else{
            count = 0;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n){//TODO check if correct
    int lenS = strlen(s), lenT = strlen(t);
    //printf("word: %s, t: %d, s: %d, n: %d\n",s,lenT, lenS,n);
    if(lenS < lenT || lenS > lenT+n){
        return 0;
    }
    int countChar = 0, j = 0;
    for (int i = 0; i < lenS && j < lenT && countChar <= n; i++){
        if(*(s+i) == *(t+j)){
            j++;
            // flag = 1;
            // if(j == lenT)
        }
        else{
            countChar++;
        }
    }
    if(countChar <= n){
        return 1;
    }
    return 0;
}

void print_lines(char *str , char *w){
    char line[LINE]={0};
    int len = strlen(str);
    // char *linePtr = &line[0];
    // char c=0;
    // c = *(str);
    int count=0, type;
    for (int j = 0; j < len; j++)
    {
        if(*(str + j) != 10){
            *(line + count) = *(str + j);
            count++;
        }
        else if (*(str + j) == 10)
        {
            count = 0;
            type = substring(line, w);
            if(type){
                printf("%s\n",line);
                
            }
            bzero(line, LINE);
        }
    }
}

void print_similar_words(char *str, char *w){
    char word[WORD]={0};
    int len = strlen(str);
    // char c=0;
    // c = *(str);
    int count=0, type;
    // printf("before for: len: %d\n",len);
    for (int j = 0; j < len; j++)
    {
        if(*(str + j)!=10 || *(str + j)!=9 || *(str + j)!=32 || *(str + j)!=3){
            *(word + count) = *(str + j);
            count++;
        }
        
        if (*(str + j)==10 || *(str + j)==9 || *(str + j)==32)
        {
             *(word + count-1) = '\0';
            count = 0;
            type = similar(word , w , 1);
            
            if(type){
                printf("%s\n",word);
                
            }
            bzero(word, WORD);
        }
        // char arr[1];
        //     arr[0]=c;
        // strcat (&c,arr);
        // c = *(str+j);
        // count++;
    }
}

int main(){
    char word[WORD];
    getword(word);
    // printf("the word: %s\n",word);
    char f[1];
    getword(f);
    char stam[1];
    getword(stam);
    // printf("the function: %s\n",f);
    char string[LINE] = {0};
    getLine(string);
    //printf("the string: %s\n",string);
    if (f[0]=='a')
    {
    	// printf("in a\n");
        print_lines(&string[0] , &word[0]);
    }
    else if (f[0]=='b')
    {
        // printf("in b\n");
        print_similar_words(&string[0] , &word[0]);
    }
   return 0;
    
}
