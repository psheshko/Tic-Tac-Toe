#include <stdio.h>
#include <stdlib.h>

int field[3][3];

int ClearingField()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            field[i][j]=0;
        }
    }
    return 0;
}

int Canvas()
{
    printf("\n    0 1 2\n");
    for(int i=0;i<3;i++)
    {
        printf(" %d ", i);
        for(int j=0;j<3;j++)
        {
            if(field[i][j]==0)
            {
                printf("|_");
            }
            if(field[i][j]==1)
            {
                printf("|X");
            }
            if(field[i][j]==2)
            {
                printf("|O");
            }
        }
    printf("|\n");
    }
    return 0;
}

int PlayerMove()
{
    int moveline;
    int movecolumn;
    int correctnessmove = 0;
    while (correctnessmove==0)
    {
        printf("Enter the line number\n");
        scanf("%d", &moveline);
        fflush(stdin);
        printf("Enter the column number\n");
        scanf("%d", &movecolumn);
        fflush(stdin);
        if (field[moveline][movecolumn]==0&&\
            ((moveline==0&&movecolumn==0)||(moveline==0&&movecolumn==1)||(moveline==0&&movecolumn==2)||\
             (moveline==1&&movecolumn==0)||(moveline==1&&movecolumn==1)||(moveline==1&&movecolumn==2)||\
             (moveline==2&&movecolumn==0)||(moveline==2&&movecolumn==1)||(moveline==2&&movecolumn==2)))
                                             {
                                                correctnessmove = 1;
                                             }
        else
        {
            printf("Incorrect move entered, try again\n");
        }
    }
    field[moveline][movecolumn] = 1;
    return 0;
}

int CloseToPlayersVictory()
{
    int i,j,k;
    int flag = 0;
    for(i=0;i<3;i++)
    {
        j=0;
        k=1;
        if((field[i][j]==1)&&(field[i][k]==1)&&(field[i][k+1]==0))
        {
            field[i][k+1]=2;
            flag=1;
            return flag;
        }
        j=1;
        k=2;
        if((field[i][j]==1)&&(field[i][k]==1)&&(field[i][j-1]==0))
        {
            field[i][j-1]=2;
            flag=1;
            return flag;
        }
        j=0;
        k=2;
        if((field[i][j]==1)&&(field[i][k]==1)&&(field[i][k-1]==0))
        {
            field[i][k-1]=2;
            flag=1;
            return flag;
        }
    }
    for(j=0;j<3;j++)
    {
        i=0;
        k=1;
        if((field[i][j]==1)&&(field[k][j]==1)&&(field[k+1][j]==0))
        {
            field[k+1][j]=2;
            flag=1;
            return flag;
        }
        i=1;
        k=2;
        if((field[i][j]==1)&&(field[k][j]==1)&&(field[i-1][j]==0))
        {
            field[i-1][j]=2;
            flag=1;
            return flag;
        }
        i=0;
        k=2;
        if((field[i][j]==1)&&(field[k][j]==1)&&(field[k-1][j]==0))
        {
            field[k-1][j]=2;
            flag=1;
            return flag;
        }
    }

    if((field[0][0]==1)&&(field[1][1]==1)&&(field[2][2]==0))
    {
        field[2][2]=2;
        flag = 1;
        return flag;
    }
    if((field[1][1]==1)&&(field[2][2]==1)&&(field[0][0]==0))
    {
        field[0][0]=2;
        flag = 1;
        return flag;
    }
    if((field[0][0]==1)&&(field[2][2]==1)&&(field[1][1]==0))
    {
        field[1][1]=2;
        flag = 1;
        return flag;
    }
    if((field[2][0]==1)&&(field[1][1]==1)&&(field[0][2]==0))
    {
        field[0][2]=2;
        flag = 1;
        return flag;
    }
    if((field[2][0]==1)&&(field[0][2]==1)&&(field[1][1]==0))
    {
        field[1][1]=2;
        flag = 1;
        return flag;
    }
    if((field[1][1]==1)&&(field[0][2]==1)&&(field[2][0]==0))
    {
        field[2][0]=2;
        flag = 1;
        return flag;
    }

    return flag;

}

int CloseToComputersVictory()
{
    int i,j,k;
    int flag = 0;
    for(i=0;i<3;i++)
    {
        j=0;
        k=1;
        if((field[i][j]==2)&&(field[i][k]==2)&&(field[i][k+1]==0))
        {
            field[i][k+1]=2;
            flag=1;
            return flag;
        }
        j=1;
        k=2;
        if((field[i][j]==2)&&(field[i][k]==2)&&(field[i][j-1]==0))
        {
            field[i][j-1]=2;
            flag=1;
            return flag;
        }
        j=0;
        k=2;
        if((field[i][j]==2)&&(field[i][k]==2)&&(field[i][k-1]==0))
        {
            field[i][k-1]=2;
            flag=1;
            return flag;
        }
    }
    for(j=0;j<3;j++)
    {
        i=0;
        k=1;
        if((field[i][j]==2)&&(field[k][j]==2)&&(field[k+1][j]==0))
        {
            field[k+1][j]=2;
            flag=1;
            return flag;
        }
        i=1;
        k=2;
        if((field[i][j]==2)&&(field[k][j]==2)&&(field[i-1][j]==0))
        {
            field[i-1][j]=2;
            flag=1;
            return flag;
        }
        i=0;
        k=2;
        if((field[i][j]==2)&&(field[k][j]==2)&&(field[k-1][j]==0))
        {
            field[k-1][j]=2;
            flag=1;
            return flag;
        }
    }

    if((field[0][0]==2)&&(field[1][1]==2)&&(field[2][2]==0))
    {
        field[2][2]=2;
        flag = 1;
        return flag;
    }
    if((field[1][1]==2)&&(field[2][2]==2)&&(field[0][0]==0))
    {
        field[0][0]=2;
        flag = 1;
        return flag;
    }
    if((field[0][0]==2)&&(field[2][2]==2)&&(field[1][1]==0))
    {
        field[1][1]=2;
        flag = 1;
        return flag;
    }
    if((field[2][0]==2)&&(field[1][1]==2)&&(field[0][2]==0))
    {
        field[0][2]=2;
        flag = 1;
        return flag;
    }
    if((field[2][0]==2)&&(field[0][2]==2)&&(field[1][1]==0))
    {
        field[1][1]=2;
        flag = 1;
        return flag;
    }
    if((field[1][1]==2)&&(field[0][2]==2)&&(field[2][0]==0))
    {
        field[2][0]=2;
        flag = 1;
        return flag;
    }

    return flag;
}


int ComputerMove()
{
    if(CloseToComputersVictory()==0)
    {
        if(CloseToPlayersVictory()==0)
        {
            int moveline;
            int movecolumn;
            int correctnessmove = 0;
            time_t CurrentTime = time(NULL);
            if(CurrentTime == -1)
            {
                return 2; //ошибка времени
            }
            srand(CurrentTime);
            while (correctnessmove==0)
            {
                moveline = rand()%3;
                movecolumn = rand()%3;
                if ((field[moveline][movecolumn]==0)&&\
                    (((moveline==0)&&(movecolumn==0))||((moveline==0)&&(movecolumn==1))||((moveline==0)&&(movecolumn==2))||\
                     ((moveline==1)&&(movecolumn==0))||((moveline==1)&&(movecolumn==1))||((moveline==1)&&(movecolumn==2))||\
                     ((moveline==2)&&(movecolumn==0))||((moveline==2)&&(movecolumn==1))||((moveline==2)&&(movecolumn==2))))
                                                     {
                                                        correctnessmove = 1;
                                                        field[moveline][movecolumn] = 2;
                                                     }


            }
        }
    }
    return 0;
}

int wincheck()
{
    int result = 0;
    for(int i=0;i<3;i++)
    {
        if ((field[i][0]==1)&&(field[i][1]==1)&&(field[i][2]==1))result = 1;
    }
    for(int i=0;i<3;i++)
    {
        if ((field[0][i]==1)&&(field[1][i]==1)&&(field[2][i]==1))result = 1;
    }
    if((field[0][0]==1)&&(field[1][1]==1)&&(field[2][2]==1))result = 1;
    if((field[0][2]==1)&&(field[1][1]==1)&&(field[2][0]==1))result = 1;


    for(int i=0;i<3;i++)
    {
        if ((field[i][0]==2)&&(field[i][1]==2)&&(field[i][2]==2))result = 2;
    }
    for(int i=0;i<3;i++)
    {
        if ((field[0][i]==2)&&(field[1][i]==2)&&(field[2][i]==2))result = 2;
    }
    if((field[0][0]==2)&&(field[1][1]==2)&&(field[2][2]==2))result = 2;
    if((field[0][2]==2)&&(field[1][1]==2)&&(field[2][0]==2))result = 2;

    return result;
}

int drawcheck()
{
    int counter = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (field[i][j]!=0)
            {
                counter++;
            }
        }
    }
    if (counter == 9)
    {
        return 9;
    }
    return 0;
}

int main()
{

    int checkrestart = 1;
    while (checkrestart==1)
        {
        int game=0;
        ClearingField();
        printf("Tic-Tac-Toe\n");
        Canvas();
        while (game==0)
        {
            PlayerMove();
            Canvas();
            game = wincheck();
            if(wincheck()!=0)
            {
                break;
            }
            if(drawcheck()==9)
            {
                break;
            }
            ComputerMove();
            Canvas();
            game = wincheck();
            if(wincheck()!=0)
            {
                break;
            }
            if(drawcheck()==9)
            {
                break;
            }
        }
        if(game == 0)printf("\nDRAW\n\n");
        if(game == 1)printf("\nYou win! Congratulations\n\n");
        if(game == 2)printf("\nComputer win\n\n");

        printf("Do you want to restart the game?\n0.NO     1.YES\n");
        scanf("%d",&checkrestart);
        fflush(stdin);
        while(checkrestart<0 || checkrestart>1)
            {
            printf("Incorrect answer, try again\n");
            printf("Do you want to restart the game?\n0.NO     1.YES\n");
            scanf("%d",&checkrestart);
            fflush(stdin);
            }
        }
    return 0;
}
