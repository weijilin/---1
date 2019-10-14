#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//结点的定义
typedef struct ListNode{
	int val;
	struct ListNode *next; 
};
typedef struct ListNode Node;

//反转链表
struct ListNode* receverList(struct ListNode *head){
	Node *rhead = NULL;
	Node *cur = head;
	while (cur != NULL){
		Node *next = cur->next;
		cur->next = rhead;
		rhead = cur;
		cur = next;
	}
	return rhead;
}

// 删除链表中所有的 val
// 遇到等于 val 的就删除
struct ListNode* removeElements_1(struct ListNode* head, int val){
	if (head == NULL){
		return NULL;
	}
	Node *prev = head;
	Node *cur = head->next;
	while(cur!=NULL){
		if (cur->val == val){
			prev->next = cur->next;
		}
		else{
			prev = cur;
		}
		cur = cur->next;
	}
	if (head->val == val){
		return head->next;
	}
	else{
		return head;
	}
}

//删除链表中所有的 val
// 遇到不等于 val 的，就尾插到另一个链表中
struct ListNode* removeElements_2(struct ListNode* head, int val){
	Node *rHead = NULL;
	Node *cur = head;
	Node *last = NULL;
	while (cur != NULL){
		Node *next = cur->next;
		if (cur->val != val){
			if (rHead == NULL){
				cur->next = rHead;
				rHead = cur;
			}
			else{
				cur->next = NULL;
				last->next = cur;
			}
			last = cur;
		}
		cur = next;
	}
	return rHead;
}
//定义一个链表
Node * createTestList(){
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;
	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;
	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;
	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	return n1;
}

void testReverseList(){
	Node *head = createTestList();
	for (Node *cur = head; cur != NULL; cur = cur->next){
		printf("%d ", cur->val);
	}
	printf("\n");
	Node *result =receverList(head);
	for (Node *cur = result; cur != NULL; cur = cur->next){
		printf("%d ", cur->val);
	}
	printf("\n");
}

//void testRemoveAll(){
//	Node *head = createTestList();
//	Node *result = removeElements_1(head, 1);
//	for (Node *cur = result; cur != NULL; cur = cur->next){
//		printf("%d ", cur->val);
//	}
//}

void testRemoveAll(){
	Node *head = createTestList();
	Node *result = removeElements_2(head, 5);
	for (Node *cur = result; cur != NULL; cur = cur->next){
		printf("%d ", cur->val);
	}
}
int main()
{
	testReverseList();
	testRemoveAll();
	system("pause");
	return 0;
}