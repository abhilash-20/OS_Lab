#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 || str[i - 1] == ' '){
            str[i] = toupper(str[i]); 
        }
        i++;
    }

    printf("Modified string: %s\n", str);

    return 0;
}
