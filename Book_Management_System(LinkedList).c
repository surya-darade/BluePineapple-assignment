//Book Management System using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
	int bid;
	char bname[25], author[25];
	float cost;
	struct book *next;
}Book;

Book *root;

int insert(int bid, char *bname, char *author, float cost)
{
	Book *node;
	node = (Book*)malloc(sizeof(Book));
	node->bid = bid;
	strcpy(node->bname, bname);
	strcpy(node->author, author);
	node->cost = cost;

	if (root == NULL)
	{
		root = node;
	}
	else
	{
		Book *temp = root;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}

int delete (int bid)
{
	Book *temp = root,*prev;
	
	if (temp!=NULL && temp->bid == bid)
	{
		root = temp->next;
		free(temp);
		return 1;
	}
	
	while(temp!=NULL && temp->bid!=bid)
	{	
		prev = temp;
		temp = temp->next;
	}
	if (temp==NULL)
	{
		return 0;
	}	
	prev->next = temp->next;
	free(temp);
	return 1;
}
int search(int bid)
{
	for (Book *temp = root; temp != NULL; temp = temp->next)
	{
		if (temp->bid == bid)
		{
			printf("\nBID \t Name \t Author \t Cost\n");
			printf("%d \t %s \t %s \t %.2f\n", temp->bid, temp->bname, temp->author, temp->cost);
			return 1;
		}
	}
	return 0;
}

void display()
{
	if (root==NULL)
	{
		printf("\nThe list is currently empty!\n");
	}
	
	printf("\nBID \t Name \t Author \t Cost\n");
	for (Book *temp = root; temp != NULL; temp = temp->next)
	{
		printf("%d \t %s \t %s \t %.2f\n", temp->bid, temp->bname, temp->author, temp->cost);
	}
}

void main()
{
	int bid,flag;
	char bname[25], author[25];
	float cost;

	int choice;
	while (1)
	{
		printf("\n1. Insert\n2. Search\n3. Display\n4. Delete\n5. Exit\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			while (1)
			{
				printf("\nBook ID: ");
				scanf("%d", &bid);
				flag=0;	
				for (Book *t = root; t != NULL; t = t->next)
				{
					if (t->bid == bid)
					{
						printf("\nAlready in use. Please try another!\n");
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					break;
				}
			}
			if (flag == 0)
			{
				printf("Book Name:");
				scanf(" %s",bname);
				printf("Author:");
				scanf(" %s",author);
				printf("Cost:");
				scanf("%f", &cost);
				if (insert(bid, bname, author, cost))
				{
					printf("\nRecord inserted successfully!\n");
				}
				else
				{
					printf("\nRecord could not be inserted successfully!\n");
				}
			}
			break;

		case 2:
			printf("Enter the book ID to search: ");
			scanf("%d", &bid);
			if(!search(bid))
			{
				printf("\nRecord not found!\n");
			}
			break;

		case 3:
			display();
			break;

		case 4:
			printf("Enter the book ID to search: ");
			scanf("%d", &bid);
			if (delete (bid))
			{
				printf("\nRecord deleted successfully!\n");
			}
			else
			{
				printf("\nRecord could not be deleted successfully!\n");
			}
			break;

		case 5: exit(0);
		}
	}
}