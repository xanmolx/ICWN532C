#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *fp;
    fp = fopen("pnrz.txt", "w");
    fclose(fp);
    fp = fopen("pnrz.txt", "a");

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    float input[100*n];
    for(int i=0; i<100*n; i++){
        input[i] = 0;
    }

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            for(int j=i*100; j<((i*100)+100); j++){
                input[j]=-5;
            }
        }
        else{
            for(int j=i*100; j<((i*100)+100); j++){
                input[j] = 5;
            }
        }
    }

    for(int i=0; i<100*n; i++){
        fprintf(fp, "%d %f\n", i, input[i]);

    }
    fclose(fp);
    return 0;
}