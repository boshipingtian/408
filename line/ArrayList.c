#define MAX_SIZE 10
#define INIT_SIZE 10
#include <stdio.h>
#include <stdlib.h>

// 静态数据大小
typedef struct {
    int data[MAX_SIZE];
    int length;
} ArrayList;

void InitList(ArrayList *list) {
    for (int i = 0; i < MAX_SIZE; i++) {
        list->data[i] = 0;
    }
    list->length = 0;
}

// 动态数据大小
typedef struct {
    int *data; // 数据地址
    int maxSize; // 最大大小
    int length; // 数据长度
} DynamicArrayList;

void InitDynamicList(DynamicArrayList *list) {
    list->maxSize = INIT_SIZE;
    list->length = 0;
    list->data = (int *) malloc(sizeof(int) * INIT_SIZE);
    for (int i = 0; i < list->maxSize; i++) {
        list->data[i] = 0;
    }
}

void IncreaseDynamicList(DynamicArrayList *list, int length) {
    int *oldData = list->data;
    list->data = (int *) malloc(sizeof(int) * length);
    for (int i = 0; i < list->length; ++i) {
        list->data[i] = oldData[i];
    }
    list->maxSize = list->maxSize + length;
    free(oldData);
}

void InsertDynamicList(DynamicArrayList *list, int value) {
    if (list->length >= list->maxSize) {
        printf("索引超出数据范围 %d >= %d", list->length, list->maxSize);
        return;
    }
    list->data[list->length] = value;
    list->length++;
}

void AddDynamicList(DynamicArrayList *list, int index, int value) {
    if (index >= list->maxSize) {
        printf("索引超出数据范围 %d >= %d", index, list->maxSize);
        return;
    }
    if (index < list->length) {
        for (int i = list->length; i >= index; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[index - 1] = value;
        list->length++;
    } else {
        InsertDynamicList(list, value);
    }
}

int main() {
    ArrayList l;
    InitList(&l);
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("value = %d\n", l.data[i]);
    }

    printf("-----------------------------\n");

    DynamicArrayList dl;
    InitDynamicList(&dl);
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("value = %d\n", dl.data[i]);
    }
    printf("old size = %d\n", dl.maxSize);
    IncreaseDynamicList(&dl, 10);
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("value = %d\n", dl.data[i]);
    }
    printf("new size = %d\n", dl.maxSize);
    printf("------------------------------\n");

    DynamicArrayList dl2;
    InitDynamicList(&dl2);
    InsertDynamicList(&dl2, 10);
    InsertDynamicList(&dl2, 11);
    InsertDynamicList(&dl2, 12);
    InsertDynamicList(&dl2, 13);
    printf("[");
    for (int i = 0; i < dl2.maxSize; ++i) {
        if (i == dl2.maxSize - 1) {
            printf("%d", dl2.data[i]);
        } else {
            printf("%d,", dl2.data[i]);
        }
    }
    printf("]\n");
    AddDynamicList(&dl2, 2, 9);
    AddDynamicList(&dl2, 7, 1);
    printf("[");
    for (int i = 0; i < dl2.maxSize; ++i) {
        if (i == dl2.maxSize - 1) {
            printf("%d", dl2.data[i]);
        } else {
            printf("%d,", dl2.data[i]);
        }
    }
    printf("]\n");

    return 0;
}
