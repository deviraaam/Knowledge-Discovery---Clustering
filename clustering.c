#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,nI,nC,b;
    float I[100][100], C[100][100],jarak[100],rank[100],mean[100][100],jumlah[5];
    /*
    printf("Masukkan jumlah input = ");
    scanf("%d",&nI);
    printf("Masukkan jumlah centroid = ");
    scanf("%d",&nC);

    for(i=1; i<=nI; i++)
    {
        printf("I[%d][1]=",i);
        scanf("%f",&I[i][1]);
        printf("I[%d][2]=",i);
        scanf("%f",&I[i][2]);
    }
    for(i=1; i<=nC; i++)
    {
        printf("C[%d][1]=",i);
        scanf("%f",&C[i][1]);
        printf("C[%d][2]=",i);
        scanf("%f",&C[i][2]);
    }
    */

    nI=6;
    nC=2;

    I[1][1]=100; I[1][2]=50;
    I[2][1]=40; I[2][2]=60;
    I[3][1]=30; I[3][2]=70;
    I[4][1]=90; I[4][2]=10;
    I[5][1]=65; I[5][2]=40;
    I[6][1]=25; I[6][2]=35;

    C[1][1]=100; C[1][2]=50;
    C[2][1]=40; C[2][2]=60;

    //Euclidean
    jumlah[1]=0;
    jumlah[2]=0;
    mean[1][1]=0;
    mean[1][2]=0;
    mean[2][1]=0;
    mean[2][2]=0;
    for(i=1; i<=nI; i++)
    {
        for(j=1; j<=nC; j++)
        {
            jarak[j]=sqrt(pow(I[i][1]-C[j][1],2)+pow(I[i][2]-C[j][2],2));
            printf("jarak[%d] = %f\n",j,jarak[j]);
        }
        for(j=1; j<=nC; j++)
            {
                rank[j]=1;
                for(b=1; b<=nC; b++)
                    {
                        if(jarak[j]>jarak[b])
                        {
                            rank[j]++;
                        }
                    }
            }
            printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=nC; j++)
        printf("%f\t\t %f\n",jarak[j], rank[j]);

        for(j=1; j<=nC; j++)
        {
            if(rank[j]==1&&j==1)
            {
                jumlah[1]=jumlah[1]+1;
            }
            else if(rank[j]==1&&j==2)
            {
                jumlah[2]=jumlah[2]+1;
            }
        }


        for(j=1; j<=nC; j++)
        {
            if(rank[j]==1&&j==1)
            {
                //jumlah[1]=jumlah[1]+1;
                //printf("jumlah[1]= %f\n",jumlah[1]);
                mean[1][1]=mean[1][1]+I[i][1];
                mean[1][2]=mean[1][2]+I[i][2];
                printf("mean[1][1] = %f\n",mean[1][1]);
                printf("mean[1][2] = %f\n",mean[1][2]);
            }
            else if(rank[j]==1&&j==2)
            {
                //jumlah[2]=jumlah[2]+1;
                //printf("jumlah[2]= %f\n",jumlah[2]);
                mean[2][1]=mean[2][1]+I[i][1];
                mean[2][2]=mean[2][2]+I[i][2];
                printf("mean[2][1] = %f\n",mean[2][1]);
                printf("mean[2][2] = %f\n",mean[2][2]);
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("mean[1][1] = %f\n",mean[1][1]);
    printf("mean[1][2] = %f\n",mean[1][2]);
    printf("mean[2][1] = %f\n",mean[2][1]);
    printf("mean[2][2] = %f\n",mean[2][2]);
    for(i=1; i<=nC; i++)
    {
        for(j=1; j<=nC; j++)
        {
            mean[i][j]=mean[i][j]/jumlah[i];
        }
    }
    printf("jumlah[1]= %f\n",jumlah[1]);
    printf("jumlah[2]= %f\n",jumlah[2]);
    printf("mean[1][1] = %f\n",mean[1][1]);
    printf("mean[1][2] = %f\n",mean[1][2]);
    printf("mean[2][1] = %f\n",mean[2][1]);
    printf("mean[2][2] = %f\n",mean[2][2]);


}
