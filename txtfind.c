#include <stdio.h>
#include <string.h>

#define LINE 256 // maximum length of the input line
#define WORD 30

// getline: read a line into s, return length
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

// getword: read a word into w, return length
int getword(char w[])
{
    int ch, i = 0;

    while ( i < WORD - 1 && (ch = getchar()) != EOF && ch != ' ' && ch != '\t' && ch != '\n'){
        w[i] = ch;
        i++;
    }
        
    // Handle empty line
    if (ch == '\n' && i == 0)
        w[i++] = ch;
    w[i] = '\0';
    return i;
}

// substring: return 1 if str1 is a substring of str2, 0 otherwise
int substring(char *str1, char *str2){

    if(strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
}

// similar: return 1 if it is possible to get t from s by removing at most n characters, 0 otherwise
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
// print_lines: print all the lines that contain the string str
void print_lines(char *str)
{
    char temp_line[LINE]; // character array to hold the input temp_line

    while (get_line(temp_line) > 0)
    {
        if (substring(str, temp_line)){
            printf("%s", temp_line); // print the temp_line if it contains str
        }
    }
}

void print_similar_words(char *str) {
    char temp_word[WORD]; // to store the words read from the input
    while (getword(temp_word) > 0) { // read a temp_word from the input
        if (similar(temp_word, str, 1)) { // check if temp is similar to str
            printf("%s\n", temp_word); // print temp_word if it is similar to temp
        }
    }
}

int main() {
    char word[WORD];
    //choice for the users choise and l for the blank line '\n'
    char choice,l;
    //Gets the user choose
    scanf("%s %choice%choice", word, &choice, &l);


    if (choice == 'a') {
        print_lines(word);
    } else if (choice == 'b') {
        print_similar_words(word);
    } else {
        printf("choose a or b");
    }

    return 0;
}

