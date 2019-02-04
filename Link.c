/* copyright Shubham Jain 
				DCSA MCA I E
				*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *next;
};
void InsBeg(struct node **head,int info)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=info;
	if(*head==NULL)
	{
		temp->next=NULL;
		*head=temp;
	}
	else
	{
		temp->next=*head;
		*head=temp;
	}	
}
void InsPnt(struct node **head,int info,int pnt)
{
	struct node *temp,*cp=*head;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=info;
	if(*head==NULL)
	{
		temp->next=NULL;
		*head=temp;
	}
	else
	{
		while(cp->info!=pnt)
		{
			if (cp->next==NULL)
			{
				printf("Element not found in the List !");
				break;
			}
			cp=cp->next;	
		}
		temp->next=cp->next;
		cp->next=temp;
	}
}
void InsEnd(struct node **head,int info)
{
	struct node *temp,*cp=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=info;
	temp->next=NULL;
	while(cp->next!=NULL)
	{
		cp=cp->next;
	}
	cp->next=temp;
}
void DelBeg(struct node **head)
{
	int info;
	if (*head==NULL)
		printf("List is Empty !");
	else
	{
		info=(*head)->info;
		*head=(*head)->next;
		printf("Element deleted :%d",info);
	}
}
void DelEle(struct node **head,int ele)
{
	struct node *cp=*head,*pr;
	int info;
	if (*head==NULL)
		printf("List is Empty !");
	else
	{
		while (cp->next->info!=ele)
		{
			cp=cp->next;
		}		
		info=cp->next->info;
		cp->next=cp->next->next;
		printf("Element deleted :%d",info);
	}
}
void DelEnd(struct node **head)
{
	struct node *cp=*head;
	int info;
	if (*head==NULL)
		printf("List is Empty !");
	else
	{
		while(cp->next->next!=NULL)
			cp=cp->next;
		info=cp->next->info;
		cp->next=NULL;
		printf("Element deleted :%d",info);
	}
}
void Trav(struct node *head)
{
	struct node *cp=head;
	int i=1;
	if (head==NULL)
		printf("List is Empty");
	else
	{
		while(cp->next!=NULL)
		{
			printf("%dth Element -> %d\n",i,cp->info);
			cp=cp->next;
			i++;
		}
		printf("%dth Element -> %d\n",i,cp->info);
	}
}
int main()
{
	struct node *head=NULL;
	int i,ch,ch1,info,pnt,ele;
	while (1)
	{
		printf("\n\n\n\n=========Linked Lists========\n\n");
		printf("1. Traverse list\n");
		printf("2. Insert a node\n");
		printf("3. Delete a node\n");
		printf("4. Exit \n");
		printf("\nEnter your fuckin' choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					Trav(head);
					break;
				}
			case 2:
				{
					printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at beginning\n2.Insert at after specified element\n3.Insert in the End\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch1);
                    switch(ch1)
                    {
                        case 1:
						{
							printf("Enter the element :");
							scanf("%d",&info);
                        	InsBeg(&head,info);
                            break;
						} 
                        case 2: 
						{
							printf("Enter the Data and element : ");
							scanf("%d%d",&info,&pnt);
							InsPnt(&head,info,pnt);
                         	break;
						}     
                        case 3: 
						{
							printf("Enter the element :");
							scanf("%d",&info);
							InsEnd(&head,info);
                            break;
						}
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
					break;
				}
			case 3:
					printf("\n---- Delete Menu ----");
                    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from after specified element\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1: 
                        {
                        	DelBeg(&head);
                        	break;
						}
                        case 2: 
                        {
                        	DelEnd(&head);
                        	break;
						}
                        case 3: 
                        {
                        	printf("Enter the element :");
                        	scanf("%d",&ele);
                        	DelEle(&head,ele);
                        	break;
						}
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
			case 4:
				{
					exit(0);
				}
			default :
				printf("Enter a valid choice !");
		}
	}
	return 0;
}
