#include <stdio.h>
#include <stdlib.h>

#define		SIZE (6)

typedef struct table
{
	int* head;
	int lenght;
	int size;
}Table;

void PrintData(Table table);
void FillData(Table* table);
Table InitTable(void);


int main()
{
	int cnt = 0;
	Table table = InitTable();

	FillData(&table);

	PrintData(table);

	return 0;
}

void PrintData(Table table)
{
	int cnt = 0;
	while (cnt <= table.lenght)
	{
		printf("%d ", table.head[cnt++]);
	}

	return;
}

void FillData(Table* table)
{
	int cnt = 0;
	while (cnt < SIZE)
	{
		table->head[cnt] = cnt;
		table->lenght = cnt++;
	}

	return;
}

Table InitTable(void)
{
	Table table;

	table.head = (int*)malloc(SIZE * sizeof(int));

	if (!table.head)
	{
		printf("crate the table fail\n");
		exit(0);
	}
	table.lenght = 0;
	table.size = SIZE;

	return table;
}