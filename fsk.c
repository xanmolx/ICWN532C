#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *fp;
    fp = fopen("fsk.txt", "w");
    fclose(fp);
    fp = fopen("fsk.txt", "a");

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    float input[100*n];

    float prev1 = 0;
    float prev2 = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            for(int j=i*100; j<((i*100)+100); j++){
                input[j] = sin(prev2);
                prev2 += 0.1;
            }
        }
        else{
            for(int j=i*100; j<((i*100)+100); j++){
                input[j] = sin(prev1);
                prev1 += 0.3;
            }
        }
    }

    for(int i=0; i<100*n; i++){
        fprintf(fp, "%d %f\n", i, input[i]);

    }
    fclose(fp);
    return 0;
}