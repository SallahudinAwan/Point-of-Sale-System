                   /*Welcome To The Filing.cpp .......*/
/*In this File All The Filing Mechanism Occur Means Input the data and Outputs the data from
                                        the file */

#include"POS.h";
#include<fstream>
/*Filing  Of Items*/
int POS::openfileI(Item**& I) {
	fstream item1("item.txt");
	item1.ignore(256, '\n');
	int i = 0; int TI = 0;//total items
	while (!item1.eof()) {
		item1.ignore(256, '\n');
		TI++;
	}
	item1.close();
	fstream item("item.txt"); item.ignore(256, '\n');
	I = new Item *[TI];
	for (i = 0; i < TI; i++) {
		I[i] = new Item;
	}
	i = 0;
	while (!item.eof()) {
		Helper H;
		char *buff = nullptr; buff = new char[20];
		item.getline(buff, 100, ';'); char* I_SKU = new char[strlen(buff) + 1];
		I_SKU = buff;
		char *buff2 = nullptr; buff2 = new char[30];
		item.getline(buff2, 100, ';'); char* description = new char[strlen(buff2) + 1];
		description = buff2;
		double *price = nullptr; price = new double; item >> *price; item.ignore(1);
		int *quantity = nullptr; quantity = new int; item >> *quantity; item.ignore(1);
		char *buff3 = nullptr; buff3 = new char[20];
		item.getline(buff3, 100, '\n');
		char* Date = new char[strlen(buff3) + 1];
		Date = buff3;
		I[i]->InputItem(I_SKU, description, *price, *quantity, Date);
		buff3 = nullptr; delete buff3; buff = nullptr; delete buff; buff2 = nullptr; delete buff2; price = nullptr; delete price; quantity = nullptr; delete quantity;
		I_SKU = nullptr; delete I_SKU; description = nullptr; delete description; Date = nullptr; delete Date;
		i++;
	}
	return TI;
}
void POS::printinfileI(Item**I, int size) {
	fstream file("item.txt");
	file << "<SKU><Description><Price><AvailableQuantity><CreationDate>"; file << '\n';
	/*for (int i = 0; i < size; i++) {
	I[i]->print();
	}*/int i = 0;
	for (i; i < size; i++) {
		char *ch;
		ch = I[i]->getItem_SKU();
		file << ch; ch = nullptr; delete ch;
		char* ch2;
		ch2 = I[i]->getDescription(); file << ";";
		file << ch2; ch2 = nullptr; delete ch2;
		double ch3 = I[i]->getPrice(); file << ";";
		file << ch3;
		int ch4 = I[i]->getAvailableQuanntity(); file << ";";
		file << ch4; file << ";";
		char* ch5;
		ch5 = I[i]->getDate();
		file << ch5; ch5 = nullptr; delete ch5;
		if (i < size - 1) {
			file << '\n';
		}/*if (i == size - 1) {
		 file.end;
		 }*/
	}
}
void POS::deleteinfileI(Item**I, int size) {
	fstream file("item.txt");
	file << "<SKU><Description><Price><AvailableQuantity><CreationDate>"; file << '\n';
	/*for (int i = 0; i < size; i++) {
	I[i]->print();
	}*/int i = 0;
	for (i; i < size; i++) {
		char *ch;
		ch = I[i]->getItem_SKU();
		file << ch;
		char* ch2;
		ch2 = I[i]->getDescription(); file << ";";
		file << ch2;
		double ch3 = I[i]->getPrice(); file << ";";
		file << ch3;
		int ch4 = I[i]->getAvailableQuanntity(); file << ";";
		file << ch4; file << ";";
		char* ch5;
		ch5 = I[i]->getDate();
		file << ch5;
		if (i < size - 1) {
			file << '\n';
		}if (i == size - 1) {
			file.end;
		}
	}
}
/*Filing of Customers*/
int POS::openfileC() {//,Item &I,Sales &S,SalesLineItem &SLI,Reciept &R
	fstream customer1("Customers.txt");
	customer1.ignore(256, '\n');
	int i = 0; int TC = 0; char ch = '\0';
	while (!customer1.eof()) {
		customer1.ignore(256, '\n');
		customer1 >> ch;
		TC++;
	}
	if (TC <= 0 && ch == '\0') { TC = -1; }
	customer1.close(); static int silvercount2 = 1; static int goldcount2 = 1; static int platinumcount2 = 1;
	fstream customer("Customers.txt");
	if (TC != -1) {
		C = new Customer *[TC];
	}
	for (i = 0; i < TC; i++) {
		C[i] = new Customer;
	}customer.ignore(256, '\n');
	i = 0;
	while (!customer.eof() && TC != 0) {
		SilverCustomers** SC2 = new SilverCustomers *[silvercount2];
		GoldCustomers** GC2 = new GoldCustomers *[goldcount2];
		PlatinumCustomers** PC2 = new PlatinumCustomers *[platinumcount2];
		SC2[silvercount2] = new SilverCustomers;
		GC2[goldcount2] = new GoldCustomers;
		PC2[platinumcount2] = new PlatinumCustomers;
		char *P = nullptr; Helper H; P = new char[20];
		customer.getline(P, 100, ';');
		char *P2 = nullptr; P2 = new char[20];
		customer.getline(P2, 100, ';');
		char *P3 = nullptr; P3 = new char[20];
		customer.getline(P3, 100, ';');
		double phone;
		char *buffer44 = new char[20];
		char *buffer55 = new char[20];
		//buffer44 =new char[20]; 
		//buffer55 = new char[20];
		customer.getline(buffer55, 100, ';');
		customer.getline(buffer44, 100, ';');
		int type = 0; customer >> type; customer.ignore(1);
		double amount; customer >> amount;  customer.ignore(1);
		double limit; customer >> limit;
		customer.ignore(1);
		if (type == 1) {
			SC2[silvercount2]->Silverinput(P, P2, P3, buffer44, buffer55, type, amount);
			C[i] = SC2[silvercount2];
			SC2[silvercount2] = nullptr;
			silvercount2++;
		}
		if (type == 2) {
			//int discount; cout << "Discount(Max=3%) : "; cin >> discount;
			GC2[goldcount2]->Goldinput(P, P2, P3, buffer44, buffer55, type, amount, 3);
			C[i] = GC2[goldcount2];
			GC2[goldcount2] = nullptr;
			goldcount2++;
		}
		if (type == 3) {
			//int discount; cout << "Discount(Max=3%) : "; cin >> discount;
			PC2[platinumcount2]->Platinuminput(P, P2, P3, buffer44, buffer55, type, amount, 5);
			C[i] = PC2[platinumcount2];
			PC2[platinumcount2] = nullptr;
			platinumcount2++;
		}P = nullptr; delete P;  P2 = nullptr; delete P2;  P3 = nullptr; delete P3;   buffer44 = nullptr; delete buffer44;   buffer55 = nullptr; delete buffer55;
		i++;
	}
	return TC;
}
void POS::printinfileC(Customer** C, int size) {
	ofstream file("Customers.txt");
	file << "<CNIC><Name><Address><Phone><Email><Type><AmountPayable><SalesLimit>"; file << "\n";
	/*for (int i = 0; i < size; i++) {
	cout << "Customer " << i + 1 << " Data" << endl;
	C[i]->print();
	}*/
	for (int i = 0; i < size; i++) {
		char* ch;
		ch = C[i]->getCNIC();
		file << ch; ch = nullptr; delete ch;
		char* ch2;
		ch2 = C[i]->getname(); file << ";";
		file << ch2; ch2 = nullptr; delete ch2;
		char* ch3;
		ch3 = C[i]->getAddress(); file << ";";
		file << ch3; ch3 = nullptr; delete ch3;
		char* ch4;
		ch4 = C[i]->getPhonenumber(); file << ";";
		file << ch4; ch4 = nullptr; delete ch4;
		char* ch5;
		ch5 = C[i]->getEmail(); file << ";";
		file << ch5; ch5 = nullptr; delete ch5;
		int type = C[i]->getType(); file << ";";
		file << type;
		double amount = C[i]->getamountpayable(); file << ";";
		file << amount;
		double Sales = C[i]->getSalesLimit(); file << ";";
		file << Sales;
		if (i < size - 1) {
			file << "\n";
		}
	}
}
/*Filing Of Sales*/
int POS::openfileS(Sales**& S, Customer** C, int size, Receipt** R) {
	//size = openfileC();
	ifstream sale1("Sales.txt");
	sale1.ignore(256, '\n');
	int i = 0; int TS = 0;//total items
	while (!sale1.eof()) {
		sale1.ignore(256, '\n');
		TS++;
	}size = openfileC();
	sale1.close();
	ifstream sale("Sales.txt");
	sale.ignore(256, '\n');
	S = new Sales *[TS];
	for (i = 0; i < TS; i++) {
		S[i] = new Sales;
	}
	i = 0; Customer* CC;
	while (!sale.eof()) {//1;36603-1234567-5;10/04/2020;Completed
		Helper H;          //<SaleID><Customer><Receipt><date><status>
		int *ID = new int;
		sale >> *ID; S[i]->setID(*ID); ID = nullptr; delete ID;
		char *buffer2 = new char[20]; sale.ignore(1);
		sale.getline(buffer2, 100, ';'); char* CNIC = new char[strlen(buffer2) + 1];
		CNIC = buffer2; int index = foundcustomer(C, CNIC, size);
		if (index != -1) {
			S[i]->setcustomer(C[index]);
		} buffer2 = nullptr; CNIC = nullptr; delete buffer2; delete CNIC;
		char *buffer3 = nullptr; buffer3 = new char[20]; sale.getline(buffer3, 100, ';');
		char* Date = new char[strlen(buffer3) + 1];
		Date = buffer3; S[i]->setdate(Date); Date = nullptr; buffer3 = nullptr; delete Date; delete buffer3;
		char *buffer4 = nullptr; buffer4 = new char[20]; sale.getline(buffer4, 100, '\n');
		char* status = new char[strlen(buffer4) + 1];
		status = buffer4; S[i]->setstatus(status); status = nullptr; buffer4 = nullptr; delete status; delete buffer4;
		//S[i]->inputSales(ID[i], C[index], Date, status);
		i++;
	}
	return TS;
}
void POS::printinfileS(Sales** S, int size) {
	fstream file("Sales.txt");
	file << "<SaleID><Customer><Receipt><date><status>"; file << '\n';
	/*for (int i = 0; i < size; i++) {
	S[i]->print();
	}*/
	for (int i = 0; i < size; i++) {//1;36603-1234567-5;10/04/2020;Completed
		int ch;
		ch = S[i]->getID();
		file << ch;
		char* ch2 = nullptr; Customer* SS; SS = S[i]->getcustomer(); if (SS != nullptr) { ch2 = SS->getCNIC(); }
		file << ";";
		if (ch2 != nullptr) {
			file << ch2;
		}
		else { file << "           "; }
		file << ";";
		ch2 = nullptr; delete ch2;
		char* ch5;
		ch5 = S[i]->getdate();
		file << ch5; file << ";"; ch5 = nullptr; delete ch5;
		char* ch6;
		ch6 = S[i]->getstatus();
		file << ch6; ch6 = nullptr; delete ch6;
		if (i < size - 1) {
			file << '\n';
		}
		/*if (i < size) {
		file.close();
		}*/
	}
}
/*Filing Of SalesLineItem*/
int POS::openfileSLI(SalesLineItem **&R, Sales** S, Item**I, int sizesale, int sizeitem) {
	fstream sale1("SalesLineItem.txt"); //Customer**CC; CC = nullptr;
	Receipt **RR = nullptr; int size = openfileC(); sizesale = openfileS(S, C, size, RR); sizeitem = openfileI(I);
	sale1.ignore(256, '\n');
	int i = 0; int TSI = 0;//total items
	while (!sale1.eof()) {
		sale1.ignore(256, '\n');
		TSI++;
	}
	sale1.close(); fstream sale("SalesLineItem.txt"); sale.ignore(256, '\n');
	R = new SalesLineItem *[TSI];
	for (i = 0; i < TSI; i++) {
		R[i] = new SalesLineItem;
	}
	i = 0;
	int j = 0;
	while (!sale.eof()) {/*<LineNo><Sales><Item><Quantity>
						 1;1;00123;2*/
		Helper H;          //int size = openfileC(CC); sizesale = openfileS(S, CC, size, RR);
		int *ID = new int;
		sale >> *ID; R[i]->setline(*ID);
		ID = nullptr; delete ID;
		int *buffer2 = new int; sale.ignore(1);
		sale >> *buffer2; sale.ignore(1);  int *II = new int; *II = 0; int Original;
		for (int i = 0; i < sizesale; i++) {
			*II = S[i]->getID(); if (*II == *buffer2) {
				Original = i;
			}
		}if (II != nullptr) {
			II = nullptr; delete II;
		}
		buffer2 = nullptr; delete buffer2;
		R[i]->setsale(S[Original]);
		//Sales *SS = new Sales;SS=R[Original]->getsale(); R[i]->setsale(SS);
		char *buffer4 = new char[20]; //char buff; sale >> buff;
		sale.getline(buffer4, 100, ';'); //sizeitem = openfileI(I);
		int index = finditemthoughall(I, sizeitem, buffer4, "\0", 0, 0, "\0");
		R[i]->setitem(I[index]); buffer4 = nullptr; delete buffer4;
		//Item *T = new Item;T= R[index]->getitem(); R[i]->setitem(T);
		int *Quan = new int; sale >> *Quan; R[i]->setquantity(*Quan); sale.ignore(1);
		Quan = nullptr; delete Quan;
		i++;
	}
	return TSI;
}
void POS::printinfileSLI(SalesLineItem** R, int size) {
	fstream file("SalesLineItem.txt");
	file << "<LineNo><Sales><Item><Quantity>"; file << '\n';
	/*for (int i = 0; i < size; i++) {
	R[i]->print();
	}*/
	for (int i = 0; i < size; i++) {//1;36603-1234567-5;10/04/2020;Completed
		int *ch = new int;
		*ch = R[i]->getline();
		file << *ch; ch = nullptr; delete ch;
		int *ch2 = new int; //Customer* SS; SS = S[i]->getcustomer(); ch2 = SS->getCNIC();
		file << ";"; *ch2 = R[i]->getSaleID();
		file << *ch2; file << ";"; ch2 = nullptr; delete ch2;
		char* ch5 = new char[20]; ch5 = R[i]->getitemSKU();
		file << ch5; file << ";"; ch5 = nullptr; delete ch5;
		int *Quan = new int; *Quan = R[i]->getquantity();
		file << *Quan; Quan = nullptr; delete Quan;
		if (i < size - 1) {
			file << '\n';
		}
		/*if (i < size) {
		file.close();
		}*/
	}
}
/*Filing Of Receipt*/
int POS::openfileR(Receipt **&R, Sales** S, int size) {
	fstream sale1("Receipt.txt");
	sale1.ignore(256, '\n');
	int i = 0; int TR = 0;//total items
	while (!sale1.eof()) {
		sale1.ignore(256, '\n');
		TR++;
	}
	sale1.close(); fstream sale("Receipt.txt"); sale.ignore(256, '\n');
	R = new Receipt *[TR];
	for (i = 0; i < TR; i++) {
		R[i] = new Receipt;
	}
	i = 0;
	int j = 0;
	while (!sale.eof()) {//<ReceiptNo><ReceiptDate><Sales><Amount>
		Helper H;          //<SaleID><Customer><Receipt><date><status>
		int *ID; ID = new int;
		sale >> *ID; R[i]->setReceiptNo(i + 1); ID = nullptr; delete ID;
		char *buffer2 = nullptr; buffer2 = new char[20]; sale.ignore(1);
		sale.getline(buffer2, 100, ';'); char* Date = new char[strlen(buffer2) + 1];
		Date = buffer2; R[i]->setDate(Date); buffer2 = nullptr; delete buffer2; Date = nullptr; delete Date;
		int *saleID, *saleID2; saleID = new int; saleID2 = new int; *saleID2 = S[i]->getID(); sale >> *saleID;
		if (*saleID == *saleID2) { R[i]->setsale(S[i]); }sale.ignore(1); saleID = nullptr; saleID2 = nullptr; delete saleID; delete saleID2;
		double *amount = nullptr; amount = new double; sale >> *amount; R[i]->setAmount(*amount);
		i++;
	}
	return TR;
}
void POS::printinfileR(Receipt** R, int size) {
	fstream file("Receipt.txt");
	file << "<ReceiptNo><ReceiptDate><Sales><Amount>"; file << '\n';
	/*for (int i = 0; i < size; i++) {
	R[i]->print();
	}*/
	for (int i = 0; i < size; i++) {//1;36603-1234567-5;10/04/2020;Completed
		int *ch = nullptr; ch = new int;
		*ch = R[i]->getReceiptNo();
		file << *ch; ch = nullptr; delete ch;
		char* ch2; //Customer* SS; SS = S[i]->getcustomer(); ch2 = SS->getCNIC();
		file << ";"; ch2 = R[i]->getReceiptdate();
		file << ch2; file << ";"; ch2 = nullptr; delete ch2;
		int  *ch5; Sales *s; s = R[i]->getsale(); int j = s->getID();
		file << j; file << ";"; ch5 = nullptr; delete ch5;
		double amount; amount = R[i]->getAmount();
		file << amount;
		if (i < size - 1) {
			file << '\n';
		}
		/*if (i < size) {
		file.close();
		}*/
	}
}