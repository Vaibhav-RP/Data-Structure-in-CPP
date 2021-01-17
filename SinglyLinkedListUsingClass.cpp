#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node(int data)
		{
			this->data=data;
			this->next=nullptr;
		}
};

class ssl
{
	public:
	Node* head;
	ssl()
	{
		this->head=nullptr;
	}
	void insertBeg(int);
	void display(Node*);
	void insertEnd(int);
	void insertMid(int,int);
	void deleteBeg();
	void deleteEnd();
	void deleteMid(int);
};


void ssl::insertBeg(int data)
{
	Node* newnode= new Node(data);
	if(head==nullptr)
		head=newnode;
	else
	{
		newnode->next=head;
		head=newnode;
	}	
}


void ssl::insertEnd(int data)
{
	Node* newnode= new Node(data);
	Node* temp=head;
	if(temp==nullptr)
	{
		head=newnode;
	}	
	else
	{	while(temp->next!=nullptr)
			temp=temp->next;
			
		temp->next=newnode;	
	}	
}


void ssl::insertMid(int data,int pos)
{
	Node* newnode= new Node(data);
	Node* temp=head;
	if(temp==nullptr)
	{
		head=newnode;
	}	
	else
	{
		int cnt=1;
		while(cnt<pos)
		{
			cnt++;
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}	
}


void ssl::display(Node* head)
{
	Node* temp=head;
	while(temp!=nullptr)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}


void ssl::deleteBeg()
{
	Node* temp=head;
	if(temp==NULL)
		return;
		
	head=head->next;
	free(temp);
}


void ssl::deleteEnd()
{
	Node* temp=head;
	if(temp==NULL)
		return;
	if(temp->next==NULL)
	{
		head=NULL;
		free(temp);
		return;
	}
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
		
	}	
	Node* temp1=temp->next;
	temp->next=NULL;
	free(temp1);
}


void ssl::deleteMid(int pos)
{
	Node* temp=head;
	if(temp==NULL){
		return;
	}
		
	if(temp->next==NULL)
	{
		head=NULL;
		free(temp);
		return;
	}
	
	int cnt=1;
	while(cnt<pos-1)
	{
		cnt++;
		temp=temp->next;
	}
	
	Node* temp1=temp->next;
	temp->next=temp1->next;
	temp1->next=NULL;
	free(temp1);
}


int main()
{
	ssl s;
	int t;
	cin>>t;
	while(t--)
	{
		ssl * list1= new ssl();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int data;
			cin>>data;
			list1->insertBeg(data);
		}
		cout<<"\nInsert at beg = ";
		s.display(list1->head);
		
		
		ssl * list2= new ssl();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int data;
			cin>>data;
			list2->insertEnd(data);
		}
		cout<<"\nInsert at end = ";
		s.display(list2->head);
		
		
		int data,pos;
		cin>>data>>pos;
		list1->insertMid(data,pos);
		cout<<"\nInsert aftre pos = ";
		s.display(list1->head);
		
		
		cout<<"\ndelete at beg = ";
		list1->deleteBeg();
		s.display(list1->head);
		
		
		cout<<"\ndelete at end = ";
		list1->deleteEnd();
		s.display(list1->head);
		
		
		cout<<"\ndelete at pos = ";
		int pos;
		cin>>pos;
		list1->deleteMid(pos);
		s.display(list1->head);
		
	}
	return 0;
}
