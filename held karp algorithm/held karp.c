#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

int main()
{
    int l =0;
    clock_t t;


    //time_t seconds;

    char ans[31][31];
    int a[10][10]={
        {0,1,15,6,5,4},
        {2,0,7,3,3,8},
        {9,6,0,12,7,6},
        {10,4,8,0,8,9},
        {6,3,8,9,0,4},
        {1,15,11,10,5,0}
            };

    for (int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
            {
            printf("%d",a[i][j]);
            printf(" ");
            }
        printf("\n");
    }


    int n;
    printf("enter number of cities");
    scanf("%d",&n);

    if(n==0||n==1||n==2)
    {
        printf("enter cities greater than 2");
    }
    else if(n==3)
    {
    int a01,a02,a21,a12,a123;
//subsets= [1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
    a01= a[0][1];
    a02= a[0][2];
//a03= a[0][3]
    a21=a01+a[1][2];
    a12=a02+a[2][1];
    //a123 = (a21+a[2][0]>a12+a[1][0]) ? a12+a[1][0] : a21+a[2][0];
    if(a21+a[2][0]>a12+a[1][0])
    {
        a123=a12+a[1][0];
        printf("%d",a123);
        printf("\n");
        printf("0->2->1->0");
    }
    else
    {
        a123=a21+a[2][0];
        printf("%d",a123);
        printf("\n");
        printf("0->1->2->0");

    }
    }

    else if (n==4)
    {
        int a01,a02,a03,a21,a31,a12,a32,a13,a23,a321,a231,a123;

    a01= a[0][1];
    a02= a[0][2];
    a03= a[0][3];
    a21=a01+a[1][2];
    a31=a01+a[1][3];
    a12=a02+a[2][1];
    a32=a02+a[2][3];
    a13=a03+a[3][1];
    a23=a03+a[3][2];

    //a312 or a321 final a321

    if(a12+a[1][3]>a[2][3]+a21)
    {
        a321=a[2][3]+a21;
        //ans[l][]="3<-2<-1";
        strcpy(ans[l],"3<-2<-1");
    }
    else
    {
        a321=a12+a[1][3];
        //ans[++l][0]="3<-1<-2";
        strcpy(ans[++l],"3<-1<-2");
    }
    //

    //a213 or a231 final a231
    if(a13+a[1][2]>a31+a[3][2])
    {
        a231=a31+a[3][2];
        //ans[++l][0]="2<-3<-1";
        strcpy(ans[++l],"2<-3<-1");
    }
    else
    {
        a231=a13+a[1][2];
        //ans[++l][0]="2<-1<-3";
        strcpy(ans[++l],"2<-1<-3");

    }

    //a123 pr a132 final a123
    if(a23+a[2][1]>a32+a[3][1])
    {
        a123=a32+a[3][1];
        //ans[++l][0]="1<-3<-2";
        strcpy(ans[++l],"1<-3<-2");
    }
    else
    {
        a123=a23+a[2][1];
        //5ans[++l][0]="1<-2<-3";
        strcpy(ans[++l],"1<-2<-3");

    }


    if(a321+a[3][0]<a231+a[2][0]&&a321+a[3][0]<a123+a[1][0])
    {
        printf("Shortest Distance = ");
        printf("%d",a321+a[3][0]);
        printf("\n");
        printf("0<-");
        printf("%s",ans[0]);
        printf("<-0");


    }
    else if(a321+a[3][0]>a231+a[2][0] && a231+a[2][0]<a123+a[1][0])
    {
        printf("Shortest Distance = ");
        printf("%d",a231+a[2][0]);
        printf("\n");
        printf("0<-");
        printf("%s",ans[1]);
        printf("<-0");
    }
    else if(a321+a[3][0]>a123+a[1][0] && a231+a[2][0]>a123+a[1][0])
    {
        printf("Shortest Distance = ");
        printf("%d",a123+a[1][0]);
        printf("\n");
        printf("0<-");
        printf("%s",ans[2]);
        printf("<-0");

    }


    }

    else if (n==5)
    {

        char ans1[15][15];
        int a01,a02,a03,a21,a31,a12,a32,a13,a23,a312,a231,a123;
        int a04, a41,a42,a43,a34,a14,a24,a314,a214,a134,a324,a234,a124,a413,a423,a412,a213;
        int a1234,a2134,a3124,a4123;
        a01= a[0][1];
        a02= a[0][2];
        a03= a[0][3];
        a04= a[0][4];

        a21=a01+a[1][2];
        a31=a01+a[1][3];
        a41=a01+a[1][4];

        a12=a02+a[2][1];
        a32=a02+a[2][3];
        a42=a02+a[2][4];

        a13=a03+a[3][1];
        a23=a03+a[3][2];
        a43=a03+a[3][4];

        a14=a04+a[4][1];
        a24=a04+a[4][2];
        a34=a04+a[4][3];



        //a312 or a321 final a312

        if(a12+a[1][3]>a[2][3]+a21)
        {
            a312=a[2][3]+a21;
            //ans[l][]="3<-2<-1";
            strcpy(ans[l],"3<-2<-1");
        }
        else
        {
            a312=a12+a[1][3];
            //ans[++l][0]="3<-1<-2";
            strcpy(ans[++l],"3<-1<-2");
        }

        //a314 or a341 final a314
        if(a14+a[1][3]>a41+a[4][3])
        {
            a314=a41+a[4][3];
            strcpy(ans[++l],"3<-4<-1");
        }
        else
        {
            a314=a14+a[1][3];
            strcpy(ans[++l],"3<-1<-4");
        }

        //a324 or a342 final a324
        if(a24+a[2][3]>a42+a[4][3])
        {
            a324=a42+a[4][3];
            strcpy(ans[++l],"3<-4<-2");
        }
        else
        {
            a324=a24+a[2][3];
            strcpy(ans[++l],"3<-2<-4");
        }
        //a213 or a231 final a213
        if(a13+a[1][2]>a31+a[3][2])
        {
            a213=a31+a[3][2];
            //ans[++l][0]="2<-3<-1";
            strcpy(ans[++l],"2<-3<-1");
        }
        else
        {
            a231=a13+a[1][2];
            //ans[++l][0]="2<-1<-3";
            strcpy(ans[++l],"2<-1<-3");

        }

         //a214 or a241 final a214
        if(a14+a[1][2]>a41+a[4][2])
        {
            a214=a41+a[4][2];
            strcpy(ans[++l],"2<-4<-1");


        }

        else
        {
            a214=a14+a[1][2];
            strcpy(ans[++l],"2<-1<-4");
        }

        //a234 or a243 final a234
        if(a34+a[3][2]>a43+a[4][2])
        {
            a234=a43+a[4][2];
            strcpy(ans[++l],"2<-4<-3");
        }
        else
        {
            a234=a34+a[3][2];
            strcpy(ans[++l],"2<-3<-4");
        }
        //a123 pr a132 final a123
        if(a23+a[2][1]>a32+a[3][1])
        {
            a123=a32+a[3][1];


            //ans[++l][0]="1<-3<-2";
            strcpy(ans[++l],"1<-3<-2");
        }
        else
        {
            a123=a23+a[2][1];
            //5ans[++l][0]="1<-2<-3";
            strcpy(ans[++l],"1<-2<-3");


        }

        //a124 or a142 final a124
        if(a24+a[2][1]>a42+a[4][1])
        {
            a124=a42+a[4][1];
            strcpy(ans[++l],"1<-4<-2");

        }
        else
        {
            a124=a24+a[2][1];
            strcpy(ans[++l],"1<-2<-4");



        }

        //a134 or a143 final a134
        if(a34+a[3][1]>a43+a[4][1])
        {
            a134=a43+a[4][1];
            strcpy(ans[++l],"1<-4<-3");
        }
        else
        {
            a134=a34+a[3][1];
            strcpy(ans[++l],"1<-3<-4");
        }

        //a413 or a431 final a413
        if(a13+a[1][4]>a31+a[3][4])
        {
            a413=a31+a[3][4];
            strcpy(ans[++l],"4<-3<-1");
        }
        else
        {
            a413=a13+a[1][4];
            strcpy(ans[++l],"4<-1<-3");
        }

        //a423 or a432 final a423
        if(a23+a[2][4]>a32+a[3][4])
        {
            a423=a32+a[3][4];
            strcpy(ans[++l],"4<-3<-2");
        }
        else
        {
            a423=a23+a[2][4];
            strcpy(ans[++l],"4<-2<-3");
        }

        //a412 or a421 final a412
        if(a12+a[1][4]>a21+a[2][4])
        {
            a412=a21+a[2][4];
            strcpy(ans[++l],"4<-2<-1");

        }
        else
        {
            a412=a12+a[1][4];
            strcpy(ans[++l],"4<-1<-2");
        }

        int t=0;

        //a1234 or a1324 or a1423  final a1234
        if(a234+a[2][1]<a324+a[3][1] && a234+a[2][1]<a423+a[4][1])
        {
            a1234=a234+a[2][1];
            char temp[15]="1<-";
            strcat(temp,ans[5]);
            strcpy(ans1[t],temp);


        }
        else if(a324+a[3][1]<a234+a[2][1] && a324+a[3][1]<a423+a[4][1])
        {
            a1234=a324+a[3][1];
            char temp[15]="1<-";
            strcat(temp,ans[2]);
            strcpy(ans1[t],temp);
        }
        else
        {
            a1234=a423+a[4][1];
            char temp[15]="1<-";
            strcat(temp,ans[10]);
            strcpy(ans1[t],temp);
        }

        //a2134 or a2314 or a2413 final a2134
        if(a134+a[1][2]<a314+a[3][2] && a134+a[1][2]<a413+a[4][2])
        {
            a2134=a134+a[1][2];
            char temp[15]="2<-";
            strcat(temp,ans[8]);
            strcpy(ans1[++t],temp);
        }
        else if (a314+a[3][2]<a134+a[1][2] && a314+a[3][2]<a413+a[4][2])
        {
            a2134=a314+a[3][2];
            char temp[15]="2<-";
            strcat(temp,ans[1]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a2134=a413+a[4][2];
            char temp[15]="2<-";
            strcat(temp,ans[9]);
            strcpy(ans1[++t],temp);
        }
        //a3124 or a3214 or a3412 final a3124
        if(a124+a[1][3]<a214+a[2][3] && a124+a[1][3]< a412+a[4][3])
        {
            a3124=a124+a[1][3];

            char temp[15]="3<-";
            strcat(temp,ans[7]);
            strcpy(ans1[++t],temp);
            //printf("%d",a3124);
        }
        else if(a214+a[2][3]<a124+a[1][3] && a214+a[2][3]<a412+a[4][3])
        {
            a3124=a214+a[2][3];
            char temp[15]="3<-";
            strcat(temp,ans[4]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a3124=a412+a[4][3];
            char temp[15]="3<-";
            strcat(temp,ans[11]);
            strcpy(ans1[++t],temp);
        }

        //a4123 or a4213 or a4312 final a4123
        if(a123+a[1][4]<a213+a[2][4] && a123+a[1][4]<a312+a[3][4])
        {
            a4123=a123+a[1][4];
            char temp[15]="4<-";
            strcat(temp,ans[6]);
            strcpy(ans1[++t],temp);
        }
        else if(a213+a[2][4]<a123+a[1][4] && a213+a[2][4]<a312+a[3][4])
        {
            a4123=a213+a[2][4];
            char temp[15]="4<-";
            strcat(temp,ans[3]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a4123=a312+a[3][4];
            char temp[15]="4<-";
            strcat(temp,ans[0]);
            strcpy(ans1[++t],temp);
        }



        //a01234 or a02134 or a03124 or a04123 final a01234
         if(a1234+a[1][0]<a2134+a[2][0] && a1234+a[1][0]<a3124+a[3][0] && a1234+a[1][0]<a4123+a[4][0])
         {
             printf("%s %d","Shortest Distance =",(a1234+a[1][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans1[0],"<-0");
             printf("\n");

         }
         else if(a2134+a[2][0]<a1234+a[1][0] && a2134+a[2][0]<a3124+a[3][0] && a2134+a[2][0]<a4123+a[4][0])
         {
             printf( "%s %d","Shortest Distance =",(a2134+a[2][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans1[1],"0<-");
             printf("\n");

         }
         else if(a3124+a[3][0]<a2134+a[2][0] && a3124+a[3][0]<a1234+a[1][0] && a3124+a[3][0]<a4123+a[4][0])
         {
             printf("%s %d","Shortest Distance =",(a3124+a[3][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans1[2],"<-0");
             printf("\n");

         }

         else if (a4123+a[4][0]<a2134+a[2][0]&& a4123+a[4][0]<a1234+a[1][0]&& a4123+a[4][0]<a3124+a[3][0])
         {
             printf("%s %d","Shortest Distance =",(a4123+a[4][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans1[3],"<-0");
             printf("\n");

         }





    }

    else if (n==6)
    {
    t = clock();


        char ans1[20][20];
int a01,a02,a03,a21,a31,a12,a32,a13,a23,a04,a05,a41,a42,a43,a34,a14,a24,a51,a52,a53,a54,a25,a15,a35,a45;
int a314,a214,a134,a324,a234,a124,a413,a423,a412,a213,a312,a231,a123,a125,a135,a145,a215,a235,a245,a315,a325,a345,a415,a425,a435,a512,a513,a514,a523,a524,a534;
int a1234,a2134,a3124,a4123,a1235,a1345,a1245,a2135,a2345,a3125,a3245,a4125,a4235,a4135,a5123,a5124,a5234,a5134,a2145,a3145;
int a12345,a21345,a31245,a41235,a51234;
        a01= a[0][1];
        a02= a[0][2];
        a03= a[0][3];
        a04= a[0][4];
        a05= a[0][5];

        a21=a01+a[1][2];
        a31=a01+a[1][3];
        a41=a01+a[1][4];
        a51=a01+a[1][5];

        a12=a02+a[2][1];
        a32=a02+a[2][3];
        a42=a02+a[2][4];
        a52=a02+a[2][5];

        a13=a03+a[3][1];
        a23=a03+a[3][2];
        a43=a03+a[3][4];
        a53=a03+a[3][5];

        a14=a04+a[4][1];
        a24=a04+a[4][2];
        a34=a04+a[4][3];
        a54=a04+a[4][5];

        a15=a05+a[5][1];
        a25=a05+a[5][2];
        a35=a05+a[5][3];
        a45=a05+a[5][4];
        l=0;

        //a123 pr a132 final a123
        if(a23+a[2][1]>a32+a[3][1])
        {
            a123=a32+a[3][1];


            //ans[++l][0]="1<-3<-2";
            strcpy(ans[l],"1<-3<-2");
        }
        else
        {
            a123=a23+a[2][1];
            //5ans[++l][0]="1<-2<-3";
            strcpy(ans[l],"1<-2<-3");


        }

        //a124 or a142 final a124
        if(a24+a[2][1]>a42+a[4][1])
        {
            a124=a42+a[4][1];
            strcpy(ans[++l],"1<-4<-2");

        }
        else
        {
            a124=a24+a[2][1];
            strcpy(ans[++l],"1<-2<-4");

        }

        //a134 or a143 final a134
        if(a34+a[3][1]>a43+a[4][1])
        {
            a134=a43+a[4][1];
            strcpy(ans[++l],"1<-4<-3");
        }
        else
        {
            a134=a34+a[3][1];
            strcpy(ans[++l],"1<-3<-4");
        }

        //a125 or a152 final a125
        if(a25+a[2][1]>a52+a[5][1])
        {
            a125=a52+a[5][1];
            strcpy(ans[++l],"1<-5<-2");
        }
        else
        {
            a125=a25+a[2][1];
            strcpy(ans[++l],"1<-2<-5");
        }

        //a135 or a153 final a135
        if(a35+a[3][1]>a53+a[5][1])
        {
            a135=a53+a[5][1];
            strcpy(ans[++l],"1<-5<-3");
        }
        else
        {
            a135=a35+a[3][1];
            strcpy(ans[++l],"1<-3<-5");
        }

        //a145 or a154 final a145
        if(a45+a[4][1]>a54+a[5][1])
        {
            a145=a54+a[5][1];
            strcpy(ans[++l],"1<-5<-4");
        }
        else
        {
            a145=a45+a[4][1];
            strcpy(ans[++l],"1<-4<-5");
        }

        //a213 or a231 final a213
        if(a13+a[1][2]>a31+a[3][2])
        {
            a213=a31+a[3][2];
            //ans[++l][0]="2<-3<-1";
            strcpy(ans[++l],"2<-3<-1");
        }
        else
        {
            a231=a13+a[1][2];
            //ans[++l][0]="2<-1<-3";
            strcpy(ans[++l],"2<-1<-3");

        }

         //a214 or a241 final a214
        if(a14+a[1][2]>a41+a[4][2])
        {
            a214=a41+a[4][2];
            strcpy(ans[++l],"2<-4<-1");


        }

        else
        {
            a214=a14+a[1][2];
            strcpy(ans[++l],"2<-1<-4");
        }

        //a234 or a243 final a234
        if(a34+a[3][2]>a43+a[4][2])
        {
            a234=a43+a[4][2];
            strcpy(ans[++l],"2<-4<-3");
        }
        else
        {
            a234=a34+a[3][2];
            strcpy(ans[++l],"2<-3<-4");
        }

        //a215 or a251 final a215
        if(a15+a[1][2]>a51+a[5][2])
        {
            a215=a51+a[5][2];
            strcpy(ans[++l],"2<-5<-1");
        }
        else
        {
            a215=a15+a[1][2];
            strcpy(ans[++l],"2<-1<-5");
        }

        //a235 or a253 final a235
        if(a35+a[3][2]>a53+a[5][2])
        {
            a235=a53+a[5][2];
            strcpy(ans[++l],"2<-5<-3");
        }
        else
        {
            a235=a35+a[3][2];
            strcpy(ans[++l],"2<-3<-5");
        }

        //a245 or a254 final a245
        if(a45+a[4][2]>a54+a[5][2])
        {
            a245=a54+a[5][2];
            strcpy(ans[++l],"2<-5<-4");
        }
        else
        {
            a245=a45+a[4][2];
            strcpy(ans[++l],"2<-4<-5");
        }

        //a312 or a321 final a312

        if(a12+a[1][3]>a[2][3]+a21)
        {
            a312=a[2][3]+a21;
            //ans[l][]="3<-2<-1";
            strcpy(ans[l],"3<-2<-1");
        }
        else
        {
            a312=a12+a[1][3];
            //ans[++l][0]="3<-1<-2";
            strcpy(ans[++l],"3<-1<-2");
        }

        //a314 or a341 final a314
        if(a14+a[1][3]>a41+a[4][3])
        {
            a314=a41+a[4][3];
            strcpy(ans[++l],"3<-4<-1");
        }
        else
        {
            a314=a14+a[1][3];
            strcpy(ans[++l],"3<-1<-4");
        }

        //a324 or a342 final a324
        if(a24+a[2][3]>a42+a[4][3])
        {
            a324=a42+a[4][3];
            strcpy(ans[++l],"3<-4<-2");
        }
        else
        {
            a324=a24+a[2][3];
            strcpy(ans[++l],"3<-2<-4");
        }

        //a315 or a351 final a315
        if(a15+a[1][3]>a51+a[5][3])
        {
            a315=a51+a[5][3];
            strcpy(ans[++l],"3<-5<-1");

        }
        else
        {
            a315=a15+a[1][3];
            strcpy(ans[++l],"3<-1<-5");
        }

        //a325 or a352 final a325
        if(a25+a[2][3]>a52+a[5][3])
        {
            a325=a52+a[5][3];
            strcpy(ans[++l],"3<-5<-2");
        }
        else
        {
            a325=a25+a[2][3];
            strcpy(ans[++l],"3<-2<-5");
        }

        //a345 or a354 final a345
        if(a45+a[4][3]>a54+a[5][3])
        {
            a345=a54+a[5][3];
            strcpy(ans[++l],"3<-5<-4");
        }
        else
        {
            a345=a45+a[4][3];
            strcpy(ans[++l],"3<-4<-5");
        }

         //a412 or a421 final a412
        if(a12+a[1][4]>a21+a[2][4])
        {
            a412=a21+a[2][4];
            strcpy(ans[++l],"4<-2<-1");

        }
        else
        {
            a412=a12+a[1][4];
            strcpy(ans[++l],"4<-1<-2");
        }

        //a413 or a431 final a413
        if(a13+a[1][4]>a31+a[3][4])
        {
            a413=a31+a[3][4];
            strcpy(ans[++l],"4<-3<-1");
        }
        else
        {
            a413=a13+a[1][4];
            strcpy(ans[++l],"4<-1<-3");
        }

        //a423 or a432 final a423
        if(a23+a[2][4]>a32+a[3][4])
        {
            a423=a32+a[3][4];
            strcpy(ans[++l],"4<-3<-2");
        }
        else
        {
            a423=a23+a[2][4];
            strcpy(ans[++l],"4<-2<-3");
        }

        //a415 or a451 final a415
        if(a15+a[1][4]>a51+a[5][4])
        {
            a415=a51+a[5][4];
            strcpy(ans[++l],"4<-5<-1");
        }
        else
        {
            a415=a15+a[1][4];
            strcpy(ans[++l],"4<-1<-5");
        }

        //a425 or a452 final a425
        if(a25+a[2][4]>a52+a[5][4])
        {
            a425=a52+a[5][4];
            strcpy(ans[++l],"4<-5<-2");
        }
        else
        {
            a425=a25+a[2][4];
            strcpy(ans[++l],"4<-2<-5");
        }

        //a435 or a453 final a435
        if(a35+a[3][4]>a53+a[5][4])
        {
            a435=a53+a[5][4];
            strcpy(ans[++l],"4<-5<-3");
        }
        else
        {
            a435=a35+a[3][4];
            strcpy(ans[++l],"4<-3<-5");
        }

        //a512 or a521 final a512
        if(a12+a[1][5]>a21+a[2][5])
        {
            a512=a21+a[2][5];
            strcpy(ans[++l],"5<-2<-1");
        }
        else
        {
            a512=a12+a[1][5];
            strcpy(ans[++l],"5<-1<-2");
        }

        //a513 or a531 final a513
        if(a13+a[1][5]>a31+a[3][5])
        {
            a513=a31+a[3][5];
            strcpy(ans[++l],"5<-3<-1");
        }
        else
        {
            a513=a13+a[1][5];
            strcpy(ans[++l],"5<-1<-3");
        }

        //a514 or a541 final a541
        if(a14+a[1][5]>a41+a[4][5])
        {
            a514=a41+a[4][5];
            strcpy(ans[++l],"5<-4<-1");
        }
        else
        {
            a514=a14+a[1][5];
            strcpy(ans[++l],"5<-1<-4");
        }

        //a523 or a532 final a523
        if(a23+a[2][5]>a32+a[3][5])
        {
            a523=a32+a[3][5];
            strcpy(ans[++l],"5<-3<-2");
        }
        else
        {
            a523=a23+a[2][5];
            strcpy(ans[++l],"5<-2<-3");
        }

        //a524 or a542 final a524
        if(a24+a[2][5]>a42+a[4][5])
        {
            a524=a42+a[4][5];
            strcpy(ans[++l],"5<-4<-2");
        }
        else
        {
            a524=a24+a[2][5];
            strcpy(ans[++l],"5<-2<-4");
        }

        //a534 or a543 final a534
        if(a34+a[3][5]>a43+a[4][5])
        {
            a534=a43+a[4][5];
            strcpy(ans[++l],"5<-4<-3");
        }
        else
        {
            a534=a34+a[3][5];
            strcpy(ans[++l],"5<-3<-4");
        }

        int t=0;

        //a1234 or a1324 or a1423  final a1234
        if(a234+a[2][1]<a324+a[3][1] && a234+a[2][1]<a423+a[4][1])
        {
            a1234=a234+a[2][1];
            char temp[15]="1<-";
            strcat(temp,ans[8]);
            strcpy(ans1[t],temp);


        }
        else if(a324+a[3][1]<a234+a[2][1] && a324+a[3][1]<a423+a[4][1])
        {
            a1234=a324+a[3][1];
            char temp[15]="1<-";
            strcat(temp,ans[14]);
            strcpy(ans1[t],temp);
        }
        else
        {
            a1234=a423+a[4][1];
            char temp[15]="1<-";
            strcat(temp,ans[20]);
            strcpy(ans1[t],temp);
        }

        //a1235 or a1325 or a1523 final a1235
        if(a235+a[2][1]<a325+a[3][1] && a235+a[2][1]<a523+a[5][1])
        {
            a1235=a235+a[2][1];
            char temp[15]="1<-";
            strcat(temp,ans[10]);
            strcpy(ans1[++t],temp);

        }
        else if(a325+a[3][1]<a235+a[2][1] && a325+a[3][1]<a523+a[5][1])
        {
            a1235=a325+a[3][1];
            char temp[15]="1<-";
            strcat(temp,ans[16]);
            strcpy(ans1[++t],temp);

        }
        else
        {
            a1235=a523+a[5][1];
            char temp[15]="1<-";
            strcat(temp,ans[27]);
            strcpy(ans1[++t],temp);
        }

        //a1345 or a1435 or a1534 final a1345
        if(a345+a[3][1]<a435+a[4][1] && a345+a[3][1]<a534+a[5][1])
        {
            a1345=a345+a[3][1];
            char temp[15]="1<-";
            strcat(temp,ans[17]);
            strcpy(ans1[++t],temp);
        }
        else if(a435+a[4][1]<a345+a[3][1] && a435+a[4][1]<a534+a[5][1])
        {
            a1345=a435+a[4][1];
            char temp[15]="1<-";
            strcat(temp,ans[23]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a1345=a534+a[5][1];
            char temp[15]="1<-";
            strcat(temp,ans[29]);
            strcpy(ans1[++t],temp);
        }

        //a1245 or a1425 or a1524 final a1245
        if(a245+a[2][1]<a425+a[4][1] && a245+a[2][1]<a524+a[5][1])
        {
            a1245=a245+a[2][1];
            char temp[15]="1<-";
            strcat(temp,ans[11]);
            strcpy(ans1[++t],temp);
        }
        else if(a425+a[4][1]<a245+a[2][1] && a425+a[4][1]<a524+a[5][1])
        {
            a1245=a425+a[4][1];
            char temp[15]="1<-";
            strcat(temp,ans[22]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a1245=a524+a[5][1];
            char temp[15]="1<-";
            strcat(temp,ans[28]);
            strcpy(ans1[++t],temp);
        }

        //a2134 or a2314 or a2413 final a2134
        if(a134+a[1][2]<a314+a[3][2] && a134+a[1][2]<a413+a[4][2])
        {
            a2134=a134+a[1][2];
            char temp[15]="2<-";
            strcat(temp,ans[2]);
            strcpy(ans1[++t],temp);
        }
        else if (a314+a[3][2]<a134+a[1][2] && a314+a[3][2]<a413+a[4][2])
        {
            a2134=a314+a[3][2];
            char temp[15]="2<-";
            strcat(temp,ans[13]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a2134=a413+a[4][2];
            char temp[15]="2<-";
            strcat(temp,ans[19]);
            strcpy(ans1[++t],temp);
        }

        //a2135 or a2315 or 2513 final a2135
        if(a135+a[1][2]<a315+a[3][2] && a135+a[1][2]<a513+a[5][2])
        {
            a2135=a135+a[1][2];
            char temp[15]="2<-";
            strcat(temp,ans[4]);
            strcpy(ans1[++t],temp);
        }
        else if(a315+a[3][2]<a135+a[1][2] && a315+a[3][2]<a513+a[5][2])
        {
            a2135=a315+a[3][2];
            char temp[15]="2<-";
            strcat(temp,ans[15]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a2135=a513+a[5][2];
            char temp[15]="2<-";
            strcat(temp,ans[25]);
            strcpy(ans1[++t],temp);
        }

        //a2345 or a2435 or a2534 final a2345
        if(a345+a[3][2]<a435+a[4][2] && a345+a[3][2]<a534+a[5][2])
        {
            a2345=a345+a[3][2];
            char temp[15]="2<-";
            strcat(temp,ans[17]);
            strcpy(ans1[++t],temp);
        }
        else if(a435+a[4][2]<a345+a[3][2] && a435+a[4][2]<a534+a[5][2])
        {
            a2345=a435+a[4][2];
            char temp[15]="2<-";
            strcat(temp,ans[23]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a2345=a534+a[5][2];
            char temp[15]="2<-";
            strcat(temp,ans[29]);
            strcpy(ans1[++t],temp);
        }

        //a2145 or a2415 or a2514 final a2145
        if(a145+a[1][2]<a415+a[4][2] && a145+a[1][2]<a514+a[5][2])
        {
            a2145=a145+a[1][2];
            char temp[15]="2<-";
            strcat(temp,ans[5]);
            strcpy(ans1[++t],temp);
        }
        else if(a415+a[4][2]<a145+a[1][2] && a415+a[4][2]<a514+a[5][2])
        {
            a2145=a415+a[4][2];
            char temp[15]="2<-";
            strcat(temp,ans[21]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a2145=a514+a[5][2];
            char temp[15]="2<-";
            strcat(temp,ans[26]);
            strcpy(ans1[++t],temp);
        }

        //a3124 or a3214 or a3412 final a3124
        if(a124+a[1][3]<a214+a[2][3] && a124+a[1][3]< a412+a[4][3])
        {
            a3124=a124+a[1][3];

            char temp[15]="3<-";
            strcat(temp,ans[1]);
            strcpy(ans1[++t],temp);
        }
        else if(a214+a[2][3]<a124+a[1][3] && a214+a[2][3]<a412+a[4][3])
        {
            a3124=a214+a[2][3];
            char temp[15]="3<-";
            strcat(temp,ans[7]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a3124=a412+a[4][3];
            char temp[15]="3<-";
            strcat(temp,ans[18]);
            strcpy(ans1[++t],temp);
        }

        //a3125 or a3215 or a3512 final a3125
        if(a125+a[1][3]<a215+a[2][3] && a125+a[1][3]<a512+a[5][3])
        {
            a3125=a125+a[1][3];
            char temp[15]="3<-";
            strcat(temp,ans[3]);
            strcpy(ans1[++t],temp);
        }
        else if(a215+a[2][3]<a125+a[1][3] && a215+a[2][3]<a512+a[5][3])
        {
            a3125=a215+a[2][3];
            char temp[15]="3<-";
            strcat(temp,ans[9]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a3125=a512+a[5][3];
            char temp[15]="3<-";
            strcat(temp,ans[24]);
            strcpy(ans1[++t],temp);
        }

        //a3245 or a3425 or a3524 final a3245
        if(a245+a[2][3]<a425+a[4][3] && a245+a[2][3]<a524+a[5][3])
        {
            a3245=a245+a[2][3];
            char temp[15]="3<-";
            strcat(temp,ans[11]);
            strcpy(ans1[++t],temp);
        }
        else if(a425+a[4][3]<a245+a[2][3] && a425+a[4][3]<a524+a[5][3])
        {
            a3245=a425+a[4][3];
            char temp[15]="3<-";
            strcat(temp,ans[22]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a3245=a524+a[5][3];
            char temp[15]="3<-";
            strcat(temp,ans[28]);
            strcpy(ans1[++t],temp);
        }

        //a3145 or a3415 or a3514 final a3145
        if(a145+a[1][3]<a415+a[4][3] && a145+a[1][3]<a514+a[5][3])
        {
            a3145=a145+a[1][3];
            char temp[15]="3<-";
            strcat(temp,ans[5]);
            strcpy(ans1[++t],temp);
        }
        else if(a415+a[4][3]<a145+a[1][3] && a415+a[4][3]<a514+a[5][3])
        {
            a3145=a415+a[4][3];
            char temp[15]="3<-";
            strcat(temp,ans[21]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a3145=a514+a[5][3];
            char temp[15]="3<-";
            strcat(temp,ans[26]);
            strcpy(ans1[++t],temp);
        }

        //a4123 or a4213 or a4312 final a4123
        if(a123+a[1][4]<a213+a[2][4] && a123+a[1][4]<a312+a[3][4])
        {
            a4123=a123+a[1][4];
            char temp[15]="4<-";
            strcat(temp,ans[0]);
            strcpy(ans1[++t],temp);
        }
        else if(a213+a[2][4]<a123+a[1][4] && a213+a[2][4]<a312+a[3][4])
        {
            a4123=a213+a[2][4];
            char temp[15]="4<-";
            strcat(temp,ans[6]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a4123=a312+a[3][4];
            char temp[15]="4<-";
            strcat(temp,ans[12]);
            strcpy(ans1[++t],temp);
        }

        //a4125 or a4215 or a4512 final a4125
        if(a125+a[1][4]<a215+a[2][4] && a125+a[1][4]<a512+a[5][4])
        {
            a4125=a125+a[1][4];
            char temp[15]="4<-";
            strcat(temp,ans[13]);
            strcpy(ans1[++t],temp);
        }
        else if(a215+a[2][4]<a125+a[1][4] && a215+a[2][4]<a512+a[5][4])
        {
            a4125=a215+a[2][4];
            char temp[15]="4<-";
            strcat(temp,ans[9]);
            strcpy(ans1[++t],temp);

        }
        else
        {
            a4125=a512+a[5][4];
            char temp[15]="4<-";
            strcat(temp,ans[24]);
            strcpy(ans1[++t],temp);
        }

        //a4235 or a4325 or a4523 final a4235
        if(a235+a[2][4]<a325+a[3][4] && a235+a[2][4]<a523+a[5][4])
        {
            a4235=a235+a[2][4];
            char temp[15]="4<-";
            strcat(temp,ans[10]);
            strcpy(ans1[++t],temp);
        }
        else if(a325+a[3][4]<a235+a[2][4] && a325+a[3][4]<a523+a[5][4])
        {
            a4235=a325+a[3][4];
            char temp[15]="4<-";
            strcat(temp,ans[16]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a4235=a523+a[5][4];
            char temp[15]="4<-";
            strcat(temp,ans[27]);
            strcpy(ans1[++t],temp);
        }

        //a4135 or a4315 or a4513
        if(a135+a[1][4]<a315+a[3][4] && a135+a[1][4]<a513+a[5][4])
        {
            a4135=a135+a[1][4];
            char temp[15]="4<-";
            strcat(temp,ans[4]);
            strcpy(ans1[++t],temp);
        }
        else if(a315+a[3][4]<a135+a[1][4] && a315+a[3][4]<a513+a[5][4])
        {
            a4135=a315+a[3][4];
            char temp[15]="4<-";
            strcat(temp,ans[15]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a4135=a513+a[5][4];
            char temp[15]="4<-";
            strcat(temp,ans[25]);
            strcpy(ans1[++t],temp);
        }

        //a5123 or a5213 or a5312 final a5123
        if(a123+a[1][5]<a213+a[2][5] && a123+a[1][5]<a312+a[3][5])
        {
            a5123=a123+a[1][5];
            char temp[15]="5<-";
            strcat(temp,ans[0]);
            strcpy(ans1[++t],temp);
        }
        else if(a213+a[2][5]<a123+a[1][5] && a213+a[2][5]<a312+a[3][5])
        {
            a5123=a213+a[2][5];
            char temp[15]="5<-";
            strcat(temp,ans[6]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a5123=a312+a[3][5];
            char temp[15]="5<-";
            strcat(temp,ans[12]);
            strcpy(ans1[++t],temp);
        }

        //a5124 or a5214 or a5412 final a5124
        if(a124+a[1][5]<a214+a[2][5] && a124+a[1][5]<a412+a[4][5])
        {
            a5124=a124+a[1][5];
            char temp[15]="5<-";
            strcat(temp,ans[1]);                                                        //////////doubt here
            strcpy(ans1[++t],temp);
        }
        else if(a214+a[2][5]<a124+a[1][5] && a214+a[2][5]<a412+a[4][5])
        {
            a5124=a214+a[2][5];
            char temp[15]="5<-";
            strcat(temp,ans[7]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a5124=a412+a[4][5];
            char temp[15]="5<-";
            strcat(temp,ans[18]);
            strcpy(ans1[++t],temp);
        }

        //a5234 or a5324 or a5423 final a5234
        if(a234+a[2][5]<a324+a[3][5] && a234+a[2][5]<a423+a[4][5])
        {
            a5234=a234+a[2][5];
            char temp[15]="5<-";
            strcat(temp,ans[8]);
            strcpy(ans1[++t],temp);
        }
        else if(a324+a[3][5]<a234+a[2][5] && a324+a[3][5]<a423+a[4][5])
        {
            a5234=a324+a[3][5];
            char temp[15]="5<-";
            strcat(temp,ans[14]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a5234=a423+a[4][5];
            char temp[15]="5<-";
            strcat(temp,ans[20]);
            strcpy(ans1[++t],temp);
        }

        //a5134 or a5314 or a5413 final a5134
        if(a134+a[1][5]<a314+a[3][5] && a134+a[1][5]<a413+a[4][5])
        {
            a5134=a134+a[1][5];
            char temp[15]="5<-";
            strcat(temp,ans[2]);
            strcpy(ans1[++t],temp);
        }
        else if(a314+a[3][5]<a134+a[1][5] && a314+a[3][5]<a413+a[4][5])
        {
            a5134=a314+a[3][5];
            char temp[15]="5<-";
            strcat(temp,ans[13]);
            strcpy(ans1[++t],temp);
        }
        else
        {
            a5134=a413+a[4][5];
            char temp[15]="5<-";
            strcat(temp,ans[19]);
            strcpy(ans1[++t],temp);
        }
        char ans2[25][25];
        int j=0;

        //a12345 or a13245 or a14235 or a15234 final a12345
        if(a2345+a[2][1]<a3245+a[3][1] && a2345+a[2][1]<a4235+a[4][1] && a2345+a[2][1]<a5234+a[5][1])
        {
            a12345=a2345+a[2][1];
            char temp[25]="1<-";
            strcat(temp,ans1[6]);
            strcpy(ans2[j],temp);
        }
        else if(a3245+a[3][1]<a2345+a[2][1] && a3245+a[3][1]<a4235+a[4][1] && a3245+a[3][1]<a5234+a[5][1])
        {
            a12345=a3245+a[3][1];
            char temp[25]="1<-";
            strcat(temp,ans1[10]);
            strcpy(ans2[j],temp);
        }

        else if(a4235+a[4][1]<a2345+a[2][1] && a4235+a[4][1]<a3245+a[3][1] && a4235+a[4][1]<a5234+a[5][1])
        {
            a12345=a4235+a[4][1];
            char temp[25]="1<-";
            strcat(temp,ans1[14]);
            strcpy(ans2[j],temp);
        }
        else
        {
            a12345=a5234+a[5][1];
            char temp[25]="1<-";
            strcat(temp,ans1[18]);
            strcpy(ans2[j],temp);
        }

        //a21345 or a23145 or a24135 or a25134 final a21345
        if(a1345+a[1][2]<a3145+a[3][2] && a1345+a[1][2]<a4135+a[4][2] && a1345+a[1][2]<a5134+a[5][2])
        {
            a21345=a1345+a[1][2];
            char temp[25]="2<-";
            strcat(temp,ans1[2]);
            strcpy(ans2[++j],temp);
        }
        else if(a3145+a[3][2]<a1345+a[1][2] && a3145+a[3][2]<a4135+a[4][2] && a3145+a[3][2]<a5134+a[5][2])
        {
            a21345=a3145+a[3][2];
            char temp[25]="2<-";
            strcat(temp,ans1[11]);
            strcpy(ans2[++j],temp);
        }
        else if(a4135+a[4][2]<a1345+a[1][2] && a4135+a[4][2]<a3145+a[3][2] && a4135+a[4][2]<a5134+a[5][2])
        {
            a21345=a4135+a[4][2];
            char temp[25]="2<-";
            strcat(temp,ans1[15]);
            strcpy(ans2[++j],temp);
        }
        else
        {
            a21345=a5134+a[5][2];
            char temp[25]="2<-";
            strcat(temp,ans1[19]);
            strcpy(ans2[++j],temp);
        }

        //a31245 or a32145 or a34125 or a35124 final a31245
        if(a1245+a[1][3]<a2145+a[2][3] && a1245+a[1][3]<a4125+a[4][3] && a1245+a[1][3]<a5124+a[5][3])
        {
            a31245=a1245+a[1][3];
            char temp[25]="3<-";
            strcat(temp,ans1[3]);
            strcpy(ans2[++j],temp);
        }
        else if(a2145+a[2][3]<a1245+a[1][3] && a2145+a[2][3]<a4125+a[4][3] && a2145+a[2][3]<a5124+a[5][3])
        {
            a31245=a2145+a[2][3];
            char temp[25]="3<-";
            strcat(temp,ans1[7]);
            strcpy(ans2[++j],temp);
        }
        else if(a4125+a[4][3]<a1245+a[1][3] && a4125+a[4][3]<a2145+a[2][3] && a4125+a[4][3]<a5124+a[5][3])
        {
            a31245=a4125+a[4][3];
            char temp[25]="3<-";
            strcat(temp,ans1[13]);
            strcpy(ans2[++j],temp);
        }
        else
        {
            a31245=a5124+a[5][3];
            char temp[25]="3<-";
            strcat(temp,ans1[17]);
            strcpy(ans2[++j],temp);
        }

        //a41235 or a42135 or a43125 or a45123 final a41235
        if(a1235+a[1][4]<a2135+a[2][4] && a1235+a[1][4]<a3125+a[3][4] && a1235+a[1][4]<a5123+a[5][4])
        {
            a41235=a1235+a[1][4];
            char temp[25]="4<-";
            strcat(temp,ans1[1]);
            strcpy(ans2[++j],temp);
        }
        else if(a2135+a[2][4]<a1235+a[1][4] && a2135+a[2][4]<a3125+a[3][4] && a2135+a[2][4]<a5123+a[5][4])
        {
            a41235=a2135+a[2][4];
            char temp[25]="4<-";
            strcat(temp,ans1[5]);
            strcpy(ans2[++j],temp);
        }
        else if(a3125+a[3][4]<a1235+a[1][4] && a3125+a[3][4]<a2135+a[2][4] && a3125+a[3][4]<a5123+a[5][4])
        {
            a41235=a3125+a[3][4];
            char temp[25]="4<-";
            strcat(temp,ans1[9]);
            strcpy(ans2[++j],temp);
        }
        else
        {
            a41235=a5123+a[5][4];
            char temp[25]="4<-";
            strcat(temp,ans1[16]);
            strcpy(ans2[++j],temp);
        }

        //a51234 or a52134 or a53124 or a54123 final a51234
        if(a1234+a[1][5]<a2134+a[2][5] && a1234+a[1][5]<a3124+a[3][5] && a1234+a[1][5]<a4123+a[4][5])
        {
            a51234=a1234+a[1][5];
            char temp[25]="5<-";
            strcat(temp,ans1[0]);
            strcpy(ans2[++j],temp);
        }
        else if(a2134+a[2][5]<a1234+a[1][5] && a2134+a[2][5]<a3124+a[3][5] && a2134+a[2][5]<a4123+a[4][5])
        {
            a51234=a2134+a[2][5];
            char temp[25]="5<-";
            strcat(temp,ans1[4]);
            strcpy(ans2[++j],temp);
        }
        else if(a3124+a[3][5]<a1234+a[1][5] && a3124+a[3][5]<a2134+a[2][5] && a3124+a[3][5]<a4123+a[4][5])
        {
            a51234=a3124+a[3][5];
            char temp[25]="5<-";
            strcat(temp,ans1[8]);
            strcpy(ans2[++j],temp);
        }
        else
        {
            a51234=a4123+a[4][5];
            char temp[25]="5<-";
            strcat(temp,ans1[12]);
            strcpy(ans2[++j],temp);
        }

        //a012345 or a021345 or a031245 or a041235 or a051234 final a012345
        if(a12345+a[1][0]<a21345+a[2][0] && a12345+a[1][0]<a31245+a[3][0] && a12345+a[1][0]<a41235+a[4][0] && a12345+a[1][0]<a51234+a[5][0])
        {
             printf("%s %d","Shortest Distance =",(a12345+a[1][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans2[0],"<-0");
             printf("\n");
        }
        else if(a21345+a[2][0]<a12345+a[1][0] && a21345+a[2][0]<a31245+a[3][0] && a21345+a[2][0]<a41235+a[4][0] && a21345+a[2][0]<a51234+a[5][0])
        {
             printf("%s %d","Shortest Distance =",(a21345+a[2][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans2[1],"<-0");
             printf("\n");
        }
        else if(a31245+a[3][0]<a12345+a[1][0] && a31245+a[3][0]<a21345+a[2][0] && a31245+a[3][0]<a41235+a[4][0] && a31245+a[3][0]<a51234+a[5][0])
        {
             printf("%s %d","Shortest Distance =",(a31245+a[3][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans2[2],"<-0");
             printf("\n");
        }
        else if(a41235+a[4][0]<a12345+a[1][0] && a41235+a[4][0]<a21345+a[2][0] && a41235+a[4][0]<a31245+a[3][0] && a41235+a[4][0]<a51234+a[5][0])
        {
             printf("%s %d","Shortest Distance =",(a41235+a[4][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans2[3],"<-0");
             printf("\n");
        }
        else
        {
             printf("%s %d","Shortest Distance =",(a51234+a[5][0]));
             printf("\n");
             printf("%s%s%s","0<-",ans2[4],"<-0");
             printf("\n");
        }

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        printf("%f",time_taken);




    }


    return 0;
}

