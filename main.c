/*
 * @Author: shangchuan shangchuan97@163.com
 * @Date: 2025-04-21 22:17:04
 * @LastEditors: shangchuan shangchuan97@163.com
 * @LastEditTime: 2025-04-25 22:46:43
 * @FilePath: \1.invert-list-using-C-language\main.c
 */
#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int data;
    struct node *next;
}Node;


Node * list_add_tail(Node **tail, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if(NULL == *tail)
    {
        *tail = node;
    }
    else
    {
        (*tail)->next = node;
        *tail = node;
    }
    return *tail;
}

Node* list_add_tail_v2(Node *tail, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    tail->next = node;
    return tail->next;
}


void printf_list(Node* head)
{
    if(NULL == head)
    {
        printf("head is NULL\n");
    }
    else
    {
        Node* tmp = head;
        while (NULL != tmp)
        {
            printf("list data = %d\n", tmp->data);
            tmp = tmp->next;
        }
    }
    
}


/**
 * @description: 就地翻转
 * @param {Node} *head
 * @return {*}
 */
Node* inverse_list(Node *head)
{
    Node *pre = head;
    Node *cur = head->next;

    while (NULL != cur)
    {
        pre->next = cur->next;
        cur->next = head;
        head = cur;
        cur = pre->next;
    }

    return head; 
    
}

/**
 * @description: 迭代翻转 三指针
 * @param {Node} *head
 * @return {*}
 */
Node* inverse_list_v2(Node *head)
{
    Node *pre = NULL;
    Node *cur = head;
    Node *nxt = cur->next;

    while (NULL != cur)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
        head = pre;
    }
    
    return head;
    
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    tail = list_add_tail(&head, 1);
    tail = list_add_tail(&tail, 2);
    tail = list_add_tail(&tail, 3);
    tail = list_add_tail(&tail, 4);
    tail = list_add_tail(&tail, 5);
    printf_list(head);
    head = inverse_list_v2(head);
    printf_list(head);

}