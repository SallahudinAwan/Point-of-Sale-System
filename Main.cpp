#include<iostream>
#include"POS.h";
using namespace std;
                      /*Welcome to The Main Of Project (Point Of Sale)*/
int main() {
	POS *P = new POS;
	P->InputFromFileInAllPointers();
	bool Back=true; int MenuMain = 0; int s1 = 0;
	for (int i = 0; Back; i++) {
		P->openfileC();
		MenuMain=P->MainMenu();
		if (MenuMain == 1) {
			Back = P->ItemMenu();
		}
		if (MenuMain == 2) {
			Back = P->CustomerMenu();
		}
		if (MenuMain == 3) {
			Back = P->MakeNewSale();
			Back = true;
		}
		if (MenuMain == 4) {
			Back = P->MakePayment();
		}
		if (MenuMain == 5) {
			Back = false;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Thanks for using This Software!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		}
	}
	system("pause");
	return 0;

}






