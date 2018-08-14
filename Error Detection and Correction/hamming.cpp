#include <bits/stdc++.h>
using namespace std;

int main(){
    int in[10];
    int out[10];

    cout << "Enter the 4 bit message ";
    cin >> in[0] >> in[1] >> in[2] >> in[4];
    in[6] = in[0]^in[2]^in[4];
    in[5] = in[0]^in[1]^in[4];
    in[3] = in[0]^in[1]^in[2];

    cout << "The coded word is: ";
    for(int i=0; i<7; i++){
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "Enter the data recieved: ";
    for(int i=0; i<7; i++){
        cin >> out[i];
    }

    int c1 = out[6]^out[4]^out[2]^out[0];
	int c2 = out[5]^out[4]^out[1]^out[0];
	int c3 = out[3]^out[2]^out[1]^out[0];

    int c = c3*4 + c2*2 + c1;

    if(!c){
        cout << "No error" << endl;
        return 0;
    }
    else{
        cout << "There was error, the correct bit word is: "
        if(out[7-c] == 0)
			out[7-c] = 1;
        else
		    out[7-c]=0;
		
        for (int i=0 ;i<7; i++){
			cout << out[i] << " ";
		}

        cout << endl;
    }
    return 0;
}