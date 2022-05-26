#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	private:
		int rno;
		char name[30];
		char division[10];
		char address[30];
	public:
		void accept()
		{
			int ch;
			
				
				cout<<"Enter student details :";
				cout<<"\nEnter Roll no : ";
				cin>>rno;
				cout<<"Enter Name of student :";
				cin>>name;
				cout<<"Enter Division of student :";
				cin>>division;
				cout<<"Enter Address of the student :";
				cin>>address;
				
		}
		void display()
		{
			cout<<"\nRoll no :"<<rno<<"\nName of student :"<<name<<"\nDivision of student :"<<division<<"\nAddress of student :"<<address;
		}
		
		int getno()
		{
			return rno;
		}
};
void write()
{
	ofstream fout;
	Student x;
	fout.open("student.txt",ios::binary|ios::app);
	x.accept();
	fout.write((char *)&x,sizeof(x));
	fout.close();
	
}
void display()
{
	ifstream fin;
	Student x;
	fin.open("student.txt",ios::binary);
	while(fin.read((char *)&x,sizeof(x)))
	{
		x.display();
	}
	fin.close();
		
}
void delete_record()
{
	Student x;
	int no;
	fstream fout,fin;
	cout<<"\nEnter Roll no which is to be deleted :";
	cin>>no;
	fin.open("student.txt",ios::binary);
	fout.open("text.txt",ios::binary);
	while(fin.read((char *)&x,sizeof(x)))
	{
		if(no!=x.getno())
		{
			fout.write((char *)&x,sizeof(x));
		}
	}
	fin.close();
	fout.close();
	remove("student.txt");
	rename("text.txt","student.txt");
}
void search()
{
	ifstream fin;
	Student x;
	int no,flag=0;
	cout<<"Enter roll no which is to be search :";
	cin>>no;
	fin.open("student.txt",ios::binary);
	while(fin.read((char *)&x,sizeof(x)))
	{
		if(no==x.getno())
		{
			x.display();
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\nRecord not found";
	}
	fin.close();
}
int main()
{
	fstream fout,fin;
	Student x;
	int ch,no,flag;
	
	while(1)
	{
		cout<<"\n************MENU*************";
		cout<<"\n1.Add student details";
		cout<<"\n2.Display student details";
		cout<<"\n3.Delete student details by Roll no";
		cout<<"\n4.Search student details by Roll no";
		cout<<"\nEnter your choice :";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				write();
				break;
			case 2:
				display();
				break;
			case 3:
				delete_record();
				break;
			case 4:
				search();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Please enter valid choice ";
				
				
		}
	}
}
