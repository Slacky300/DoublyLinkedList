#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*head=NULL,*head2=NULL;
struct node *addAtEnd(struct node *head, int value)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    if(p==NULL)
    {
        head = temp;
        head->left=NULL;
        head->right=NULL;
    }
    else
    {
        while(p->right!=NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->right=NULL;
        temp->left=p;
        return head;
    }
}
struct node *addAfter(struct node *head,int locat,int value)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    while(p!=NULL)
    {
        if(p->data==locat)
        {
            if(p->right==NULL)
            {
                head = addAtEnd(head,value);
                return head;
            }
            temp->left = p;
            p->right=temp->right;
            if(p->right!=NULL)
            {
                p->right->left = temp;
                p->right = temp;
                return head;
            }
        }
        p=p->right;
    }
    printf("%d does not exists in the linked list\n");
    return head;
}
struct node *addBefore(struct node *head,int item,int value)
{
    struct node *temp,*p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->data == item)
    {
        temp->left = NULL;
        temp->right=head;
        head->left = temp;
        head = temp;
        return head;
    }
    p = head;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            temp->left = p->left;
            temp->right = p;
            p->left->right = temp;
            p->left = temp;
            return head;
        }
        p = p->right;
    }
    printf("%d does not exist in the linked list\n",value);
    return head;
}
struct node *addAtBeg(struct node *head,int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    head->left = temp;
    temp->right = head;
    temp->left = NULL;
    head = temp;
    return head;
}
struct node *createList(struct node *head)
{
    int i,n,value;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the %d element to add\n",i+1);
        scanf("%d",&value);
        head = addAtEnd(head,value);
    }
    return head;
}
void display(struct node *head)
{
    struct node *p;
    p = head;
    if(p==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        printf("List elements are:\n");
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->right;
        }
        printf("\n");
    }
}
struct node *delNode(struct node *head, int value)
{
    struct node *p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
//Only one node present in the list;
    if(head->right==NULL)
    {
        if(head->data==value)
        {
            p = head;
            head = NULL;
            free(p);
            return head;
        }
        else
        {
            printf("%d does not exists in the list\n",value);
            return head;
        }
    }
//For deleting head node;
    if(head->data==value)
    {
        p = head;
        head = head->right;
        head->left = NULL;
        free(p);
        return head;
    }
//Deletion of random node;
    p = head->right;
    while(p->right!=NULL)
    {
        if(p->data==value)
        {
            p->left->right = p->right;
            p->right->left = p->left;
            free(p);
            return head;
        }
        p= p->right;
    }
//To delete last node;
    if(p->data==value)
    {
        p->left->right=NULL;
        free(p);
        return head;
    }
    else
    {
        printf("Element does not exists in the linked list\n");
        return head;
    }
}
void nodeSort()
{
    struct node *p,*q;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    int temp;
    for(p=head; p!=NULL; p=p->right)
    {
        for(q=p->right; q!=NULL; q=q->right)
        {
            if(p->data>q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}
struct node *split(struct node *head,int value)
{
    struct node *p;
    p = head;
    if(head==NULL)
    {
        printf("Linked list is empty cannot perform split operation\n");
        return head;
    }
    while(p->data!=value)
    {
        p=p->right;
    }
    if(p==NULL)
    {
        printf("Last node\n");
        return head2;
    }
    head2 = p->right;
    p->right = NULL;
    head2->left = NULL;
    p->left = NULL;
    return head2;
}
struct node *merge(struct node *head,struct node *head2)
{
    struct node *p;
    p = head;
    while(p->right!=NULL)
    {
        p = p->right;
    }
    p->right = head2;
    head2 = NULL;
    return head2;
}
void main()
{
    int hold,n,choice=0,choice2=0;
    while(choice!=8)
    {
        printf("Enter the operation to perform\n");
        printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Split\n6.Merge\n7.Sort\n8.Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            head = createList(head);
        }
        else if(choice == 2)
        {
            display(head);
        }
        else if(choice == 3)
        {
            while(choice2!=5)
            {
                printf("1.Beginning\n2.Last\n3.After\n4.Before\n5.Exit\n");
                scanf("%d",&choice2);
                if(choice2==1)
                {
                    display(head);
                    printf("Enter the value to insert\n");
                    scanf("%d",&hold);
                    head = addAtBeg(head,hold);
                }
                else if(choice2==2)
                {
                    display(head);
                    printf("Enter the value to insert\n");
                    scanf("%d",&hold);
                    head = addAtEnd(head,hold);
                }
                else if(choice2==3)
                {
                    display(head);
                    printf("Enter the element and the value to add after it\n");
                    scanf("%d %d",&hold,&n);
                    head = addAfter(head,hold,n);
                }
                else if(choice2==4)
                {
                    display(head);
                    printf("Enter the element and the value to add before it\n");
                    scanf("%d %d",&hold,&n);
                    head = addBefore(head,hold,n);
                }
                else if(choice2==5)
                {
                    break;
                }
                else
                {
                    printf("Invalid choice\n");
                }
            }
        }
        else if(choice==4)
        {
            display(head);
            printf("Enter the element to delete\n");
            scanf("%d",&hold);
            head = delNode(head,hold);
        }
        else if(choice==5)
        {
            display(head);
            printf("Enter the ending point of first list\n");
            scanf("%d",&hold);
            head2 = split(head,hold);
            display(head);
            printf("Second linked list\n");
            display(head2);
        }
        else if(choice==6)
        {
            head2=merge(head,head2);
            printf("Merged Successfully\n");
        }
        else if(choice==7)
        {
            nodeSort();
            printf("Sorted Successfully\n");
            display(head);
        }
        else if(choice == 8)
        {
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }
    printf("Operations Terminated\nFinal Linked List\n");
    display(head);
}
