#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int get_line(char s[]) {
    int c, i;
    for (i = 0; i < LINE-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int getword(char w[]) {
    int c, i;
    for (i = 0; i < WORD-1 && (c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' '; i++) {
        w[i] = c;
    }
    w[i] = '\0';
    return i;
}

int substring(char * str1, char * str2) {
    int i, j;
    for (i = 0; i < strlen(str1); i++) {
        if (str1[i] == str2[0]) {
            for (j = 0; j < strlen(str2); j++) {
                if (str1[i+j] != str2[j]) {
                    break;
                }
            }
            if (j == strlen(str2)) {
                return 1;
            }
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    if (strlen(s) != strlen(t)) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != t[i]) {
            count++;
        }
        if (count > n) {
            return 0;
        }
    }
    return 1;
}

void print_lines(char *str) {
    char line[LINE];
    while (get_line(line)) {
        if (substring(line, str)) {
            printf("%s", line);
        }
    }
}

void print_similar_words(char *str) {
    char word[WORD];
    while (getword(word)) {
        if (similar(word, str, 1)) {
            printf("%s\n", word);
        }
    }
}

int main() {
    char option, str[WORD];
    scanf("%c %s", &option, str);
    if (option == 'a') {
        print_lines(str);
    } else if (option == 'b') {
        print_similar_words(str);
    }
    return 0;
}