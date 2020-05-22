#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
class Merge
{
char list[9][30][20];
char outputlist[270][20];
int k,count;
int size[9];
int index[9];
public:
void sort(char l[30][20],int s);
void merge();
void read(char temp[30]);
void load(char filename[20]);
char* minValue();
void display();
};
void Merge::read(char temp[30])
{
int n;
char name[20];
fstream fs;
fs.open(temp,ios::out|ios::app);
cout<<"Enter hoW many name for list one: ";
cin>>n;
for(int i=0;i<n;i++)
{
fflush(stdin);
cin>>name;
fs<<name<<endl;
}
fs.close();
}
void Merge :: load(char filename[20])
{
k = 8;
char temp[30],buf[10];
fstream file;
memset(size,0,sizeof(size));
memset(index,0,sizeof(index));
for(int i=1; i<=k;i++)
{
strcpy(temp,filename);
sprintf(buf,"%d",i);
strcat(temp,buf);
strcat(temp,".txt");
read(temp);
file.open(temp,ios::in);
while(!file.eof())
{
file.getline(temp,'\n');
if(file.eof())
break;
strcpy(list[i][size[i]],temp);
size[i]++;
}
file.close();
sort(list[i],size[i]);
}
}
void Merge :: merge()
{
count = 0;
char *value = minValue();
while(value != NULL)
{
for(int i = 1; i<= k; i++)
{
if(index[i]>= size[i])
continue;
if(strcmp(value,list[i][index[i]]) == 0)
index[i]++;
}
strcpy(outputlist[count],value);
count++;
value = minValue();
}
}
char* Merge :: minValue()
{
int t = 1;
char *value = NULL;
while(index[t] >= size[t] && t <= k)
t++;
if( t <= k)
{
value = list[t][index[t]];
for(int i = t+1; i <= k; i++)
if(strcmp(value,list[i][index[i]]) > 0 && index[i]<size[i])
value = list[i][index[i]];
}
return value;
}
void Merge :: sort(char l[30][20],int s)
{
char temp[20];
for(int i = 0; i < s; i++)
{
for(int j=i+1; j<s;j++)
{
if(strcmp(l[i],l[j]) > 0)
{
strcpy(temp,l[i]);
strcpy(l[i],l[j]);
strcpy(l[j],temp);
}
}
}
}
void Merge ::display()
{
for(int i= 0; i < count; i++)
cout<<outputlist[i]<<" ";
}
void main()
{
Merge m;
char filename[]="list";
clrscr();
m.load(filename);
m.merge();
cout<<"\nNames in sorted order is :";
m.display();
getch();
}