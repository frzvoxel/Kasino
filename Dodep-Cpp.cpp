#include <iostream> // preproseccor
#include <Windows.h>
#include <clocale>
#include <cstdlib> 
#include <ctime>   

struct plr // Characteristics
{
	int Balance; // player balance
	int Bid; // Player Bid
	int Input; // Player Input
};

plr Player; // global announcement
// global varibales
bool Check = true;

void MakeBid(); // prototypes
void Kasik(); // prototypes
void CheckWin();

using namespace std; // namespace??

int main() { // entry point
	srand(static_cast<unsigned int>(std::time(0))); // time-based randomness
	setlocale(LC_ALL, "Russian"); // set locale

	Player.Balance = 150; // Set Default Balance

	while (Check) { // cycle
		system("cls"); // clear console
		cout << "Dodep Simulator\n\n"; // logo


		cout << "Balance: " << Player.Balance; // Print Balance

		Beep(100, 100); // funny beep


		cout << "\n Привет злые баллерки украли твой дом и оставили тебе всего 150 рублев отыграйся! на 5000\n\n"; // ?

		cout << "Ваша ставочка?)) "; // just print
		MakeBid(); // call function
		Kasik(); // call function
		CheckWin(); // call function
	}

	return 0; 
}


void MakeBid() {
	while (true) { 
		cin >> Player.Bid;

		if (Player.Bid <= Player.Balance && Player.Bid > 0) {
			return; 
		}

		cout << "\033[31m Ошибка! Ставка больше баланса или равна 0. Попробуй еще раз: \033[0m";
	}
}

void CheckWin() {
	if (Player.Balance >= 5000) {
		cout << "Победа!";
		Check = false;

		Sleep(2000);

		return;
	}

	if (Player.Balance <= 0) {
		cout << "Банкрот!";
		Check = false;

		Sleep(2000);

		return;
	}
}

void Kasik() {
	int min = 1, max = 10;
	int Target = min + rand() % (max - min + 1);
	cout << "Число выпало! От 0 до 10 ";
	
	cin >> Player.Input;

	if (Player.Input > 10 || Player.Input < 0) {
		cout << "Э, мабой, ты куда за границы лезешь?";
		
		Sleep(5000);

		return;
	}

	if (abs(Player.Input - Player.Bid) <= min) {
		cout << "Угадал!";
		Player.Balance += (Player.Bid * 0.5);

		Sleep(5000);

		return;
	}
	else {
		cout << "\033[31m Не угадал(( \033[0m";

		if (Player.Balance > 1) {
			Player.Balance /= (Player.Bid / 1.5);
		}
		else {
			Player.Balance -= Player.Bid;
		}



		Sleep(5000);

		return;
	}
}