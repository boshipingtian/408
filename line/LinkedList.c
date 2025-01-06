#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkedList;

// 头插法建立链表
LinkedList List_HeadInsert() {
    LNode* l = malloc(sizeof(LNode));  // 创建头节点
    if (l == NULL) {
        printf("内存分配失败!\n");
        exit(1);
    }
    l->next = NULL;  // 初始化头节点的 next 指针为 NULL

    LNode* s;
    int x;
    printf("请输入数据，输入 9999 结束：\n");
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));  // 创建新节点
        if (s == NULL) {
            printf("内存分配失败!\n");
            exit(1);
        }
        s->data = x;
        s->next = l->next;  // 将新节点的 next 指向当前链表的第一个节点
        l->next = s;        // 将新节点插入到链表头部
        scanf("%d", &x);
    }
    return l;  // 返回头节点指针
}

// 打印链表
void Print(LinkedList l) {
    if (l == NULL || l->next == NULL) {
        printf("链表为空\n");
        return;
    }
    LinkedList dummyNode = l->next;  // 跳过头节点
    while (dummyNode != NULL) {
        printf("%d ", dummyNode->data);
        dummyNode = dummyNode->next;
    }
    printf("\n");
}

// 递归释放内存
void ReleaseMem(LinkedList l) {
    if (l == NULL) return;
    LinkedList temp;
    while (l != NULL) {
        temp = l;
        l = l->next;
        free(temp);
    }
}

int main() {
    LinkedList linkeds = List_HeadInsert();  // 获取头节点
    Print(linkeds);  // 打印链表
    ReleaseMem(linkeds);  // 释放链表内存
    return 0;
}
