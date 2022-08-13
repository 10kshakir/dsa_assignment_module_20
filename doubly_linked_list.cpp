#include <iostream>
using namespace std;

class Doubly_Node
{
public:
    int value;
    Doubly_Node *prev;
    Doubly_Node *next;
    Doubly_Node(int n)
    {
        value =n;
        prev =NULL;
        next=NULL;
    }
};

void print_linked_list(Doubly_Node* n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
        {
            cout<<" -> ";
        }
        n=n->next;
    }
}

void  insert_node(Doubly_Node * &head,int n )
{
    Doubly_Node* new_dn =new Doubly_Node(n);
    if(head==NULL){head=new_dn;return;}

    Doubly_Node* temp =head;
    while(temp->next!=NULL) temp=temp->next;

    temp->next=new_dn;
    new_dn->prev=temp;
}

void insert_at_tail(Doubly_Node* &head,int n)
{

    Doubly_Node *new_dn = new Doubly_Node(n);

    if(head ==NULL) {head =new_dn; return;}

    Doubly_Node* temp =head;

    while(temp->next!=NULL)
    {
        temp =temp->next;
    }

    temp->next=new_dn;
    new_dn->prev =temp;

}
int linked_list_length(Doubly_Node * &head)
{
   int count =0;
   Doubly_Node * temp =head;
   while(temp!=NULL)
   {
       temp=temp->next;
       count++;
   }
   return count;
}

void insert_at_head(Doubly_Node* &head,int n)
{
    if(head ==NULL)
    {
        insert_at_tail(head,n);
        return;
    }
    Doubly_Node *new_dn =new Doubly_Node(n);
    head->prev=new_dn;
    new_dn->next=head;

    head =new_dn;
}

void insert_node_by_position(Doubly_Node* &head,int pos ,int value)
{
    Doubly_Node* new_dn =new Doubly_Node(value);
    if(head==NULL){head=new_dn;return;}

   if(pos ==1)
    {

        insert_at_head(head,value);
        return;
    }

    int i =1;
    Doubly_Node* temp =head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    Doubly_Node *t =temp->next;
    new_dn->next=t;
    temp->next=new_dn;
    new_dn->prev=temp;
}

void deletion_at_head(Doubly_Node* &head)
{
    Doubly_Node *temp =head;
    if(temp!=NULL)
    {
        Doubly_Node* t=temp->next;
        head=t;
        t->prev=NULL;
        delete temp;
    }
    else
    {
        cout<<"there is no value in the list"<<endl;
    }
}

void delete_at_tail(Doubly_Node * &head)
{
    Doubly_Node *temp =head;
    if(temp!=NULL&&temp->next!=NULL)
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Doubly_Node *del =temp->next;
        temp->next =NULL;
        delete del;
    }
    else
    {
        if(temp==NULL)cout<<"there is no value in the list"<<endl;
        else if(temp->next==NULL) deletion_at_head(temp);
    }
}

void delete_node_by_position(Doubly_Node* & head,int pos)
{
    Doubly_Node *temp =head;
    if(temp!=NULL&&pos<=linked_list_length(head))
    {
        if(pos==1)deletion_at_head(head);
        else if(pos==linked_list_length(head)) delete_at_tail(head);
        else{
            int i =1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            Doubly_Node *del =temp->next;
            Doubly_Node *t = del->next;
            temp->next=t;
            t->prev=temp;
            delete del;
        }
    }else{
        cout<<"position out of the linked list range"<<endl;
    }

}

void move_head(Doubly_Node* &head)
{
    if(head==NULL)return;
    Doubly_Node* temp =head;
    Doubly_Node* l_node =head;
    Doubly_Node* new_head =head->next;
    new_head->prev=NULL;
    head=new_head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=l_node;
    l_node->prev=temp;
    l_node->next=NULL;
}

int main()
{

     Doubly_Node * head = NULL;
    int n;
    int pos;
    int c=2;
    cout<<"choice 1 for insert at tail "<<endl;
    cout<<"choice 2 for insert at specific position "<<endl;
    cout<<"choice 3 for delete at specific position  "<<endl;
    cout<<"choice 4 for move head on tail "<<endl;
    cout<<"choice 0 for end"<<endl;
    cout<<endl;
     while(c!=0)
    {
        cout<<"enter choice ";
        cin>>c;

        switch(c)
        {
        case 1:
            cout<<"enter num ";
            cin>>n;
            insert_node(head,n);
            break;
        case 2:
            cout<<"enter position";
            cin>>pos;
            cout<<"enter num ";
            cin>>n;

            insert_node_by_position(head,pos,n);
            break;
        case 3:
            cout<<"enter position";
            cin>>pos;
            delete_node_by_position(head,pos);
            break;
        case 4:
            move_head(head);
            break;
        default:
            break;
        }
    }
    cout<<endl;
    print_linked_list(head);
}
