#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include<string>

using namespace std;

int Random(int a, int b){ // a부터 b까지의 숫자 중 임의의 숫자를 추출하는 함수

	return a + rand() % (b-a+1);
}

void marbles_if_Computer_smart(int &marbles){  // 구슬 갯수를 4n+1로 하기 위한 변수 (스마트 모드일 경우에만)

	int marbles_before = marbles;  // marbles_before: 전(before) 구슬 갯수
	if(marbles_before > 29){
		marbles = 29;
	} else if(marbles_before < 29 && marbles_before > 25){
		marbles = 25;
	} else if(marbles_before < 25 && marbles_before > 21){
		marbles = 21;
	} else if(marbles_before < 21 && marbles_before > 17){
		marbles = 17;
	} else if(marbles_before < 17 && marbles_before > 13){
		marbles = 13;
	} else if(marbles_before < 13 && marbles_before > 9){
		marbles = 9;
	} else if(marbles_before < 9 && marbles_before > 5){
		marbles = 5;
	} else if(marbles_before < 5 && marbles_before > 1){
		marbles = 1;
	} else{
		marbles = marbles - Random(1, 3);
	}
}

void Computer_smart(int &marbles){  // 컴퓨터가 구슬을 가져갈 차례일 때 실행하는 함수(스마트 모드용)

	int marbles_before = marbles;  // marbles_before: 전(before) 구슬 갯수
	marbles_if_Computer_smart(marbles);  // 구슬 갯수를 4n+1로 함
	int computer_take = marbles_before - marbles;  // computer_take: '전(before) 갯수 - 후(after) 갯수'로 컴퓨터가 가져간 구슬 갯수를 넣음

	cout << "Computer plays..." << endl;
	cout << "The computer takes " << computer_take << " marbles." << endl;  // 컴퓨터가 몇 개의 구슬을 가져갔는지 출력
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // 구슬 갯수 출력
	}
}

void Computer_general(int &marbles){  // 컴퓨터가 구슬을 가져갈 차례일 때 실행하는 함수(일반 모드용)

	int computer_take = Random(1, 3);  // computer_take: 컴퓨터가 가져간 구슬 갯수(Random)
	cout << "Computer plays..." << endl;
	cout << "The computer takes " << computer_take << " marbles." << endl;  // 컴퓨터가 몇 개의 구슬을 가져갔는지 출력
	marbles = marbles - computer_take;  // 컴퓨터가 가져간 구슬 갯수만큼 전체 구슬 갯수를 뺌
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // 구슬 갯수 출력
	}
}

int smart_mode = Random(1,2);  // (전역 변수) smart_mode: 1-일반 모드, 2-스마트 모드

void Computer(int &marbles){  // 스마트 모드일 때는 스마트 모드용 함수를, 일반 모드일 때는 일반 모드용 함수를 실행시킴

	if(smart_mode == 1){
		Computer_general(marbles);
	} else{
		Computer_smart(marbles);
	}
}

void Player(int &marbles){  // 플레이어가 구슬을 가져갈 차례일 때 실행하는 함수

	int player_take;  // player_take: 플레이어가 가져간 구슬 갯수
	cout << "Your play .. you may take 1, 2, or 3 marbles." << endl;
	cout << "You take ";
	cin >> player_take;  // 몇 개의 구슬을 가져갈 것이지 입력받게 함

	if(player_take!=1 && player_take!=2 && player_take!=3){  // 1,2, 3이 아닌 다른 수를 입력할 경우에 실행하는 부분
		cout << "Ooops... you picked too many or not enough." << endl;
		player_take = Random(1, 3);
		cout << "You will take " << player_take  << " marbles." << endl;
	}
	marbles = marbles - player_take;  // 플레이어가 가져간 구슬 갯수만큼 전체 구슬 갯수를 뺌
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // 구슬 갯수 출력
	}
}

void rand_changing(){  // 랜덤 씨앗값을 바꾸기 위해 사용

 int change = static_cast <int> (time(0));
 srand(change);

}

int main(){

	string restart;  // restart: yes-게임을 재시작함, no-게임을 재시작하지 않고 끝냄

	do{
		rand_changing();

		cout << "Players alternate taking 1, 2, or 3 marbles in the pile.\n";
		cout << "The player who takes the last marble loses." << endl;        // 초기 출력문
	
		int first_start = Random(1,2);  // first_start: 1-컴퓨터가 먼저 시작, 2-플레이어가 먼저 시작
		if(first_start == 1){  // 누가 먼저 시작하는지에 따라 출력을 달리함
			cout << "The computer will play first." << endl;
		} else{
			cout << "You will play first." << endl;
		}
	
		/*  smart_mode: 전역 변수로 지정했음  */
		if(smart_mode == 1){  // 스마트 모드인지 아닌지에 따라 출력을 달리함 (1-일반 모드, 2-스마트 모드)
			cout << "The computer will play general." << endl;
		} else{
			cout << "The computer will play smart." << endl;
		}

		int marbles;  // marbles: 현재 구슬 갯수를 저장하기 위한 변수
		if(smart_mode == 1){  // 스마트 모드이면 초기 구슬 갯수를 4n+1로 함 (아니면 그냥 무작위로 초기 구슬 갯수를 지정)
			marbles = Random(10,30);
		} else{
			int n = Random(3,7);
			marbles = 4*n+1;
		}
		cout << "There are " << marbles << " marbles in the pile." << endl;  // (한번만 사용됨)

		int next_turn;  // next_turn: 0-컴퓨터 차례, 1-플레이어 차례
		if(first_start == 1){  // 초기 시작자가 누구인지에 따라 차례를 바꿔가면서 계속 실행

			next_turn = 0;
			Computer(marbles);

			while(marbles > 1){

				if(marbles > 1){
					next_turn = 1;
					Player(marbles);
				}
				if(marbles > 1){
					next_turn = 0;
					Computer(marbles);
				}

			}

		} else{

			next_turn = 1;
			Player(marbles);

			while(marbles > 1){

				if(marbles > 1){
					next_turn = 0;
					Computer(marbles);
				}
				if(marbles > 1){
					next_turn = 1;
					Player(marbles);
				}

			}

		}

		if(next_turn == 0){  // 구슬이 1개만 남았을 때 승부를 결정
			cout << "You must take the last marble. You lose!" << endl;
		} else{
			cout << "The computer must take the last marble. You win!!" << endl;
		}

		cout << "Do you want to restart this game (yes/no) " ;
		cin >> restart;  // 재시작 여부


	} while(restart == "yes");

	cout << "\nThanks for Playing our game~!! ^0^" << endl;  // 재시작을 원하지 않을 경우 출력함 (종료문)
	return 0;
}