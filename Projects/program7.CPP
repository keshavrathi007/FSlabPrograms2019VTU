#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
class coseq
{
char list1[20][20],list2[20][20];
int count1,count2;
public:
void load();
void sort();
coseq();
void match();
};
coseq::coseq()
{
int n;
char name[20];
fstream fs;
fs.open("name1.txt",ios::out|ios::app);
cout<<"Enter hoW many name for list one: ";
cin>>n;
for(int i=0;i<n;i++)
{
fflush(stdin);
cin>>name;
fs<<name<<endl;
}
fs.close();
fs.open("name2.txt",ios::out|ios::app);
cout<<"Enter hoW many name for list two: ";
cin>>n;
for(i=0;i<n;i++)
{
fflush(stdin);
cin>>name;
fs<<name<<endl;
}
fs.close();
}
void coseq::load()
{
fstream file;
char name[20];
count1=-1;
count2=-1;
file.open("name1.txt",ios::in);
while(!file.eof())
{
file.getline(name,'\n');
strcpy(list1[++count1],name);
}
file.close();
file.open("name2.txt",ios::in);
while(!file.eof())
{
file.getline(name,'\n');
strcpy(list2[++count2],name);
}
file.close();
}
void coseq::sort()
{
int i,j;
char temp[20];
for(i=0;i<=count1;i++)
{
for(j=i+1;j<=count1;j++)
{
if(strcmp(list1[i],list1[j])>0)
{
strcpy(temp,list1[i]);
strcpy(list1[i],list1[j]);
strcpy(list1[j],temp);
}
}
 }
 for(i=0;i<=count2;i++)
 {
for(j=i+1;j<=count2;j++)
{
if(strcmp(list2[i],list2[j])>0)
{
strcpy(temp,list2[i]);
strcpy(list2[i],list2[j]);
strcpy(list2[j],temp);
}
}
}
}
void coseq::match()
{
int i=0,j=0;
cout.flush();
while(i<=count1 &&j<=count2)
{
if(strcmp(list1[i],list2[j])==0)
{
cout<<endl<<list1[i];
i++;
j++;
}
if(strcmp(list1[i],list2[j])<0)
i++;
if(strcmp(list1[i],list2[j])>0)
j++;
}
}
void main()
{ clrscr();
coseq c;
c.load();
c.sort();
 cout<<”\nList of Names common in both list are : ”;
c.match();
getch();
}