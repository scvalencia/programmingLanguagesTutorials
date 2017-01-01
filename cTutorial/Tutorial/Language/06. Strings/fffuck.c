# include <stdio.h>
# include <string.h>
# define N 100
int main(void) {
    char name[N];
    char sign;
    int var = -1;
    for(int i = 0; i < N; i++) name[i] = ' ';
    printf("Enter a sentence: ");
    for(int j = 0; j < N; j++) {
        scanf("%c", &name[j]);      
        if((name[j] == '?') || (name[j] == '.')) {
            sign = name[j];
            name[j] = ' ';
            break;
        }
        else var++;
    }
    char array[var];
    for(int i = 0; i <= var; i++) array[i] = ' ';
    for(int y = 0; y <= var; y++) array[y] = strrev(name);
 
    for(int i = 0; i < var; i ++) {
        printf("%c", array[i]);
             
    }
    printf("%c\n", sign);   
}

