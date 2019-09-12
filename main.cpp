#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct stock
{
	string name;
	int manuyr,manumonth,expiyr,expimonth;
	int price_item,avail;
	struct stock *next;
}*head=NULL;
void add()
{
	struct stock *nn,*temp;
	nn=new(stock);
	bool g=1;
	cout<<"Enter name of product"<<endl;
	cin>>nn->name;
	while(g)
	{
		cout<<"manufacturing month and yr"<<endl;
		cin>>nn->manumonth;
		cin>>nn->manuyr;
		if(nn->manumonth<=12 && nn->manumonth>=1)
			g=0;
		else
			cout<<"Wrong input"<<endl;
	}
	g=1;
	while(g)
	{
		cout<<"expiry month and yr"<<endl;
		cin>>nn->expimonth>>nn->expiyr;
		if(nn->expimonth<13 && nn->expimonth>0 && nn->expiyr > nn->manuyr)
			g=0;
		else if(nn->expiyr==nn->manuyr)
		{
			if(nn->expimonth>=nn->manumonth)
				g=0;
			else
				cout<<"Wrong input"<<endl;
		}
		else
			cout<<"Wrong choice"<<endl;
	}
	cout<<"price of each item"<<endl;
	cin>>nn->price_item;
	cout<<"Availability of that product"<<endl;
	cin>>nn->avail;
	cin.ignore();
	if(head==NULL)
		head=nn;
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}
	nn->next=NULL;
}
void display()
{
	struct stock *temp=head;
	while(temp!=NULL)
	{
		cout<<"Product details are"<<endl;
		cout<<"Name is\t"<<temp->name<<endl;
		cout<<"Manufacturing date is\t"<<temp->manumonth<<"/"<<temp->manuyr<<endl;
		cout<<"Expiry date is\t"<<temp->expimonth<<"/"<<temp->expiyr<<endl;
		cout<<"Price of each item is\t"<<temp->price_item<<endl;;
		cout<<"Available item are\t"<<temp->avail<<endl;
		temp=temp->next;
		cout<<endl;
	}
}
void bill()
{
	float total=0;
	float wat;
	int no,num;
	string n;
	char ch;
	struct stock *temp;
	cout<<"Enter number of products u want to add in ur cart"<<endl;
	cin>>no;
	while(no--)
	{
		cout<<"Enter product name u want"<<endl;
		cin>>n;
		cout<<"How many do u want?"<<endl;
		cin>>num;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->name==n)
			{
			cout<<"here\n";
				if(temp->avail==0)
				{
					cout<<"Sorry!!Product is not available"<<endl;
					break;
				}
				else if(temp->avail<num)
				{
					cout<<"Availabiliy of product is"<<temp->avail;
					cout<<"Do u want"<<temp->avail;
					cout<<"then press y else n"<<endl;
					cin>>ch;
					if(ch=='y')
						num=temp->avail;
					else
						num=0;
				}
				total+=(temp->price_item*num);
				temp->avail=(temp->avail-num);
				break;
			}
			temp=temp->next;
		}
		if(temp->next==NULL && temp->name!=n)
			cout<<"Sorry!!Product is not available"<<endl;
 	}
	wat=total*0.06;
	total=total+(wat*2);
	cout<<"Total amount is"<<total<<endl;
}
void ava()
{
	string n;
	struct stock *temp;
	cout<<"Enter a product u r seaching for"<<endl;
	cin>>n;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"hi";
		if(temp->name==n)
			cout<<temp->name<<"are"<<temp->avail<<endl;
		temp=temp->next;
	}
}
int main()
{
	int ch;
	bool f=1;
	while(f)
	{
		cout<<"What u want to do?"<<endl;
		cout<<"1.Add data 2.Display details 3.Bill 4.Availability of Product"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				add();
				break;
			case 2:
				display();
				break;
			case 3:
				bill();
				break;
			case 4:
				ava();
				break;
			default:
				cout<<"Wrong choice"<<endl;
		}
		cout<<"If u ant to continue then press 1 else 0"<<endl;
		cin>>f;
	}
	return 0;
}