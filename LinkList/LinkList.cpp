#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}Link;

Link* InitLinkList(void);
void InsertNode(int number, Link* head);
void PrintList(Link* head);

int main()
{
	Link *head = InitLinkList();

	InsertNode(3, head);

	PrintList(head);

	return 0;
}

Link* InitLinkList(void)
{
	Link* head = NULL;	// 创建头结点
	Link* temp = (Link*)malloc(sizeof(Link));	// 创建首元结点
	
	temp->data = 0;
	temp->next = NULL;

	head = temp;

	return head;
}

void InsertNode(int number, Link *head)
{
	Link* temp = head;
	Link* InsertTempNode = (Link*)malloc(sizeof(Link));
	InsertTempNode->data = number;
	InsertTempNode->next = NULL;

	// 每次插入链表的尾部
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = InsertTempNode;
}

void PrintList(Link* head)
{
	Link* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}