#include <stdio.h>
#include <string.h>
int max_ele(int x,int y,int z)
{
    if(x>y)
    {
        if(x>z)
        {return x;}
        else
        {return z;}
    }
    else
    {
        if(y>z)
        {return y;}
        else
        {return z;}
    }
}
int main()
{
    char s1[100];
    char s2[100];
    printf("Enter String1:");
    scanf("%s",s1);
    
    printf("Enter String2:");
    scanf("%s",s2);
    
    int adj_mat[strlen(s1)+1][strlen(s1)+1];
    for(int i=0;i<strlen(s1)+1;i++)
    {for(int j=0;j<strlen(s1)+1;j++)
        {adj_mat[i][j]=0;}}
    
    int max=-1;
    int row=0;int col=0;
    for(int i=1;i<strlen(s1)+1;i++)
    {
        for(int j=1;j<strlen(s1)+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                adj_mat[i][j] = adj_mat[i-1][j-1] + 2;
                if(max<adj_mat[i][j])
                {
                    max = adj_mat[i][j];row=i;col=j;
                }
            }
            else
            {
                adj_mat[i][j] = max_ele(adj_mat[i][j-1]-1,adj_mat[i-1][j]-1,adj_mat[i-1][j-1]-1);
            }
        }
    }
    for(int i=0;i<strlen(s1)+1;i++)
    {
        for(int j=0;j<strlen(s1)+1;j++)
        {
            printf("%d\t",adj_mat[i][j]);
        }
        printf("\n");
    }
    char ans1[100];
    char ans2[100];
    int c=0;
    while(row!=0 && col!=0)
    {
        if(s1[row-1]==s2[col-1])
        {
            printf("%d\t%d\t%d\n",adj_mat[row][col],row,col);
            ans1[c]=s1[row-1];ans2[c]=s2[row-1];c++;
            row=row-1;
            col=col-1;
        }
        else if(s1[row-1]==s2[col-2])
        {
            printf("%d\t%d\t%d\n",adj_mat[row][col],row,col);
            ans1[c]='_';ans2[c]=s2[col-1];c++;
            ans1[c]=s1[row-1];ans2[c]=s2[col-2];c++;
            col=col-1;
        }
        else if(s1[row-2]==s2[col-1])
        {
            printf("%d\t%d\t%d\n",adj_mat[row][col],row,col);
            ans1[c]=s1[row-1];ans2[c]='_';c++;
            ans1[c]=s1[row-2];ans2[c]=s2[col-1];c++;
            row=row-1;
        }
    }
    printf("Answer String\n");
    for(int i=0;i<c;i++)
    {
        printf("%c\t%c\n",ans1[i],ans2[i]);
    }
    return 0;
}




