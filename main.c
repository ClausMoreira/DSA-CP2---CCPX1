#include <stdio.h>
#include <string.h>
#include <ctype.h>

//fibonacci
void fibonacci() {
    int n;
    printf("Digite a quantidade de termos da sequencia Fibonacci(1 a 50):");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Numero invalido!\n");
        return;
    }

    int fib[50];
    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Sequencia Fibonacci:");
    for (int i = 0; i < n; i++) {
        printf("%d", fib[i]);
    }
    printf("\n");
}

//fatorial
void fatoriais() {
    int n;
    printf("Digite um numero(1 a 20):");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Impossivel, tente novamente\n");
        return;
    }

    long long fat[20];
    fat[0] = 1;

    for (int i = 1; i < n; i++) {
        fat[i] = fat[i - 1] * (i + 1);
    }

    printf("Fatoriais:\n");
    for (int i = 0; i < n; i++) {
        printf("%d! = %lld\n", i + 1, fat[i]);
    }
}

//palindromo
void palindromo() {
    char palavra[101];

    printf("Digite uma palavra:"); //tenta AIBOFOBIA :)
    scanf("%s", palavra);

    int tam = strlen(palavra);
    int st_palindromo = 1;

    for (int i = 0; i < tam / 2; i++) {
        if (tolower(palavra[i]) != tolower(palavra[tam - 1 - i])) {
            st_palindromo = 0;
            break;
        }
    }

    if (st_palindromo)
        printf("Representa um palindromo.\n");
    else
        printf("Nao representa um palindromo.\n");
}

//substring
void verificar_substring() {
    char str1[100], str2[100];

    printf("Informe a primeira string:");
    scanf("%s", str1);

    printf("Informe a segunda string:");
    scanf("%s", str2);

    // Verificação simples de substring sem usar strstr
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int encontrado = 0;

    if (len2 > len1) {
        printf("A segunda string nao esta contida na primeira string.\n");
        return;
    }

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j])
                break;
        }
        if (j == len2) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
        printf("A segunda string esta contida na primeira string.\n");
    else
        printf("A segunda string nao esta contida na primeira string.\n");
}

//menu
int main() {
    int opcao;

    do {
        printf(">>>> MENU <<<<\n");
        printf("1 - Fibonacci\n");
        printf("2 - Fatorial\n");
        printf("3 - Palindromo\n");
        printf("4 - Substring\n");
        printf("5 - Encerrando\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                fibonacci();
                break;
            case 2:
                fatoriais();
                break;
            case 3:
                palindromo();
                break;
            case 4:
                verificar_substring();
                break;
            case 5:
                printf("Encerrando\n");
                break;
            default:
                printf("Escolha impossivel, tente novamente\n");
        }

    } while (opcao != 5);

    return 5;
}
