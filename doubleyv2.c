/*			Shubham Jain
			DCSA MCA E
			
				*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>

struct dnode
{
	int info;
	struct dnode *prev,*next;
};
void Trav(struct dnode *head,struct dnode *tail)
{
	int i=1;
	if(head==NULL) //----------------------------------------------------- empty list
		printf("\nList is Empty !");
	else
	{	
		while(head!=NULL) //---------------------------------------------- moving in list
		{
			printf("\n%dth Element is :%d",i,head->info);
			i++;
			head=head->next;
		}
	}
}
void InsBeg(struct dnode **head,struct dnode **tail,int info)
{
	struct dnode *temp;
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	temp->info=info;
	if((*head)==NULL && (*tail)==NULL)	//-------------------------------- list is empty
	{
		temp->next=NULL;
		temp->prev=NULL;
		*head=temp;
		*tail=temp;
	}
	else	//------------------------------------------------------------ list is not empty
	{
		temp->prev=NULL;
		temp->next=*head;
		(*head)->prev=temp;
		*head=temp;
	}
}
void InsMid(struct dnode **head,struct dnode **tail,int info,int loc)
{
	int i,flag=0;
	struct dnode *temp,*cp=(*head);
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	temp->info=info;
	for	(i=0;i<loc;i++)	//------------------------------------------------ reaching to the position
	{
		if(cp==NULL)
		{
			printf("\nEnd of List Reached !");
			flag=1;
			break;
		}
		else
		{
			cp=cp->next;
		}
	}
	if(flag!=1)
	{
		if (cp->next==NULL)	//-------------------------------------------- last position
		{
			temp->prev=cp;
			temp->next=NULL;
			cp->next=temp;
			(*tail)=temp;
		}
		else 	//-------------------------------------------------------- somewhere at middle
		{
			temp->prev=cp;
			temp->next=cp->next;
			cp->next->prev=temp;
			cp->next=temp;
		}
	}
}
void InsEnd(struct dnode **head,struct dnode **tail,int info)
{
	struct dnode *temp;
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	temp->info=info;
	if((*head)==NULL && (*tail)==NULL)	//-------------------------------- list is empty
	{
		temp->next=NULL;
		temp->prev=NULL;
		*head=temp;
		*tail=temp;
	}
	else	//------------------------------------------------------------ list is not empty
	{
		temp->prev=*tail;
		temp->next=NULL;
		(*tail)->prev=temp;
		*tail=temp;
	}
}
void DelBeg(struct dnode **head,struct dnode **tail)
{
	int info;
	if((*head)==NULL && (*tail)==NULL)	//--------------------------------- list is empty
	{
		printf("List is Empty !");
	}
	else	//------------------------------------------------------------- list isnt empty
	{
		if((*head)!=(*tail))	//----------------------------------------- only one node
		{
			info=(*head)->info;
			(*head)=(*head)->next;
			(*head)->prev=NULL;
		}
		else	//--------------------------------------------------------- normal situation
		{
			info=(*head)->info;
			(*head)=NULL;
			(*tail)=NULL;
		}
		printf("\nDeleted Value is :%d",info);
	}
}
void DelMid(struct dnode **head,struct dnode **tail,int loc)
{
	int info,i;
	struct dnode *cp=(*head);
	if((*head)==NULL && (*tail)==NULL)	//---------------------------------- list is empty
	{
		printf("List is Empty !");
	}
	else	//-------------------------------------------------------------- list is not empty
	{
		if((*head)!=(*tail))	//------------------------------------------ reaching to position
		{
			for (i=0;i<loc;i++)
			{
				if(cp==NULL) //--------------------------------------------- list finished
				{
					printf("\nEnd of List reached !");
					break;
				}
				cp=cp->next;
			}	
				info=cp->info;
				cp->prev->next=cp->next;	
				cp->next->prev=cp->prev;
				printf("\nElement Deleted :%d",info);
		}
		else //-------------------------------------------------------------- only element in the list
		{
			info=(*head)->info;
			(*head)=NULL;
			(*tail)=NULL;
		}
		printf("\nDeleted Value is :%d",info);
	}
}
void DelEnd(struct dnode **head,struct dnode **tail)
{
	int info;
	if((*head)==NULL && (*tail)==NULL)//-------------------------------------- empty list
	{
		printf("List is Empty !");
	}
	else	//list is not empty
	{
		if((*head)!=(*tail))	//-------------------------------------------- more then one element
		{
			info=(*tail)->info;
			(*tail)=(*tail)->prev;
			(*tail)->next=NULL;
		}
		else 	//------------------------------------------------------------ only one element
		{
			info=(*head)->info;
			(*head)=NULL;
			(*tail)=NULL;
		}
		printf("\nDeleted Value is :%d",info);
	}	
}
int main()
{
	struct dnode *head=NULL,*tail=NULL;
	int ch,ch1,loc,info;
	while (1)
	{
		printf("\n\n\n============+WELCOME+===========\n\n");
		printf("1.Traverse List\n2.Insert Element\n3.Delete Element\n4.Exit\n*Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{	
				Trav(head,tail);
				}break;
			case 2:
				{
					printf("\n============+Insert Menu+=========\n\n");
					printf("1.Insert at Beginning\n2.Insert at Mid Loc\n3.Insert at End\n4.Back\n*Enter your choice :");
					scanf("%d",&ch1);
					switch(ch1)
					{
						case 1:
							{
								printf("Enter Element :");
								scanf("%d",&info);
								InsBeg(&head,&tail,info);
							}break;
						case 2:
							{
								printf("Enter Element and Position :");
								scanf("%d%d",&info,&loc);
								InsMid(&head,&tail,info,loc);
							}break;
						case 3:
							{
								printf("Enter Element :");
								scanf("%d",&info);
								InsEnd(&head,&tail,info);
							}break;
						case 4:
							break;
						default :
							printf("Not a valid choice !\n");
					}
				}break;
			case 3:
				{
					printf("\n============+Delete Menu+=========\n\n");
					printf("1.Delete at Beginning\n2.Delete at Mid Loc\n3.Delete at End\n4.Back\n*Enter your choice :");
					scanf("%d",&ch1);
					switch(ch1)
					{
						case 1:
							{
								DelBeg(&head,&tail);
							}break;
						case 2:
							{
								printf("Enter Position :");
								scanf("%d",&loc);
								DelMid(&head,&tail,loc);
							}break;
						case 3:
							{
								DelEnd(&head,&tail);
							}break;
						case 4:
							break;
						default :
							printf("Not a valid choice !\n");
					}
				}break;
			case 4:
				exit(0);
			default :
					printf("Enter valid choice !");
		}
	}
	return 0;
}
