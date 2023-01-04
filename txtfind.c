#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256

int getWord(char s[]);
int get_Line(char s[]);
int substring( char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

int main(){
    char word[WORD];
    char choice;
    char l;
    scanf("%s %c %c",word, &choice, &l);

    switch (choice) {
        case 'a':
            print_lines(word);
            break;
        case 'b':
            print_similar_words(word);
            break;
        default:
            printf("Choose a or b");
            break;
    }
    return 0;
}

int get_Line(char s[]) {
    int numOfChars = 0;
    int ch = 0;
    while ((ch != '\n') && (ch != '\r')  && (numOfChars < LINE - 1)) {
        if ((ch = getchar()) != EOF){
            if (ch != '\r'){
                s[numOfChars] = (char) ch;
            }
            else{
                s[numOfChars] = '\n';
            }
        }
        else{
            return 0;
        }
    numOfChars++;
    }
    if (numOfChars == 0){
        return 1;
    }
    s[numOfChars] = '\0';
    return numOfChars;
}

int getWord(char s[]) {
    int numOfChars = 0;
    int ch;
    while (((ch = getchar()) != '\n') && (ch != '\t') && (ch != '\r') && (ch != ' ') && (ch != EOF)) {
        s[numOfChars++] = (char) ch;
    }
    s[numOfChars] = '\0';
    return numOfChars;
}

int substring( char *str1, char *str2) {
    if(strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
}

int similar(char *s, char *t, int n){
    //identical strings and zero letters to omit.
    if (strcmp(s, t) == 0 && n == 0) {
        return 1;
    }
    //If these conditions are true it can't be similar.
    if (strlen(s) < strlen(t) || strlen(t) + n < strlen(s)){
        return 0;
    }
    int i = 0, j = 0;
    while (i < strlen(s) && j < strlen(t))
    {
        if (s[i] != t[j]) {
            n--;
            if(n < 0){
                return 0;
            }
        }
        else{
            j++;
        }
        i++;
    }
    return 1;
}

void print_lines(char *str){
    char temp_line[LINE];
    while(get_Line(temp_line) > 0){
        if(substring(str, temp_line)){
            printf("%s", temp_line);
        }
    }
}

void print_similar_words(char *str){
    char temp_word[WORD];
    while (getWord(temp_word) > 0){
        if (similar(temp_word, str, 1)){
            printf("%s\n", temp_word);
        }
    }
}
