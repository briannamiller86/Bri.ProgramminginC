#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void caesarCipher(const char* text, int shift, char* cipher) {
    int i;
    shift = shift % 26;  // Normalize large shifts
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            cipher[i] = (ch - base + shift + 26) % 26 + base;
        } else {
            cipher[i] = ch;
        }
    }
    cipher[i] = '\0';
}

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void pigLatinWord(const char* word, char* pigWord) {
    int len = strlen(word);
    int i = 0;

    if (isVowel(word[0])) {
        sprintf(pigWord, "%syay", word);
        return;
    }

    while (word[i] != '\0' && !isVowel(word[i])) {
        i++;
    }

    if (i == 0 || i == len) {
        sprintf(pigWord, "%syay", word);
    } else {
        sprintf(pigWord, "%s%.*syay", &word[i], i, word);
    }
}

void pigLatinSentence(const char* text, char* cipher) {
    char word[100], pigWord[120];
    int i = 0, w = 0;
    cipher[0] = '\0';

    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            word[w++] = text[i];
        } else {
            if (w > 0) {
                word[w] = '\0';
                pigLatinWord(word, pigWord);
                strcat(cipher, pigWord);
                w = 0;
            }
            strncat(cipher, &text[i], 1);
        }
        i++;
    }

    // Handle last word
    if (w > 0) {
        word[w] = '\0';
        pigLatinWord(word, pigWord);
        strcat(cipher, pigWord);
    }
}

int main() {
    char text[MAX_LEN];
    char cipher[MAX_LEN * 2];  // Pig Latin may grow the string
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline

    printf("Enter shift: ");
    scanf("%d", &shift);

    printf("Text: %s\n", text);
    printf("Shift: %d\n", shift);

    if (shift >= 0) {
        caesarCipher(text, shift, cipher);
    } else {
        pigLatinSentence(text, cipher);
    }

    printf("Cipher: %s\n", cipher);
    return 0;
}
