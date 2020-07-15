#include <stdio.h>
#include <stdlib.h>
void add_screen(int main_arr[][100][100],int rows[],int cols[],int aisle[10][100],int sc);
void reserve_seat(int main_arr[][100][100]);
void get_unreserved(int main_arr[][100][100],int cols[]);
void suggest_contiguous(int main_arr[][100][100],int cols[100]);
int main()
{
    int main_arr[10][100][100],rows[100],cols[100],aisle[10][100];
    int n,cas,screencount=0;
    scanf("%d",&n);
    char str[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[0]=='a')
            cas=1;
        else if(str[0]=='r')
            cas=2;
        else if(str[0]=='g')
            cas=3;
        else if(str[0]=='s')
            cas=4;
        switch(cas)
        {
        case 1:
            {
                add_screen(main_arr,rows,cols,aisle,screencount);
                screencount++;
                break;
            }
        case 2:
            {
                reserve_seat(main_arr);
                break;
            }
        case 3:
            {
                get_unreserved(main_arr,cols);
                break;
            }
        case 4:
            {
                suggest_contiguous(main_arr,cols);
                break;
            }
        }
    }
    return 0;
}
void add_screen(int main_arr[][100][100],int rows[],int cols[],int aisle[10][100],int screencount)
{
    char str[10];
    scanf("%s",str);
    int x=str[6]-'0';
    scanf("%d",&rows[x]);
    scanf("%d",&cols[x]);
    int aiscount=0;
    char temp;
    do
    {

        scanf("%d%c",&aisle[x][aiscount],&temp);
        //printf("aisle[%d][%d]=%d\n",x,aiscount,aisle[x][aiscount]);
        aiscount++;
    }while(temp!='\n');
    aisle[x][aiscount]=-1;
    if(main_arr[x][0][0]==-1)
    {
        printf("failed, same screen already exists\n");
        return;
    }
    //printf("aisle[%d][%d]=%d\n",x,aiscount,aisle[x][aiscount]);
    //printf("rows[%d]=%d\n",x,rows[x]);
    //printf("cols[%d]=%d\n",x,cols[x]);
    for(int i=1;i<=rows[x];i++)
    {
        for(int j=1;j<=cols[x];j++)
        {
            main_arr[x][i][j]=0;
            for(int k=0;k<aiscount;k++)
            {
                if(aisle[x][k]==j)
                    main_arr[x][i][j]=1;
            }

        }
    }
    main_arr[x][0][0]=-1;
    /*for(int i=1;i<=rows[x];i++)
    {
        for(int j=1;j<=cols[x];j++)
        {
            printf("%d ",main_arr[x][i][j]);
        }
        printf("\n");
    }*/
    printf("succesfully added screen\n");

}
void reserve_seat(int main_arr[][100][100])
{
    char str[10];
    scanf("%s",str);
    int rownum,seats[100],sc=0;
    int x=str[6]-'0';
    //printf("x=%d",x);
    scanf("%d",&rownum);
    //printf("row no = %d",rownum);
    int seatscount=0;
    char temp;
    do
    {
        scanf("%d%c",&seats[seatscount],&temp);
        //printf("seats[%d]=%d\n",seatscount,seats[seatscount]);
        seatscount++;
    }while(temp!='\n');
    //printf("seat count=%d",seatscount);
    if(main_arr[x][0][0]!=-1)
    {
        printf("failed, no such screen available\n");
        return;
    }
    for(int i=0;i<seatscount;i++)
    {
        if(main_arr[x][rownum][seats[i]]==9)
        {
            printf("failed\n");
            return;
        }
    }
    for(int i=0;i<seatscount;i++)
    {
        main_arr[x][rownum][seats[i]]=9;
    }
    /*for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=10;j++)
        {
            printf("%d ",main_arr[x][i][j]);
        }
        printf("\n");
    }*/
    printf("successfully reserved\n");

}
void get_unreserved(int main_arr[][100][100],int cols[])
{
    char str[10];
    scanf("%s",str);
    int rownum,seats[100],sc=0;
    int x=str[6]-'0';
    int col=cols[x];
    //printf("x=%d,cols=%d",x,col);
    scanf("%d",&rownum);
    //printf("row no = %d",rownum);
    if(main_arr[x][0][0]!=-1)
    {
        printf("failed, no such screen available\n");
        return;
    }
    for(int i=1;i<=col;i++)
    {
        if(main_arr[x][rownum][i]!=9)
            printf("%d ",i);
    }
    printf("\n");
}
void suggest_contiguous(int main_arr[][100][100],int cols[])
{
    char str[10];
    scanf("%s",str);
    int x=str[6]-'0';
    int numseats=0;
    scanf("%d",&numseats);
    //printf("num of seats=%d\n",numseats);
    int rownum;
    scanf("%d",&rownum);
    //printf("row no = %d\n",rownum);
    int col=cols[x];
    //printf("max col =%d\n",col);
    int pref,j,cond1=0,cond2=0;
    scanf("%d",&pref);
    if(main_arr[x][0][0]!=-1)
    {
        printf("failed, no such screen available\n");
        return;
    }
    //printf("pref=%d\n",pref);
    int i,k;
    if(col-pref>numseats)
    {
        int sc=0;
    for(i=pref,j=pref+1;sc<numseats&&i<=col;j++,i++,sc++)
    {
        if(main_arr[x][rownum][i]==1 &&main_arr[x][rownum][j]==1 || main_arr[x][rownum][i]==9)
        {
            //printf("\n\n++cond check main_arr[x][rownum][i]=%d main_arr[x][rownum][j]=%d main_arr[x][rownum][i]=%d\n",main_arr[x][rownum][i],main_arr[x][rownum][j],main_arr[x][rownum][i]);
            cond1=1;
            break;
        }
    }
    if(cond1!=1)
    {
        for(int i=pref,j=0;j<numseats;j++,i++)
        {
        printf("%d ",i);
        }
        printf("\n");
        return ;
    }
    }
    if(pref-0>numseats)
    {
        int scou=0;
    for(j=pref,k=pref-1;scou<numseats&&j>0;k--,j--,scou++)
    {
        if(main_arr[x][rownum][j]==1 && main_arr[x][k]==1|| main_arr[x][rownum][j]==9)
        {
            //printf("\n\n--cond check main_arr[x][rownum][i]=%d main_arr[x][rownum][j]=%d main_arr[x][rownum][i]=%d",main_arr[x][rownum][j],main_arr[x][rownum][k],main_arr[x][rownum][j]);
            cond2=1;
            break;
        }
    }
    if(cond2!=1)
    {
        for(int i=pref,j=0;j<numseats;j++,i--)
        {
        printf("%d ",i);
        }
        printf("\n");
        return ;
    }
    }
    if(cond1==1&&cond2==1 || col-pref<numseats || pref-0<numseats)
    {
        printf("none\n");
    }
}
