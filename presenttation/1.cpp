#include <iostream>
#include <cstdlib> 
#include <time.h>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1, guess, attempts =0;
    cout<<"==Game doan so===\n";
    do{
        cout<<"Doan so (1-100)";
        cin>>guess;
        attempts++;
        if(guess>secret){
            cout<< "Qua cao!\n";
        }
        else if(guess < secret){
            cout<<"Qua thap!\n";
        }
        else{
            cout<<"==> Thang roi!\n";
        }
    }while(guess != secret);
    cout<<"So luot doan: "<<attempts <<endl;

    return 0;
}