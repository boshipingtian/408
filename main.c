#include <stdio.h>
#include <stdlib.h>

void do_change(int *i) {
    *i = 1;
};


int main() {
    /*
     * ------------------指针------------------
     */
    printf("------------------指针------------------\n");
    int a = 0;
    printf("a = %d\n", a);
    do_change(&a);
    printf("a = %d\n", a);

    int b = 0; // 静态分配内存，系统自动申请4字节空间
    int *p = NULL;
    p = (int *) malloc(sizeof(int));
    *p = 3;
    printf("p = %d\n", *p);
    free(p);

    printf("\n\n\n");

    /*
     * ------------------数组------------------
     */
    printf("------------------数组------------------\n");
    const int n = 10;
    int score[n];
    for (int i = 0; i < n; ++i) {
        score[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", score[i]);
    }
    char str[6] = "hello";
    printf("str[6] = %s, length = %llu\n", str, sizeof(str) / sizeof(str[0]));

    /*
     * ------------------结构体------------------
     */
    printf("------------------结构体------------------\n");
    typedef struct Student {
        char name;
        int age;
        float weight;
        int score;
    } stu;

    stu s1 = {'a', 18, 180.5f, 100};
    stu* s2 = &s1;
    printf("s1.name = %c, s1.age = %d, s1.weight = %.2f, s1.score = %d\n", s1.name, s1.age, s1.weight, s1.score);
    printf("s2->name = %c, s2->age = %d, s2->weight = %.2f, s2->score = %d\n", s2->name, s2->age, s2->weight, s2->score);
}
