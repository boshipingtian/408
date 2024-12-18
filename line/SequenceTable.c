#define INIT_SIZE 10
#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序表
 * 底层：数组，内存上是连续的空间，指针指向数组中第一个元素
 * 时间复杂度：查找、新增为O(1)；修改，删除需要移动其他元素，极端情况为O(n)
 */
#define MAX_SIZE 10 // 定义最大长度

typedef struct {
    int data[MAX_SIZE]; // 使用静态“数组”存放数据元素
    int length; // 顺序表当前长度
} SqList;

void InitSqList(SqList *list) {
    for (int i = 0; i < MAX_SIZE; i++) {
        list->data[i] = 0; // 初始化数据，【否则会有脏数据出现】
    }
    list->length = 0;
}

// 测试静态顺序表
int main_1() {
    SqList list;
    InitSqList(&list);
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", list.data[i]);
    }
    return 0;
}


/*
 * 动态分配大小
 *
 * 使用malloc分配内存空间
 */
#define INIT_SIZE 10 // 顺序表的初始长度

typedef struct {
    int *data; // 顺序表地址，动态分配数组的指针
    int maxSize; // 顺序表的最大容量
    int length; // 顺序表的当前长度
} SeqList;

void InitSeqList(SeqList *list) {
    list->maxSize = INIT_SIZE;
    list->length = 0;
    list->data = (int *) malloc(sizeof(int) * INIT_SIZE); // malloc分配内存
    for (int i = 0; i < list->maxSize; i++) {
        list->data[i] = 0; // 初始化数据
    }
}

void IncreaseSeqSize(SeqList *list, int len) {
    int *oldData = list->data; // 旧数据指针
    list->data = (int *) malloc(sizeof(int) * (list->maxSize + len)); // 分配一个更大的内存空间
    for (int i = 0; i < list->length; i++) {
        list->data[i] = oldData[i]; // 复制旧数据到新空间，【最耗时】
    }
    for (int i = list->maxSize; i < list->length + len; ++i) {
        list->data[i] = 0; // 给新空间设置默认值
    }
    list->maxSize = list->maxSize + len; // 修改最大容量
    free(oldData); // 释放旧空间
}

void InsertSeqList(SeqList *list, int val) {
    if (list->length >= list->maxSize) {
        printf("索引超出数据范围 %d >= %d", list->length, list->maxSize);
        return;
    }
    list->data[list->length] = val;
    list->length++;
}

void AddSeqList(SeqList *list, int index, int val) {
    if (index >= list->maxSize) {
        printf("索引超出数据范围 %d >= %d", index, list->maxSize);
        return;
    }
    if (index < list->length) {
        for (int i = list->length; i >= index; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[index - 1] = val;
        list->length++;
    } else {
        InsertSeqList(list, val);
    }
}

void main() {
    SeqList seqList;
    InitSeqList(&seqList);
    for (int i = 0; i < seqList.maxSize; ++i) {
        printf("%d ", seqList.data[i]);
    }
    printf("扩容10单位 \n");
    IncreaseSeqSize(&seqList, 10);
    for (int i = 0; i < seqList.maxSize; ++i) {
        printf("%d ", seqList.data[i]);
    }
    printf("\n");
}
