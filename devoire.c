#include<stdlib.h>
#include<stdio.h>
int ** create_func(int a,int b);
int ** matrix_add(int ** T1,int**T2,int n,int m);
int ** matrix_prod(int ** T1,int**T2,int n);
int main(){
printf(R"EOF(              .7
            .'/
           / /
          / /
         / /
        / /
       / /
      / /
     / /         
    / /          
  __|/
,-\__\
|f-"Y\|
\()7L/
 cgD                            __ _
 |\(                          .'  Y '>,
  \ \                        / _   _   \
   \\\                       )(_) (_)(|}
    \\\                      {  4A   } /
     \\\                      \uLuJJ/\l
      \\\                     |3    p)/
       \\\___ __________      /nnm_n//
       c7___-__,__-)\,__)(".  \_>-<_/D
                  //V     \_"-._.__G G_c__.-__<"/ ( \
                         <"-._>__-,G_.___)\   \7\
                        ("-.__.| \"<.__.-" )   \ \
                        |"-.__"\  |"-.__.-".\   \ \
                        ("-.__"". \"-.__.-".|    \_\
                        \"-.__""|!|"-.__.-".)     \ \
                         "-.__""\_|"-.__.-"./      \ l
                          ".__""">G>-.__.-">       .--,_
                              GG"")EOF");
    printf("\n");
    int n,m,c;
    int**T1,**T2,**T3,**T4;
    printf("please enter the number of lines in your matrix: ");
    scanf("%d",&n);
    printf("please enter the number of colums in your matrix: ");
    scanf("%d",&m);
    T1=create_func(n,m);
    T2=create_func(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("please enter ith _%d_ jth _%d_ value: ",i,j);
            scanf("%d",&c);
            T1[i][j]=c;
            T2[j][i]=c;
            
        }
    }
    printf("\n\nthe constructed matrix T1 is bellow \n");
    printf("_____________________________________________________\n");
    for(int i=0;i<n;i++){
        printf("\n|");
        for(int j=0;j<m;j++){
            if (j==n-1){printf("%d",T1[i][j]);}
            else printf("%d\t",T1[i][j]);

        }
        printf("|");}
        printf("\n");
    printf("the constructed matrix T2 is bellow \n");
        printf("_____________________________________________________\n");
    for(int i=0;i<n;i++){
        printf("\n|");
        for(int j=0;j<m;j++){
            if (j==n-1){printf("%d",T2[i][j]);}
            else printf("%d\t",T2[i][j]);

        }
        printf("|");}
        printf("\n");
    printf("now the addition of this 2 matrices is bellow: \n");
        printf("_____________________________________________________\n");
    T3=matrix_add(T1,T2,n,m);
    for(int i=0;i<n;i++){
        printf("\n|");
        for(int j=0;j<m;j++){
            if (j==n-1){printf("%d",T3[i][j]);}
            else printf("%d\t",T3[i][j]);

        }
        printf("|");}
        printf("\n");
    T4=matrix_prod(T1,T2,n);
    printf("now the product of this 2 matrices is bellow: \n");
        printf("_____________________________________________________\n");
    for(int i=0;i<n;i++){
        printf("\n|");
        for(int j=0;j<m;j++){
            if (j==n-1){printf("%d",T4[i][j]);}
            else printf("%d\t",T4[i][j]);

        }
        printf("|");}
        printf("\n");

}

int ** create_func(int a,int b){
    int ** T=(int **) malloc(a*sizeof(int *));
    for(int i=0;i<a;i++){
        T[i]=(int*) malloc(b*sizeof(int));
    }
return T;

}
int ** matrix_add(int ** T1,int**T2,int n,int m){
    int **T3;
    T3=create_func(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            T3[i][j]=T1[i][j]+T2[i][j];
        }}
    return T3;

    
}
int ** matrix_prod(int ** T1,int**T2,int n){
    int **T4;
    int c;
    T4=create_func(n,n);
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c=0;
            for(int k=0;k<n;k++){
                c+=T1[i][k]*T2[k][j];
            }
            T4[i][j]=c;
        }
}
return T4;
}
