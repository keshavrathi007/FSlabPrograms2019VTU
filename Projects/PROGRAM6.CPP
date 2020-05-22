#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
# include<conio.h>
class Person
{
int add[10],count;
char sk[10][10];
char usn[30];
char name[30];
char address[30];
char branch[30];
char college[30];
char buffer[100];
public:
void input();
void creatind();
void search();
void remove();
void delfile(int);
void pack();
void sort();
void readf(int);
int searchn(char[20]);
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
void Person::pack()
{
strcpy(buffer,usn); strcat(buffer,"|");
strcat(buffer,name); strcat(buffer,"|");
strcat(buffer,address); strcat(buffer,"|");
strcat(buffer,branch); strcat(buffer,"|");
strcat(buffer,college); strcat(buffer,"|");
strcat(buffer,"#");
}
void Person:: Write()
{
fstream os("p.txt",ios::in | ios::app);
os.write(buffer,strlen(buffer));
os<<endl;
os.close();
 creatind();
}
void Person::creatind()
{
int pos;
count=-1;
fstream file;
file.open("p.txt",ios::in);
while(file)
{
pos=file.tellg();
file.getline(buffer,'#');
if(*buffer=='$')
continue;
if(file.eof())
break;
char *ptr=buffer;
while(*ptr!='#')
{
if(*ptr=='|')
*ptr='\0';
ptr++;
}
ptr=buffer;
ptr=ptr+strlen(ptr)+1;
strcpy(sk[++count],ptr);
add[count]=pos;
}
file.close();
sort();
}
void Person::sort()
{
int i,j,addlist;
char temp[20];
for(i=0;i<=count;i++)
{
for(j=i+1;j<=count;j++)
{
if(strcmp(sk[i],sk[j])>0)
{
strcpy(temp,sk[i]);
strcpy(sk[i],sk[j]);
strcpy(sk[j],temp);
addlist=add[i];
add[i]=add[j];
add[j]=addlist;
}
}
}
}
int Person :: searchn(char key[20])
{
int low=0,high=count,mid=0,flag=0;
while(low<=high)
{
mid=(low+high)/2;
if(strcmp(sk[mid],key)==0)
{
flag=1;
break;
}
if(strcmp(key,sk[mid])<0)
high=mid-1;
else
low=mid+1;
}
if(flag)
return mid;
else
return -1;
}
void Person::delfile(int pos)
{
char del='$';
int i;
fstream is;
if(pos>=0)
{
is.open("p.txt",ios::in|ios::out);
int addl=add[pos];
is.seekp(addl,ios::beg);
is<<del;
cout<<"Record DELETED !!! "<<endl;
is.close();
}
}
void Person ::remove()
{
char key[30];
fstream is;
cout<<"ENTER THE NAME :: "<<endl;
cin>>key;
int pos=searchn(key);
if(pos>=0)
{
readf(pos);
delfile(pos);
int t=pos;
while(strcmp(sk[++t],key)==0 && t<=count)
{
readf(t);
delfile(t);
}
t=pos;
while(strcmp(sk[--t],key)==0)
{
readf(t);
delfile(t);
}
}
else
cout<<"Record Not Found!!! "<<endl;
}
void Person::readf(int pos)
{
fstream file;
file.open("p.txt",ios::in);
int addl=add[pos];
file.seekp(addl,ios::beg);
file.getline(buffer,'#');
cout<<"\n RECORD FOUND !!! "<<buffer;
file.close();
}
void Person::search()
{
int pos=0,t;
char key[20];
fstream file;
cout<<"\n ENTER THE NAME TO BE SEARCH : " ;
cin>>key;
pos=searchn(key);
if(pos>=0)
{
readf(pos);
t=pos;
while(strcmp(sk[++t],key)==0 && t<=count)
readf(t);
t=pos;
while(strcmp(sk[--t],key)==0 && t<=count)
readf(t);
}
else
cout<<"Record Not Found!!! "<<endl;
}
void main()
{
int choice = 1;
clrscr();
Person ob;
while(choice < 4)
{
ostream&flush();
cout<<"1> Insert A Record "<<endl;
cout<<"2> Search For A Record "<<endl;
cout<<"3> Delete A Record "<<endl;
cout<<"4> Exit "<<endl;
cin>> choice;
switch(choice)
{
case 1: ob.input();
ob.pack();
ob.Write();
break;
case 2:
ob.creatind();
ob.search();
break;
case 3:
ob.creatind();
ob.remove();
break;

}
} getch();
}