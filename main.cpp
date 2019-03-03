#include <iostream>

void printBinary(int n, char format = 1);
void RemoveDups(char *pStr);

int main() {
    /* Chapter 1 */
    printBinary(137);

    /* Chapter 2 */
    char str[80] = "AAA BBB AAA CKKK";
    RemoveDups(str);
    printf("%s\n", str);
    return 0;
}

void printBinary(int n, char format)
{
    /* Main part */
    int num_of_bits = sizeof(n)*8;//calculate int size for different systems
    char result[num_of_bits + 1];
    result[num_of_bits] = '\0';
    for(int i = num_of_bits - 1;i >= 0; i--)
    {
        result[i] = (n & 1) ? '1' : '0';
        n = n>>1;
    }

    /* Optional part. Just delete or not insignificant zeros */
    if(!format) printf("%s\n", result);
    else {
        int i = 0;
        while(result[i] == '0') i++;
        for( ;i < num_of_bits; i++) printf("%c", result[i]);
        printf("\n");
    }
}

void RemoveDups(char *pStr)
{
    char skip = pStr[0];
    int i = 0, j = 0;
    while(pStr[i + j] != '\0')
    {
        if(pStr[i + j] == skip) j++;
        else {
            skip = pStr[i + j];
            i++;
            pStr[i] = skip;
        }
    }
    pStr[++i] = '\0';
}