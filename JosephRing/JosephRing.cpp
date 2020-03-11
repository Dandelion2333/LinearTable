#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 5

typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}Link;

Link* InitLinkList(void);
void InsertNode(int number, Link* head);
void PrintList(Link* head);
Link* JosephRing(Link* head);
Link* DeleteNode(Link* Node);

int main()
{
	int cnt = 0;
	Link* head = InitLinkList();

	for (cnt = 1; cnt < MAX_VAL; cnt++)
	{
		InsertNode(cnt, head);
	}

	head = JosephRing(head);
	//PrintList(head);

	printf("%d\n", head->data);

	return 0;
}

Link* JosephRing(Link* head)
{
	Link* node = head;
	int cnt = 1;
	int delCnt = 0;

	while (MAX_VAL > delCnt + 1)
	{
		if ((cnt % 2) == 0)
		{
			node = DeleteNode(node);
			delCnt++;
		}
		else
		{
			node = node->next;
		}		
		cnt++;
	}


	return node;
}

Link* DeleteNode(Link* Node)
{
	Link* DelNode = Node->next;
	Link* Nnode = DelNode->next;

	Node->next = Nnode;

	free(DelNode);

	return Node;
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

void InsertNode(int number, Link* head)
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

	if (number == MAX_VAL-1)
	{
		InsertTempNode->next = head;
	}
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
