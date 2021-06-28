#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include<string>

using namespace std;

int Random(int a, int b){ // a���� b������ ���� �� ������ ���ڸ� �����ϴ� �Լ�

	return a + rand() % (b-a+1);
}

void marbles_if_Computer_smart(int &marbles){  // ���� ������ 4n+1�� �ϱ� ���� ���� (����Ʈ ����� ��쿡��)

	int marbles_before = marbles;  // marbles_before: ��(before) ���� ����
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

void Computer_smart(int &marbles){  // ��ǻ�Ͱ� ������ ������ ������ �� �����ϴ� �Լ�(����Ʈ ����)

	int marbles_before = marbles;  // marbles_before: ��(before) ���� ����
	marbles_if_Computer_smart(marbles);  // ���� ������ 4n+1�� ��
	int computer_take = marbles_before - marbles;  // computer_take: '��(before) ���� - ��(after) ����'�� ��ǻ�Ͱ� ������ ���� ������ ����

	cout << "Computer plays..." << endl;
	cout << "The computer takes " << computer_take << " marbles." << endl;  // ��ǻ�Ͱ� �� ���� ������ ���������� ���
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // ���� ���� ���
	}
}

void Computer_general(int &marbles){  // ��ǻ�Ͱ� ������ ������ ������ �� �����ϴ� �Լ�(�Ϲ� ����)

	int computer_take = Random(1, 3);  // computer_take: ��ǻ�Ͱ� ������ ���� ����(Random)
	cout << "Computer plays..." << endl;
	cout << "The computer takes " << computer_take << " marbles." << endl;  // ��ǻ�Ͱ� �� ���� ������ ���������� ���
	marbles = marbles - computer_take;  // ��ǻ�Ͱ� ������ ���� ������ŭ ��ü ���� ������ ��
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // ���� ���� ���
	}
}

int smart_mode = Random(1,2);  // (���� ����) smart_mode: 1-�Ϲ� ���, 2-����Ʈ ���

void Computer(int &marbles){  // ����Ʈ ����� ���� ����Ʈ ���� �Լ���, �Ϲ� ����� ���� �Ϲ� ���� �Լ��� �����Ŵ

	if(smart_mode == 1){
		Computer_general(marbles);
	} else{
		Computer_smart(marbles);
	}
}

void Player(int &marbles){  // �÷��̾ ������ ������ ������ �� �����ϴ� �Լ�

	int player_take;  // player_take: �÷��̾ ������ ���� ����
	cout << "Your play .. you may take 1, 2, or 3 marbles." << endl;
	cout << "You take ";
	cin >> player_take;  // �� ���� ������ ������ ������ �Է¹ް� ��

	if(player_take!=1 && player_take!=2 && player_take!=3){  // 1,2, 3�� �ƴ� �ٸ� ���� �Է��� ��쿡 �����ϴ� �κ�
		cout << "Ooops... you picked too many or not enough." << endl;
		player_take = Random(1, 3);
		cout << "You will take " << player_take  << " marbles." << endl;
	}
	marbles = marbles - player_take;  // �÷��̾ ������ ���� ������ŭ ��ü ���� ������ ��
	
	if(marbles > 1){
		cout << "There are " << marbles << " marbles in the pile." << endl;  // ���� ���� ���
	}
}

void rand_changing(){  // ���� ���Ѱ��� �ٲٱ� ���� ���

 int change = static_cast <int> (time(0));
 srand(change);

}

int main(){

	string restart;  // restart: yes-������ �������, no-������ ��������� �ʰ� ����

	do{
		rand_changing();

		cout << "Players alternate taking 1, 2, or 3 marbles in the pile.\n";
		cout << "The player who takes the last marble loses." << endl;        // �ʱ� ��¹�
	
		int first_start = Random(1,2);  // first_start: 1-��ǻ�Ͱ� ���� ����, 2-�÷��̾ ���� ����
		if(first_start == 1){  // ���� ���� �����ϴ����� ���� ����� �޸���
			cout << "The computer will play first." << endl;
		} else{
			cout << "You will play first." << endl;
		}
	
		/*  smart_mode: ���� ������ ��������  */
		if(smart_mode == 1){  // ����Ʈ ������� �ƴ����� ���� ����� �޸��� (1-�Ϲ� ���, 2-����Ʈ ���)
			cout << "The computer will play general." << endl;
		} else{
			cout << "The computer will play smart." << endl;
		}

		int marbles;  // marbles: ���� ���� ������ �����ϱ� ���� ����
		if(smart_mode == 1){  // ����Ʈ ����̸� �ʱ� ���� ������ 4n+1�� �� (�ƴϸ� �׳� �������� �ʱ� ���� ������ ����)
			marbles = Random(10,30);
		} else{
			int n = Random(3,7);
			marbles = 4*n+1;
		}
		cout << "There are " << marbles << " marbles in the pile." << endl;  // (�ѹ��� ����)

		int next_turn;  // next_turn: 0-��ǻ�� ����, 1-�÷��̾� ����
		if(first_start == 1){  // �ʱ� �����ڰ� ���������� ���� ���ʸ� �ٲ㰡�鼭 ��� ����

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

		if(next_turn == 0){  // ������ 1���� ������ �� �ºθ� ����
			cout << "You must take the last marble. You lose!" << endl;
		} else{
			cout << "The computer must take the last marble. You win!!" << endl;
		}

		cout << "Do you want to restart this game (yes/no) " ;
		cin >> restart;  // ����� ����


	} while(restart == "yes");

	cout << "\nThanks for Playing our game~!! ^0^" << endl;  // ������� ������ ���� ��� ����� (���Ṯ)
	return 0;
}