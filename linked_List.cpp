#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node(int n)
    {
        value =n;
        next =NULL;
    }
};

void  insert_node(Node *&head,int n)
{
    Node * new_node =new Node(n);
    if(head ==NULL){ head =new_node; return;}

    Node *temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

int count_node(Node * &head)
{
   int count =0;
   Node * temp =head;
   while(temp!=NULL)
   {
       temp=temp->next;
       count++;
   }
   return count;
}

void insert_node_by_position(Node* &head,int pos,int val)
{
    if(pos >0&&pos<=count_node(head))
    {
        Node* new_node =new Node(val);
        if(pos ==1) head =new_node;
        else{

            Node * temp =head;
            int i =1;
            while(i<pos-1)
            {
                temp =temp->next;
                i++;
            }
            new_node->next= temp->next;
            temp->next =new_node;
        }

    }
    else{
        cout<<"out of the linked list length";
    }
}

void print_linked_list(Node* n)
{
    if(n==NULL) cout<<"there is nothing on the list"<<endl;
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

void delete_at_head(Node * &head)
{
    Node *temp =head;
    if(temp!=NULL)
    {
        head=temp->next;
        delete temp;
    }
    else
    {
        cout<<"there is no value in the list"<<endl;
    }
}

void delete_at_tail(Node * &head)
{
    Node *temp =head;
    if(temp!=NULL&&temp->next!=NULL)
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node *del =temp->next;
        temp->next =NULL;
        delete del;
    }
    else
    {
        if(temp==NULL)cout<<"there is no value in the list"<<endl;
        else if(temp->next==NULL) delete_at_head(temp);
    }
}

void delete_node_by_position(Node* &head,int pos)
{
    Node *temp =head;
    if(temp!=NULL&&pos<=count_node(head))
    {
        if(pos==1) delete_at_head(head);
        else if(pos ==count_node(head)) delete_at_tail(head);
        else{

            int i =1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            Node *del =temp->next;
            temp->next=del->next;
            delete del;
        }
    }else{
        cout<<"position out of the linked list range"<<endl;
    }

}

void move_tail(Node* &head)
{
    if(head==NULL)return;
    Node* temp =head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;

    }
    Node *new_head =temp->next;
    temp->next=NULL;
    new_head->next=head;
    head=new_head;
}

int main()
{
    Node * head = NULL;
    int n;
    int pos;
    int c=2;
    cout<<"choice 1 for insert at tail "<<endl;
    cout<<"choice 2 for insert at specific position "<<endl;
    cout<<"choice 3 for delete at specific position "<<endl;
    cout<<"choice 4 to move tail"<<endl;
     cout<<"choice 0 to end  "<<endl;

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
            cout<<"enter position : ";
            cin>>pos;
            cout<<"enter num ";
            cin>>n;
            insert_node_by_position(head,pos,n);
            break;
         case 3:
             if(head==NULL)cout<<"there is nothing on the list"<<endl;
            cout<<"enter desire position to delete ";
            int pos_to_delete;
            cin>>pos_to_delete;
            delete_node_by_position(head,pos_to_delete);
            break;
         case 4:
            move_tail(head);
            break;
         default:
            break;
         }


    }

    print_linked_list(head);
    return 0;
}
