#include <stdio.h>
#include <string.h>

#define LINE 256 // maximum line
#define WORD 30 // maximum word

int get_line(char s[]){
    int i = 0,ch = 0;

    while ( i < LINE - 1 && ch != '\n' && ch != '\r'){
        if((ch = getchar()) != EOF) {
            if (ch != '\r') {
                s[i] = ch;
            } else {
                s[i] = '\n';
            }
        }
        else {
            return 0;
        }
        i++;
    }
    
    if (i==0){
        return 1;
    }
    
    s[i] = '\0';
    return i;
}

int getword(char w[])
{
    int ch, i = 0;

    while ( i < WORD - 1 && (ch = getchar()) != EOF && ch != ' ' && ch != '\t' && ch != '\n'){
        w[i] = ch;
        i++;
    }
        
    // if ther's empty line
    if (ch == '\n' && i == 0)
        w[i++] = ch;
    w[i] = '\0';
    return i;
}

int substring(char *str1, char *str2){

   for (int i = 0; i < strlen(str2) - strlen(str1) + 1; i++){
        // compare the characters
        if (strncmp(str1, str2 + i, strlen(str1)) == 0){
            return 1; 
        }
    }
    return 0;
}

int similar(char *s, char *t, int n){
    
    if (strcmp(s, t) == 0 && n == 0) {
        return 1;
    }
    //If these conditions are true it can't be similar.
    if (strlen(s) < strlen(t) || strlen(t) + n < strlen(s)){
        return 0;
    }
    int i = 0, j = 0;
    while (i < strlen(s)) {
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

void print_lines(char *str)
{
    char temp_line[LINE];

    while (get_line(temp_line) > 0)
    {
        if (substring(str, temp_line)){
            printf("%s", temp_line);
        }
    }
}

void print_similar_words(char *str) {
    char temp_word[WORD]; // store the words from input
    while (getword(temp_word) > 0) { // read temp_word from input
        if (similar(temp_word, str, 1)) { // check if temp is similar to str
            printf("%s\n", temp_word); // print temp_word if it is similar to temp
        }
    }
}

int main() {
    char word[WORD];
    
    char choice,l;
    //Gets the user choose
    scanf(" %s %c %c", word, &choice, &l);
    
    if (choice == 'a') {
        print_lines(word);
    } else if (choice == 'b') {
        print_similar_words(word);
    } else {
        printf("choose a or b");
    }

    return 0;
}

