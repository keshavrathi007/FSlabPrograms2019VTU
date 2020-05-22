#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
class Person
{
int rrn[10];
char usn[30];
char name[30];
char address[30];
char branch[30];
char college[30];
char buffer[100];
int count;
public:
void input();
 void output();
void searchrrn();
void creatrrn();
void pack();
 void unpack();
void Write();
};
void Person :: input()
{
cout<<"Enter Usn"<<endl;
cin>>usn;
cout<<"Enter Name"<<endl;
cin>>name;
cout<<"Enter Address"<<endl;
cin>>address;
cout<<"Enter Branch"<<endl;
cin>>branch;
cout<<"Enter College"<<endl;
cin>>college;
}
void Person :: output()
{
istream& flush();
cout<<"Usn :";
puts(usn);
 cout<<"Name :";
puts(name);
cout<<"Address :";
puts(address);
 cout<<"Branch :";
puts(branch);
 cout<<"College :";
puts(college);
}
void Person::pack()
{
strcpy(buffer,usn); strcat(buffer,"|");
strcat(buffer,name); strcat(buffer,"|");
strcat(buffer,address); strcat(buffer,"|");
strcat(buffer,branch); strcat(buffer,"|");
strcat(buffer,college); strcat(buffer,"|");
strcat(buffer,"#");
}
void Person::unpack()
{
char *ptr = buffer;
while(*ptr!='#')
{
if(*ptr == '|')
*ptr = '\0';
ptr++;
}
ptr = buffer;
strcpy(usn,ptr);
ptr = ptr +strlen(ptr)+1;
strcpy(name,ptr);
ptr = ptr +strlen(ptr)+1;
strcpy(address,ptr);
ptr = ptr +strlen(ptr)+1;
strcpy(branch,ptr);
ptr = ptr+strlen(ptr)+1;
strcpy(college,ptr);
}
void Person:: Write()
{
fstream os("p.txt",ios::out|ios::app);
os.write(buffer,strlen(buffer));
os<<endl;
os.close();
}
void Person :: searchrrn()
{
int pos=-1;
int key;
cout<<"\n ENTER THE RRN:";
cin>>key;
if(key>count)
cout<<"\n FILE IS NOT FOUND";
else
{
fstream is("p.txt",ios::in);
pos=rrn[key];
is.seekp(pos,ios::beg);
is.getline(buffer,'#');
unpack();
output();
cout<<endl;
cout<<buffer;
cout<<endl<<endl;
is.close();
}
}
void Person::creatrrn()
{
fstream fs;
int pos;
count=-1;
fs.open("p.txt",ios::in);
while(fs)
{
pos=fs.tellg();
fs.getline(buffer,'#');
if(fs.eof())
break;
rrn[++count]=pos;
}
fs.close();
}
void main()
{
int choice = 1;
clrscr();
Person ob;
while(choice < 3)
{
cout<<"1> Insert A Record "<<endl;
cout<<"2> Search For A Record "<<endl;
cout<<"3> Exit "<<endl;
cin>> choice;
switch(choice)
{
case 1: ob.input();
ob.pack();
ob.Write();
break;
case 2: ob.creatrrn();
ob.searchrrn();
break;
}
} getch();
}