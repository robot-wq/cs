#include <stdio.h>

void trocar(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d", &a);
    scanf("%d", &b);

    trocar(&a, &b);

    printf("Após a troca: %d %d\n", a, b);

    return 0;
}
