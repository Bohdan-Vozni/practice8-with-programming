#include <stdio.h>
#include <string.h>

int main() {
    char string[20]; 
    int result[256] = { 0 }; 
    printf("Input string: ");
    fgets(string, sizeof(string), stdin);
    int size_array = strlen(string);

    if (size_array > 19) {
        printf("Error, character limit exceeded");
        return 13;
    }

    
    if (string[size_array - 1] == '\n') {
        string[size_array - 1] = '\0';
        size_array--;
    }

  
    for (int i = 0; i < size_array; i++) {
        result[(unsigned char)string[i]]++;
    }

    
    printf("\nRepeating characters and their number:");
    int denominator=1;
    
    for (int i = 0; i < 256; i++) {
        if (result[i] > 1) {
            printf("\nThe character '%c' is repeated %d times", i, result[i]);
            int integral = 1;

            for (int j = 1; j <= result[i]; j++) {
                integral *= j;
            }
            denominator*=integral;

            printf("\nintegral %d", integral);
        }
    }
   
    printf("\ndenominator %d", denominator);
    int numerical = 1;
    for (int j = 1; j <= size_array; j++) {
        numerical *= j;
    }
    float res = numerical / denominator;
    printf("\n number of possible anagrams %.0f", res);
    return 0;
}
