#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand(static_cast<unsigned int>(time(nullptr)));
	int random_num = rand() %100 +1;
	int guess_num;
	int attempt =0;
	do{
		cout<<"Enter your guess number "<<endl;
		cin>>guess_num;
		attempt++;
		if(guess_num==random_num){
			cout<<"Congrats you guessed the number in "<<attempt <<"attempts"<<endl;
		}
		else if (guess_num>random_num){
			cout<<"your guessed number is too high ! try again "<<endl;
		}
		else{
			cout<<"your guessed number is too low ! try again  "<<endl;
		}

	}while(guess_num != random_num);
return 0;
}
