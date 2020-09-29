#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc (void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *result = malloc(size);
    memcpy(result, ptr, size);
    free(ptr);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int m;
    scanf("%d", &m);

    a = (int*)my_realloc(a, sizeof(int) * m);

    for (int i = n; i < m;++i) {
        a[i] = 0;
    }

    for(int i = 0; i < m; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}


