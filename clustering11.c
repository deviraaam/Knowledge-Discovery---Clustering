#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,l,b,a,ranking[200][200],iterasi,loop;
    float I[200][200],c[20][20],jarak[200],rank[5],jumlah[5],mean1[200][200],mean2[200][200],mean3[200][200], mean[200][200];

    I[1][1]=89; I[1][2]=90; I[1][3]=75;
    I[2][1]=90; I[2][2]=71; I[2][3]=95;
    I[3][1]=70; I[3][2]=75; I[3][3]=80;
    I[4][1]=45; I[4][2]=65; I[4][3]=59;
    I[5][1]=65; I[5][2]=75; I[5][3]=53;
    I[6][1]=80; I[6][2]=70; I[6][3]=75;
    I[7][1]=90; I[7][2]=85; I[7][3]=81;
    I[8][1]=70; I[8][2]=70; I[8][3]=73;
    I[9][1]=96; I[9][2]=93; I[9][3]=85;
    I[10][1]=60; I[10][2]=55; I[10][3]=48;
    I[11][1]=45; I[11][2]=60; I[11][3]=58;
    I[12][1]=60; I[12][2]=70; I[12][3]=72;
    I[13][1]=85; I[13][2]=90; I[13][3]=88;
    I[14][1]=52; I[14][2]=68; I[14][3]=55;
    I[15][1]=40; I[15][2]=60; I[15][3]=70;

    c[1][1]=96; c[1][2]=93 ; c[1][3]=85;
    c[2][1]=70; c[2][2]= 75; c[2][3]=80 ;
    c[3][1]=60; c[3][2]=55 ; c[3][3]= 48;

    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
        {
            printf("c[%d][%d]= %f\n",i,j,c[i][j]);
        }
    }

    jumlah[1]=0;
    jumlah[2]=0;
    jumlah[3]=0;

    for(j=1; j<=3; j++)
    {
        for(l=1; l<=3; l++)
        {
            mean1[j][l]=0;
            mean2[j][l]=0;
            mean3[j][l]=0;
        }
    }

    loop=2;
    for(iterasi=1; iterasi<=loop; iterasi++)
    {
        jumlah[1]=0;
        jumlah[2]=0;
        jumlah[3]=0;

        for(i=1; i<=3; i++)
        {
            for(j=1; j<=3; j++)
            {
                mean[i][j]=0;
            }
        }

        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\niterasi = %d\n\n",iterasi);
    for(i=1; i<=15; i++)
    {
        for(j=1; j<=3; j++) //CLuster
        {
            jarak[j]=0;
            for(k=1; k<=3; k++) //Penjumlahan jarak
            {
                jarak[j]=jarak[j]+pow(I[i][k]-c[j][k],2);
            }
            jarak[j]=sqrt(jarak[j]);
            //printf("jarak[%d][%d]=%f\n",i,j,jarak[j]);
        }
        for(j=1; j<=3; j++)
            {
                rank[j]=1;
                for(b=1; b<=3; b++)
                    {
                        if(jarak[j]>jarak[b])
                        {
                            rank[j]++;
                        }
                    }
            }
            //printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=3; j++)
        //printf("%f\t\t %f\n",jarak[j], rank[j]);


        for(j=1; j<=3; j++)
        {
            if(rank[j]==1 && j==1)
            {
                jumlah[j]=jumlah[j]+1;
                ranking[i][j]=j;
            }
            else if(rank[j]==1 && j==2)
            {
                jumlah[j]=jumlah[j]+1;
                ranking[i][j]=j;
            }
            else if(rank[j]==1 && j==3)
            {
                jumlah[j]=jumlah[j]+1;
                ranking[i][j]=j;
            }
            else
            {
                ranking[i][j]=0;
            }
        }
    }



    //printf("\n\n");
    for(i=1; i<=3; i++)
    {
        //printf("jumlah[%d] = %f\n",i,jumlah[i]);
    }

    for(i=1; i<=15; i++)
    {
        for(j=1; j<=3; j++)
        {
            if(ranking[i][j]==1)
            {
                mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
            }
            else if(ranking[i][j]==2)
            {
                mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
            }
            else if(ranking[i][j]==3)
            {
                mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
            }
        }
    }

    //printf("\n\n");
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
        {
            //printf("mean[%d][%d] = %f\n",i,j,mean[i][j]);
        }
    }


    //printf("\n\n");
    for(i=1; i<=3; i++)
    {
        if(i==1)
        {
            for(j=1; j<=3; j++)
            {
                c[i][j]=mean[i][j]/jumlah[i];
                printf("c[%d][%d] = %f\n",i,j,c[i][j]);
            }
        }
        else if(i==2)
        {
            for(j=1; j<=3; j++)
            {
                c[i][j]=mean[i][j]/jumlah[i];
                printf("c[%d][%d] = %f\n",i,j,c[i][j]);
            }
        }
        else if(i==3)
        {
            for(j=1; j<=3; j++)
            {
                c[i][j]=mean[i][j]/jumlah[i];
                printf("c[%d][%d] = %f\n",i,j,c[i][j]);
            }
        }
    }
    }
    }

