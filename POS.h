#include<iostream>
#include<cmath>
#include <ctime>
#include<Windows.h>
using namespace std;
                       /*Welcome to the Header file of project (Point Of Sale System)*/
/* Helper Functions for copying , finding length and comparing*/
class Helper
{
public:
	int mystrlen(char* a) {
		int count = 0;
		for (int i = 0; a[i] != '\0'; i++) {
			count++;
		}
		return count;
	};
	bool mystrcmp(char* a, char* b) {
		if (mystrlen(a) != mystrlen(b)) {
			return false;
		}
		for (int i = 0; i < mystrlen(a); i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	};
	void mystrcpy(char*& a, char* s) {
		 Helper b;
		 int k = b.mystrlen(s);
		 int i;
		 for (i = 0; i < k; i++) {
			 a[i] = s[i];
		 }
		 a[i] = '\0';
	 };
};

class Item {
protected:
	char *Item_SKU;
	char *Description;
	double Price;
	int AvailableQuantity;
	char *CreationDate;
public:
	/*Default Constructor*/
	Item() {
		Description = nullptr;
		Item_SKU = nullptr;
		CreationDate = nullptr;
	};//default
	/*Parametrized Constructor*/
	Item(char *I_SKU, char* _description, double _price, int _Quantity, char *date) {
		Item_SKU = I_SKU;
		Description = _description;
		Price = _price;
		AvailableQuantity = _Quantity;
		CreationDate = date;
	};
	/*Input Function To Set all the values at Once*/
	void InputItem(char *I_SKU, char* _description, double _price, int _Quantity, char *date) {
		Item_SKU = I_SKU;
		Description = _description;
		Price = _price;
		AvailableQuantity = _Quantity;
		//CreationDate = getlatestdate();
		CreationDate = date;
	}
	                                   /*Setters*/
	void setItem_SKU(char *ch) {
		Item_SKU = ch;
	};
	void setDescription(char *D) {
		Description = D;
	};
	void setPrice(double P) {
		Price = P;
	};
	void setAvailableQuanntity(int Q) {
		AvailableQuantity = Q;
	};
	void setDate(char *Date) {
		CreationDate = Date;
	};
	                                  /*Getters*/
	char* getItem_SKU() {
		return Item_SKU;
	};
	char *getDescription() {
		return Description;
	};
	double getPrice() {
		return Price;
	};
	int getAvailableQuanntity() {
		return AvailableQuantity;
	};
	char* getDate() {
		return CreationDate;
	};
	                                 /*Printers*/
	void print() {
		cout << "\t\t" << Item_SKU << "\t\t";
		cout << Description << "\t\t";
		cout << Price << "\t\t";
		cout << AvailableQuantity << endl;
		//cout  << CreationDate << endl;
	}
	void printSKU() {
		cout << Item_SKU;
	}
	void printDescription() {
		cout << Description;
	}
	                              /*Destructors*/
	void deleteItem() {
		if (Item_SKU == nullptr) {
			Item_SKU = nullptr; delete Item_SKU;
		}if (Description == nullptr) {
			Description = nullptr; delete Description;
		}if (CreationDate == nullptr) {
			CreationDate = nullptr; delete CreationDate;
		}
	}
	~Item() {
		if (Item_SKU == nullptr) {
			Item_SKU = nullptr; delete Item_SKU;
		}if (Description == nullptr) {
			Description = nullptr; delete Description;
		}if (CreationDate == nullptr) {
			CreationDate = nullptr; delete CreationDate;
		}
	};

};
/*Class of Customer*/

class Customer {
protected:
	char* CNIC, *Name, *Address, *Email, *Phone;
	double AmountPayable, SalesLimit; int Type;
public:
	Customer() {
		CNIC = nullptr;
		Name = nullptr;
		Address = nullptr;
		Email = nullptr;
		Type = 0;
		AmountPayable = 0;
		SalesLimit = 0;  Phone = nullptr;
	};
	Customer(char* cnic, char* name, char* adress, char* email, int type, double Amount, double saleslimit, char * phone) {
		CNIC = cnic;
		Name = name;
		Address = adress;
		Email = email;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = saleslimit;  Phone = phone;
	};
	/*setters*/
	void setCNIC(char *cnic) {
		CNIC = cnic;
	}; 
	void setamountpayable(double amount) {
		AmountPayable = amount;
	};
	void  setname(char *name) {
		Name = name;
	}; 
	void setSalesLimit(int saleslimit) {
		SalesLimit = saleslimit;
	};
	void setAddress(char *address) {
		Address = address;
	}; 
	void setPhonenumber(char * phonenumber) {
		Phone = phonenumber;
	};
	void setEmail(char *email) {
		Email = email;
	};
	void setType(int type) {
		Type = type;
	};
	/*getters*/
	char* getCNIC() {
		if (CNIC != nullptr) {
			return CNIC;
		}
	}; 
	int getamountpayable() {
		return AmountPayable;
	};
	char * getname() {
		return Name;
	}; 
	int getSalesLimit() {
		return SalesLimit;
	};
	char * getAddress() {
		return Address;
	}; 
	char* getPhonenumber() {
		return Phone;
	};
	char* getEmail() {
		return Email;
	};
	virtual int getdiscount() {
		return 0;
	};
	int getType() {
		return Type;
	};
	/*Printers*/
	virtual void print() {
		cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\tCNIC\t\t"; cout << "Name\t\t"; cout << "Address\t\t\t"; cout << "     Email\t\t\t"; cout << "    Phone\t\t"; cout << "Sales-Limit\n";
		cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (CNIC != nullptr) {
			cout << "" << CNIC << "\t\t";
		}if (Name != nullptr) {
			cout << Name << "\t";
		}if (Address != nullptr) {
			cout << Address << "\t\t";
		}if (Email != nullptr) {
			cout << Email << "\t\t";
		}if (Phone != nullptr) {
			cout << Phone << "\t\t";
		}
		//cout << "Type = " << Type << endl;
		//cout << "Amount-Payable = " << AmountPayable << endl;
		cout << SalesLimit << "\t\t" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	void printCNIC() {
		cout << CNIC;
	}
	void printname() {
		cout << Name;
	}
	void printemail() {
		cout << Email;
	}
	void printtype() {
		int i = this->getType();
		if (i = 1) {
			cout << "Silver Customer";
		}if (i == 2) {
			cout << "Gold Customer";
		}
		if (i == 3) {
			cout << "Platinum Customer";

		}
	}
	/*Copy Constructor*/
	Customer& operator = (Customer C) {
		Helper H;
		this->CNIC = new char[strlen(C.CNIC) + 1];
		H.mystrcpy(this->CNIC, C.CNIC);
		this->Name = new char[strlen(C.Name) + 1];
		H.mystrcpy(this->Name, C.Name);
		this->Address = new char[strlen(C.Address) + 1];
		H.mystrcpy(this->Address, C.Address);
		this->Email = new char[strlen(C.Email) + 1];
		H.mystrcpy(this->Email, C.Email);
		this->Phone = new char[strlen(C.Phone) + 1];
		H.mystrcpy(this->Phone, C.Phone);
		this->SalesLimit = C.SalesLimit;
		this->AmountPayable = C.AmountPayable;
		this->Type = C.Type;
		return *this;
	}
	/*Destructors*/
	void deletecustomer() {
		if (CNIC != nullptr) {
			CNIC = nullptr;
			delete CNIC;
		}if (Email != nullptr) {
			Email = nullptr;
			delete Email;
		}if (Name != nullptr) {
			Name = nullptr;
			delete Name;
		}if (Address != nullptr) {
			Address = nullptr;
			delete Address;
		}

	}
	virtual ~Customer() {
		if (CNIC != nullptr) {
			CNIC = nullptr;
			delete CNIC;
		}if (Email != nullptr) {
			Email = nullptr;
			delete Email;
		}if (Name != nullptr) {
			Name = nullptr;
			delete Name;
		}if (Address != nullptr) {
			Address = nullptr;
			delete Address;
		}
	};
};

/*Child classes OF Customer*/
class SilverCustomers :public Customer {//The sales limit for silver customer is 40, 000
public:
	SilverCustomers() {
		CNIC = nullptr;
		Name = nullptr;
		Address = nullptr;
		Email = nullptr;
		Type = 0;
		AmountPayable = 0;
		SalesLimit = 40000;  Phone = nullptr;
	};
	SilverCustomers(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount) {
		CNIC = cnic;
		Name = name;
		Address = adress;
		Email = email;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 40000;  Phone = phone;
	};
	void Silverinput(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount) {
		CNIC = cnic;
		Name = name;
		Address = adress;
		Email = email;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 40000;  Phone = phone;
	};

	SilverCustomers & operator = (Customer C) {
		Helper H; char *cnic; cnic = C.getCNIC();
		this->CNIC = new char[strlen(cnic) + 1];
		H.mystrcpy(this->CNIC, cnic); char *name; name = C.getname();
		this->Name = new char[strlen(name) + 1];
		H.mystrcpy(this->Name, name); char *address; address = C.getAddress();
		this->Address = new char[strlen(address) + 1];
		H.mystrcpy(this->Address, address); char *email; email = C.getEmail();
		this->Email = new char[strlen(email) + 1];
		H.mystrcpy(this->Email, email); char *phone; phone = C.getPhonenumber();
		this->Phone = new char[strlen(phone) + 1];
		H.mystrcpy(this->Phone, phone);
		this->SalesLimit = 40000; double amount; amount = C.getamountpayable();
		this->AmountPayable = AmountPayable; int type; C.getType();
		this->Type = type;
		return *this;
	} 
	void print() {
		Customer::print();
	}
	int getdiscount() {
		return 0;
	};
	/*Destructors*/
	~SilverCustomers()
	{
		/*No Need to implement Destructor Because no Variable should be deleted*/
	}
};
class GoldCustomers : public Customer {//Maximum discount to GoldCustomers will be 3 % andsales limit is 100, 000
	int Discount;
public:
	GoldCustomers() {
		CNIC = nullptr;
		Name = nullptr;
		Address = nullptr;
		Email = nullptr;
		Type = 0;
		AmountPayable = 0;
		SalesLimit = 100000;  Phone = nullptr;
	};
	GoldCustomers(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount, int discount) {
		CNIC = cnic;
		Name = name;
		Address = adress;
		Email = email;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 100000;  Phone = phone;
		if (discount > 3) {
			discount = 3;
		}
		else {
			Discount = discount;
		}
	};
	void Goldinput(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount, int discount) {
		CNIC = cnic;
		Name = name;
		Address = adress;
		Email = email;
		Phone = phone;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 100000;
		if (discount > 3) {
			discount = 3;
		}
		else {
			Discount = discount;
		}
	};
	int getdiscount() {
		return Discount;
	};
	/*Destructors*/
	~GoldCustomers()
	{
		/*No Need to implement Destructor Because no Variable should be deleted*/
	}
};
class PlatinumCustomers : public Customer {//Maximum discount to PlatinumCustomers will be 5% and sales limit is 250,000
	int Discount;
public:
	PlatinumCustomers() {
		CNIC = nullptr;
		Name = nullptr;
		Address = nullptr;
		Email = nullptr;
		Type = 0;
		AmountPayable = 0;
		SalesLimit = 40000;  Phone = nullptr;
	};
	PlatinumCustomers(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount, int discount) {
		CNIC = new char[strlen(cnic) + 1]; Helper H; H.mystrcpy(CNIC, cnic); CNIC = cnic;
		Name = new char[strlen(name) + 1]; H.mystrcpy(Name, name); Name = name;
		Address = new char[strlen(adress) + 1]; H.mystrcpy(Address, adress); Address = adress;
		Email = new char[strlen(email) + 1]; H.mystrcpy(Email, email); Email = email;
		Phone = new char[strlen(phone) + 1]; H.mystrcpy(Phone, phone); Phone = phone;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 250000;
		if (discount > 5) {
			discount = 5;
		}
		else {
			Discount = discount;
		}
	};
	void Platinuminput(char* cnic, char* name, char* adress, char* email, char * phone, int type, double Amount, int discount) {
		CNIC = new char[strlen(cnic) + 1];
		Helper H; H.mystrcpy(CNIC, cnic); CNIC = cnic;
		Name = new char[strlen(name) + 1]; H.mystrcpy(Name, name); Name = name;
		Address = new char[strlen(adress) + 1]; H.mystrcpy(Address, adress); Address = adress;
		Email = new char[strlen(email) + 1]; H.mystrcpy(Email, email); Email = email;
		Phone = new char[strlen(phone) + 1]; H.mystrcpy(Phone, phone); Phone = phone;
		Type = type;
		AmountPayable = Amount;
		SalesLimit = 250000;
		if (discount > 5) {
			discount = 5;
		}
		else {
			Discount = discount;
		}
	};
	int getdiscount() {
		return Discount;
	};
	//only difference between platinum and GOld customer is discount % limit
	/*Destructors*/
	~PlatinumCustomers()
	{
		/*No Need to implement Destructor Because no Variable should be deleted*/
	}
};


/*Sales class*/
class Receipt;
class Sales {
	int SaleID;//<SaleID><Customer><SalesLineItem><Receipt><date><status>
	Customer *C;
	Receipt *R;
	char* date; char *status;
public:
	Sales() {
		SaleID = 0;
		C = nullptr;
		R = nullptr;
		date = nullptr;
		status = nullptr;
	}
	Sales(int ID, Customer *CC, Receipt *RR, char * Date, char *STATUS) {
		SaleID = ID;
		C = CC;
		R = RR;
		date = Date;
		status = STATUS;
	}
	/*Overall Input Function */
	void inputSales(int ID, Customer *CC, Receipt *RR, char * Date, char *STATUS) {
		SaleID = ID;
		C = CC;
		R = RR;
		date = Date;
		status = STATUS;
	}
	/*= Operator is used to copy one Object to other object*/
	Sales &operator=(Sales S) {
		this->SaleID = S.SaleID;
		this->C = S.C;
		this->R = S.R;
		this->date = S.date;
		this->status = S.status;
		return *this;
	}
	/*Setters*/
	void setID(int ID) {
		SaleID = ID;
	}
	void setdate(char * Date) {
		date = Date;
	}
	void setstatus(char *_S) {
		status = _S;
	}
	void setcustomer(Customer *CC) {
		C = CC;
	}
	void setreceipt(Receipt *RR) {
		R = RR;
	}
	/*Getters*/
	int getID() {
		return SaleID;
	}
	char * getdate() {
		return date;
	}
	char * getstatus() {
		return status;
	}
	Customer * getcustomer() {
		return C;
	}
	Receipt *getreceipt() {
		return R;
	}
	/*Printer*/
	void print() {
		cout << "SalesID : " << SaleID << "\t\t\t";
		cout << "CNIC : "; C->printCNIC(); cout << endl;
		cout << "Sales Date : " << date << "\t\t\t";
		cout << "Name : "; C->printname(); cout << endl;
		cout << "Type : "; C->printtype(); cout << endl;
	}
    /*Destructors*/
	void deleteSale() {
		if (C != nullptr) {
			C = nullptr;
		}if (R != nullptr) {
			R = nullptr;
		}if (date != nullptr) {
			date = nullptr; delete date;
		}if (status != nullptr) {
			status = nullptr; delete status;
		}
	}
	~Sales()
	{
		if (C != nullptr) {
			C->deletecustomer(); C = nullptr;
		}if (R != nullptr) {
			R = nullptr;
		}if (date != nullptr) {
			date = nullptr; delete date;
		}if (status != nullptr) {
			status = nullptr; delete status;
		}

	}
};
class SalesLineItem {/*<LineNo><Sales><Item><Quantity>
					 1;    1;    00123;  2
					 2;    1;    1000S;  10
					 3;    2;    1000S;  2*/
	int LineNo; Sales *S; Item *I; int  Quantity;
public:
	SalesLineItem() {
		LineNo = 0;
		Quantity = 0;
		S = nullptr;
		I = nullptr;
	};
	SalesLineItem(int Line, Sales *SS, Item* II, int  Q) {
		LineNo = Line;
		Quantity = Q;
		S = SS;
		I = II;
	};
	void InputSaleslineitem(int Line, Sales *SS, Item* II, int  Q) {
		LineNo = Line;
		Quantity = Q;
		S = SS;
		I = II;
	}
	/*= operator For Copy The Object*/
	SalesLineItem &operator=(SalesLineItem SS) {
		this->LineNo = SS.LineNo;
		this->Quantity = SS.Quantity;
		this->S = SS.S;
		this->I = SS.I;
	}
	/*Setters*/
	void setline(int Lineno) {
		LineNo = Lineno;
	}
	void setSalesID(int ID) {
		S->setID(ID);
	}
	void setsale(Sales *_S) {
		S = _S;
	}
	void setItemSKu(char *SKU) {
		I->setItem_SKU(SKU);
	}
	void setitem(Item *_I) {
		I = _I;
	}
	void  setquantity(int  _Quantity) {
		Quantity = _Quantity;
	}
	/*Getters*/
	int getline() {
		return LineNo;
	} 
	Sales *getsale() {
		return S;
	} 
	Item *getitem() {
		return I;
	}
	int getquantity() {
		return 	Quantity;
	}
	int getSaleID() {
		return S->getID();
	}
	char* getitemSKU() {
		return I->getItem_SKU();
	}
	/*Printers*/
	void print() {
		cout << LineNo << "\t\t";
		cout << S->getID() << "\t\t";
		cout << I->getItem_SKU() << "\t\t";
		cout << Quantity << endl;
	}
	void printlineitem() {
		I->printSKU(); cout << "\t\t";
		I->getDescription(); cout << "\t\t";
		cout << Quantity << "\t\t"; double price; price = I->getPrice(); double Total; Total = price*Quantity;
		cout << Total << endl;
	}
	void printlineno() {
		cout << LineNo;
	}
	void printQuantity() {
		cout << Quantity;
	}
	void PrintSaleID() {
		cout << S->getID();
	}
	void printitemSKU() {
		cout << I->getItem_SKU();
	}
	/*Destructors*/
	void deletesaleslineitem() {
		if (S != nullptr) {
			S->deleteSale(); S = nullptr; delete S;
		}if (I != nullptr) {
			I->deleteItem();
			I = nullptr; delete I;
		}
	}
	~SalesLineItem()
	{
		if (S != nullptr) {
			S->deleteSale(); S = nullptr; delete S;
		}if (I != nullptr) {
			I->deleteItem();
			I = nullptr; delete I;
		}

	}

};
/*Receipt Class*/
class Receipt {
	int ReceiptNo; char* ReceiptDate; Sales *S;
	double Amount;
public:
	Receipt() {
		ReceiptNo = 0;
		ReceiptDate = nullptr;
		S = nullptr;
		Amount = 0;
	}
	Receipt(int RN, char *RD, Sales *s, double amount) {
		S = s;
		ReceiptNo = RN;
		ReceiptDate = RD;
		Amount = amount;
	}
	void Inputinreceipt(int RN, char *RD, Sales *s, double amount) {
		S = s;
		ReceiptNo = RN;
		ReceiptDate = RD;
		Amount = amount;
	}
	/*Setters*/
	void setDate(char *date) {
		ReceiptDate = date;
	}
	void setsale(Sales *s) {
		S = s;
	}
	void setReceipt(char *RD) {
		ReceiptDate = RD;
	}
	void setReceiptNo(int RN) {
		ReceiptNo = RN;
	}
	void setAmount(double amount) {
		Amount = amount;
	}
	/*Getters*/
	Sales* getsale() {
		return S;
	}
	char* getReceiptdate() {
		return ReceiptDate;
	}
	int getReceiptNo() {
		return ReceiptNo;
	}
	double getAmount() {
		return Amount;
	}
	/*Printer*/
	void print() {
		cout << "Receipt No : " << ReceiptNo << "\t";
		cout << "Receipt Date : " << ReceiptDate << "\t";
		cout << "Sales : "; int i = S->getID(); cout << i << "\t";
		cout << "Amount : " << Amount << endl;
	}
	/*Destructor*/
	~Receipt()
	{
		if (ReceiptDate != nullptr) {
			ReceiptDate = nullptr; delete ReceiptDate;
		}
		if (S != nullptr) {
			S->deleteSale(); S = nullptr; delete S;
		}
	}

};

/*POS Class*/
/*Child class of (Item ,Customer, Sales and Receipt)
and have all the command on all these classes
and use any of the functionality of
these 4 classes and their
subclasses(child) as well */
class POS {
	Item **I;  Customer **C; Sales **S;  Receipt **R; SalesLineItem **SLI;
public:
	/*Public Variables*/
	int size; int sizeofitems;  int sizeofSalelineitem;  int sizeofSale;  int sizeofReceipt;
	POS() {
		I = nullptr;
		C = nullptr;
		S = nullptr;
		R = nullptr;
		SLI = nullptr;
	};


	/*No Need to Implement a Parametrized Constructor*/

	/*General Functions*/
	/*Get The Date OF That Particular Day means current date of your PC*/
	char*getlatestdate() {
		time_t t = time(NULL);// time_t tt= time(NULL);
		tm* timePtr = new tm[20];
		localtime_s(timePtr, &t);
		char *ch = new char[12];
		int day = (timePtr->tm_mday);
		int mon = (timePtr->tm_mon) + 1;
		int year = (timePtr->tm_year) + 1900;
		char *ch2 = new char[10];
		_itoa_s(day, ch2, 10, 10);
		char*ch3 = new char[10];
		_itoa_s(mon, ch3, 10, 10);
		char*ch4 = new char[10];
		_itoa_s(year, ch4, 10, 10);
		int i = 0;
		for (i; ch2[i] != '\0'; i++) {
			ch[i] = ch2[i];
		}int j = 0; ch[i] = '/'; i++;
		for (j; ch3[j] != '\0'; j++) {
			ch[i] = ch3[j];
			i++;
		}ch[i] = '/'; i++;
		for (int k = 0; ch4[k] != '\0'; k++) {
			ch[i] = ch4[k];
			i++;
		}ch[i] = '\0';
		ch2 = nullptr; delete ch2;
		ch3 = nullptr; delete ch3;
		ch4 = nullptr; delete ch4;
		return ch;
	}
	void delay(int delay)
	{
		int now = time(NULL);
		int later = now + delay;
		while (now <= later)now = time(NULL);
	}

	/*All Important work Done Here*/

	int MainMenu() {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		cout << "Main Menu" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "1- Manage Items" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "2- Manage Customers" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "3 - Make New Sale" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "4 - Make Payment" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "5 - Exit" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		int MainMenu;
		cin >> MainMenu;
		return MainMenu;
	};
	bool ItemMenu() {
		system("cls");
	Itemmenu:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46); 
		cout << "Items Menu" << endl<<endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "1- Add new Item" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "2 - Update Item details" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "3 - Find Items" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "4 - Remove Existing Item" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout<<"5 - Back to Main Menu" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			 int IM;
			 cin >> IM;
			 system("cls");
			 if (IM == 1) {
				 I[sizeofitems] = new Item;
				 char ch[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 cout << "Item_SKU : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
				 cin.getline(ch, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				 char ch2[20];  cout << "Description : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 cin.getline(ch2, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 double ch3;  cout << "Price : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 cin >> ch3; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				 int ch4;  cout << "Quantity : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 cin >> ch4; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 char *ch5;  cout << "Date : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 ch5 = getlatestdate(); cout << ch5 << endl;
				 /*getchar();
				 cin.getline(ch5, 100);*/
				 I[sizeofitems]->InputItem(ch, ch2, ch3, ch4, ch5);
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				 cout << "If u Want to Save this changes and add it in list press S : ";
				 char save; cin >> save;
				 if (save == 'S' || save == 's') {
					 printinfileI(I, sizeofitems + 1);
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "Item Information successfully saved" << endl;
				 }ch5 = nullptr; delete ch5;
				 sizeofitems++;
			 }
			 if (IM == 2) {
				 char SKU[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 cout << "Item_SKU : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 getchar(); cin.getline(SKU, 20);
				 int i = foundItem(I, SKU, sizeofitems);
				 if (i != -1) {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "If You Want To Change Any Detail then Change it OR Leave Blank" << endl;
					 char ch[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);  cout << "Item_SKU : "; //getchar();
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch, 100);
					 if (ch[0] != '\0') {
						 I[i]->setItem_SKU(ch);
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 char ch2[20];  cout << "Description : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch2, 100);
					 if (ch2[0] != '\0') {
						 I[i]->setDescription(ch2);
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 double ch3;  cout << "Price(Press 0 for Blank) : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin >> ch3;
					 if (ch3 != 0) {
						 I[i]->setPrice(ch3);
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "Quantity : "; int Q; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin >> Q;
					 if (Q != 0) {
						 I[i]->setAvailableQuanntity(Q);
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch5[20];  cout << "Date : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 getchar();
					 cin.getline(ch5, 100);
					 if (ch5[0] != '\0') {
						 I[i]->setDate(ch5);
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "If u Want to Save this changes and add it in list press S : ";
					 char save; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin >> save;
					 if (save == 'S' || save == 's') {
						 printinfileI(I, sizeofitems);
						 sizeofitems = openfileI(I);
						 printinfileI(I, sizeofitems); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "Item Information successfully saved" << endl;
					 }
				 }
				 else {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "Customer Not Found" << endl;
				 }
				 //delay(5);
				 //system("cls");

			 }
			 if (IM == 3) {
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 cout << "Please specify at least one of the following to find the Item. Leave all fields blank to return to Customers Menu :" << endl;
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				 cout << "Enter 0 In Price and Quantity....== Blank " << endl;
				 char ch[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);  cout << "Item_SKU : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
				 cin.getline(ch, 100);
				 char ch2[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94); cout << "Description : ";
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 cin.getline(ch2, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 double ch3;  cout << "Price : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				 cin >> ch3; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				 int ch4; cout << "Quantity : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin >> ch4;
				 char ch5[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79); cout << "Date : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
				 cin.getline(ch5, 100);
				 int l = finditemthoughall(I, sizeofitems, ch, ch2, ch3, ch4, ch5);
				 if (l != -1) {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "---------------------------------------------------------------------------------------------------" << endl;
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cout << "\t\tItem_SKU" << "\t" << "Description" << "\t\t" << "Price" << "\t\t" << "Quantity" << endl;
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "---------------------------------------------------------------------------------------------------" << endl;
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 I[l]->print();
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "---------------------------------------------------------------------------------------------------" << endl;
				 }
				 else {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "Item Not Found" << endl;
				 }
				 //delay(10);
				 //system("cls");
			 }
			 if (IM == 4) {
				 char SKU[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				 cout << "Item_SKU : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar(); cin.getline(SKU, 20);
				 int i = foundItem(I, SKU, sizeofitems);
				 if (i != -1) {
					 I[i]->deleteItem();
					 I[i] = nullptr; sizeofitems--;
					 for (i; i < sizeofitems; i++) {
						 I[i] = I[i + 1];
					 }
					 I[sizeofitems] = nullptr;
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "If you Want to Save this changes and add it in list press S : ";
					 char save; cin >> save;
					 if (save == 'S' || save == 's') {
						 int s = sizeofitems;
						 printinfileI(I, s);
						 /*sizeofitems = openfileI(I);
						 printinfileI(I, sizeofitems);*/
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "item Deletion successfully saved" << endl;
					 }
				 }
				 else {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "Customer Not Found" << endl;
				 }
				 //delay(10);
				 //system("cls");
			 }
			 if (IM == 5) {
				 system("cls");
				 return true;
			 }
			 goto Itemmenu;
			 return false;
	};
	bool CustomerMenu() {
		static int silvercount = 1; static int goldcount = 1; static int platinumcount = 1;
		system("cls");
	customermenu:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46); 
		cout << "Customer Menu" << endl << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "1 - Add new Customer" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "2 - Update Customer details" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "3 - Find Customer" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "4 - Remove Existing Customer" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout<<"5 - Back to Main Menu" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				 size = openfileC();
				 int c; cin >> c;
				 system("cls");
				 if (c == 1) {
					 system("cls");
					 size++; SilverCustomers** SC = new SilverCustomers *[silvercount];
					 GoldCustomers** GC = new GoldCustomers *[goldcount];
					 PlatinumCustomers** PC = new PlatinumCustomers *[platinumcount];
					 SC[silvercount] = new SilverCustomers;
					 GC[goldcount] = new GoldCustomers;
					 PC[platinumcount] = new PlatinumCustomers;
					 Customer** C2; C2 = new Customer *[size];
					 for (int j = 0; j < size; j++) { C2[j] = new Customer; }
					 if (size > 0) {
						 for (int i = 0; i < size - 1; i++) { C2[i] = C[i]; }
					 }
					 else { size = 0; }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch[20];  cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
					 cin.getline(ch, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 char ch2[20];  cout << "Name : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch2, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch3[20];  cout << "Address : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch3, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 char ch4[20];  cout << "Phone Number : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch4, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch5[20];  cout << "Email : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch5, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 int type; cout << "Type : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin >> type;
					 if (type == 1) {
						 SC[silvercount]->Silverinput(ch, ch2, ch3, ch5, ch4, type, 0);
						 C2[size - 1] = SC[silvercount];
						 SC[silvercount] = nullptr;
						 silvercount++;
					 }
					 if (type == 2) {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 int discount; cout << "Discount(Max=3%) : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin >> discount;
						 GC[goldcount]->Goldinput(ch, ch2, ch3, ch5, ch4, type, 0, discount);
						 C2[size - 1] = GC[goldcount];
						 GC[goldcount] = nullptr;
						 goldcount++;
					 }
					 if (type == 3) {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79); 
						 int discount; cout << "Discount(Max=5%) : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin >> discount;
						 PC[platinumcount]->Platinuminput(ch, ch2, ch3, ch5, ch4, type, 0, discount);
						 C2[size - 1] = PC[platinumcount]; PC[platinumcount] = nullptr;
						 platinumcount++;
					 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "If u Want to Save this changes and add it in list press S : ";
					 char save; cin >> save;
					 if (save == 'S' || save == 's') {
						 printinfileC(C2, size);
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "Customer Information successfully saved" << endl;
					 }
				 }
				 if (c == 2) {
					 char cnic[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar(); cin.getline(cnic, 20);
					 int i = foundcustomer(C, cnic, size);
					 if (i != -1) {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 cout << "If You Want To Change Any Detail then Change it OR Leave Blank" << endl;
						char ch[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);  cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
						 cin.getline(ch, 100);
						 if (ch[0] != '\0') {
							 C[i]->setCNIC(ch);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 char ch2[20];  cout << "Name : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						 cin.getline(ch2, 100);
						 if (ch2[0] != '\0') {
							 C[i]->setname(ch2);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 char ch3[20];  cout << "Address : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						 cin.getline(ch3, 100);
						 if (ch3[0] != '\0') {
							 C[i]->setAddress(ch3);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 char ch4[20];  cout << "Phone Number : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						 cin.getline(ch4, 100);
						 if (ch4[0] != '\0') {
							 C[i]->setPhonenumber(ch4);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 char ch5[20];  cout << "Email : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						 cin.getline(ch5, 100);
						 if (ch5[0] != '\0') {
							 C[i]->setEmail(ch5);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 cout << "Type : "; char c[2]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin.getline(c, 2);
						 if (c[0] != '\0') {
							 C[i]->setType(c[0] - 48);
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "If u Want to Save this changes and add it in list press S : ";
						 char save; cin >> save;
						 if (save == 'S' || save == 's') {
							 printinfileC(C, size);
							 size = openfileC();
							 printinfileC(C, size);
							 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
							 cout << "Customer Information successfully saved" << endl;
						 }
					 }
					 else {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "Customer Not Found" << endl;
					 }
				 }
				 if (c == 3) {
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "Please specify at least one of the following to find the customer. Leave all fields blank to return toCustomers Menu :" << endl;
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 char ch[20];  cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar();
					 cin.getline(ch, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch2[20];  cout << "Name : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch2, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 char ch4[20];  cout << "Phone Number : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch4, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 char ch5[20];  cout << "Email : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					 cin.getline(ch5, 100); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
					 cout << "Type : "; char c[2]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); cin.getline(c, 2);
					 int l = findcustomerthoughall(C, size, ch, ch2, ch5, ch4, c);
					 if (l != -1) {
						 C[l]->print();
					 }
					 else {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
						 cout << "Customer Not Found" << endl;
					 }
				 }
				 if (c == 4) {
					 char cnic[20]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					 cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); getchar(); cin.getline(cnic, 20);
					 int i = foundcustomer(C, cnic, size);
					 if (i != -1) {
						 C[i]->deletecustomer();
						 C[i] = nullptr; size--;
						 for (i; i < size; i++) {
							 C[i] = C[i + 1];
						 }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 cout << "If you Want to Save this changes and add it in list press S : ";
						 char save; cin >> save;
						 if (save == 'S' || save == 's') {
							 printinfileC(C, size);
							 size = openfileC();
							 printinfileC(C, size);
							 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
							 cout << "Customer Deletion successfully saved" << endl;
						 }
					 }
					 else {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						 cout << "Customer Not Found" << endl;
					 }
				 }
				 if (c == 5) {
					 system("cls");
					 return true;
				 }
				 goto customermenu;
				 return false;
	}
	bool exceedlimit(char *date, int salesID) {
		return false;
	}
	bool SalesLimit(char *ch) {
		Helper H; char *ch2; Customer *C2; int ch3; int limit;
		for (int i = 0; i < sizeofSale; i++) {
			C2 = S[i]->getcustomer();
			ch2=S[i]->getdate();
			ch3 = C2->getamountpayable();
			limit = C2->getSalesLimit();
			if (H.mystrcmp(ch2, ch)) {
			
			}
		}
	
	}
	bool MakeNewSale() {
		Helper H;
		system("cls"); static double d = 0; int limitofC = 0; static int start = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		cout << "New Sale" << endl << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "Sales ID : "; int x; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  cin >> x; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "Sales Date : "; char *ch; ch = getlatestdate(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  cout << ch << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "CNIC : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  char ch2[20];
		getchar();
		cin.getline(ch2, 20);
		int II = foundcustomer(C, ch2,size);
		if (II != -1) {
			limitofC = C[II]->getSalesLimit();
			system("cls");
			AddnewSale(S, sizeofSale, C, size, x, ch, ch2);
			system("cls");  start = sizeofSalelineitem;
		ss1:cout << endl << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << endl << endl << endl << "------------------------------------------WELCOME TO THE STORE--------------------------------------" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
			cout << "\t\t\t      Enter the Code of Any Item to Purchase it      \t\t\t\t" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "\t\tItem_SKU" << "\t" << "Description" << "\t\t" << "Price" << "\t\t" << "Quantity\t\t\t\t\t" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			for (int i = 0; i < sizeofitems; i++) {
				I[i]->print();
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "                                                <<your Order>>\t\t\t\t\t\t" << endl;
			char c[10][100]; double cc = 0; cout << "Total  : "; cout << d << endl;
		SKU:
			sizeofSalelineitem = openfileSLI(SLI, S, I, sizeofSale, sizeofitems);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "Enter Item_SKU : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cin >> c[sizeofSalelineitem]; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			int index = foundItem(I, c[sizeofSalelineitem], sizeofitems); int Q = 0; int QQuan = 0;
			if (index != -1) {
				QQuan = I[index]->getAvailableQuanntity();
			}
			if (QQuan == 0 && index != -1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout << "SORRY!!!!!Item Unavailable" << endl;
			}
			if (index != -1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "Description : "; char* ch; ch = I[index]->getDescription(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << ch << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout << "Price : ";  cc = I[index]->getPrice(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << cc << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "Quantity : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cin >> Q;
				if (QQuan - Q < 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
					cout << "Sorry!!!This item short!!!if You buy then only " << QQuan << " Available" << endl;
				}
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout << "Invalid Item_SKU" << endl;
				goto ss1;
			}
			if (index != -1 || (QQuan - Q) < 0) {
				int QQ; QQ = I[index]->getAvailableQuanntity(); I[index]->setAvailableQuanntity(QQ - Q);
				printinfileI(I, sizeofitems);
				//sizeofitems = openfileI(I);
				int before; before = d;
				d = d + (Q * cc); if (d > limitofC) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					cout << "Sorry!!!Your Sales Limit Over!!!!! Now Press 2 to End Sale now " << endl;
					d = before;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "Total  : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << d << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "Press 1 to Enter New Item" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "Press 2 to End Sale" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "Press 3 to Remove an existing Item from the current sale" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout<<"Press 4 to Cancel Sale" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				//Addnewsaleitem(SLI, sizeofSalelineitem, c[sizeofSalelineitem], Q, x);
			int Sale; cin >> Sale;
			if (Sale == 1) {
				Addnewsaleitem(SLI, sizeofSalelineitem, c[sizeofSalelineitem], Q, x);
				system("cls");
				goto ss1;
			}
			if (Sale == 2) {
				Addnewsaleitem(SLI, sizeofSalelineitem, c[sizeofSalelineitem], Q, x);
				sizeofSalelineitem = openfileSLI(SLI, S, I, sizeofSale, sizeofitems);
				size = openfileC();
				int typeofC = 0; typeofC = C[II]->getType(); int discountreal = C[II]->getdiscount();
				if (typeofC == 2) {
					int discount; discount = d*(discountreal / 100);
					d = d - discount;
				}
				if (typeofC == 3) {
					int discount; discount = d*(discountreal / 100);
					d = d - discount;
				}
				R[sizeofReceipt] = new Receipt;
				int Orii = 0;
				sizeofSale = openfileS(S, C, size, R);
				for (int i = 0; i < sizeofSale; i++) {
					int IID = S[i]->getID();
					if (IID == x) {
						Orii = i;
					}
				}
				R[sizeofReceipt]->setReceiptNo(sizeofReceipt);
				R[sizeofReceipt]->setsale(S[Orii]);
				R[sizeofReceipt]->setDate("Generated");// R[sizeofitems]->setReceiptNo(sizeofReceipt);
				R[sizeofReceipt]->setAmount(d); sizeofReceipt++;
				printinfileR(R, sizeofReceipt);
				sizeofReceipt = openfileR(R, S, sizeofSale);
				/*for (int i = 0; i < sizeofReceipt; i++) {
				int IDD = R[i]->getReceiptNo();
				if (IDD == x) {

				}
				}*/
				printinfileR(R, sizeofReceipt);
				sizeofReceipt = openfileR(R, S, sizeofSale);
				double AA = C[II]->getamountpayable();
				C[II]->setamountpayable(d + AA);
				printinfileC(C, size); //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl;
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << "\t\tItem_SKU" << "\t" << "Description" << "\t\t" << "Quantity" << "\t\t" << "Amount" << endl;
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				for (int i = start; i < sizeofSalelineitem; i++) {
					Item *Ifake = SLI[i]->getitem(); cout << "\t\t"; cout << Ifake->getItem_SKU(); cout << "\t\t";  Ifake->printDescription(); cout << "\t\t\t"; int Quant = SLI[i]->getquantity(); cout << Quant << "\t\t\t";  int p = Ifake->getPrice(); cout << p*Quant << endl;
				}
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl;
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout << "\t\t\t\t\t\t\t\t\t\tTotal Sales  :   RS. "; /*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);*/ cout << d << endl;// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				/*char menu;*///SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << endl; cout << endl << "\t\t\t\t\Enter M to return to Main Menu" << endl;
				/* cin >> menu;
				if (menu = 'M') {
				goto mainmenu;
				}*/
			}
			if (Sale == 3) {
				sizeofSalelineitem = openfileSLI(SLI, S, I, sizeofSale, sizeofitems); //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl; //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << "\t\tItem_SKU" << "\t" << "Description" << "\t\t" << "Quantity" << "\t\t" << "Amount" << endl; //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl;
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				for (int i = start; i < sizeofSalelineitem; i++) {
					Item *Ifake = SLI[i]->getitem(); cout << "\t\t"; cout << Ifake->getItem_SKU(); cout << "\t\t";  Ifake->printDescription(); cout << "\t\t\t"; int Quant = SLI[i]->getquantity(); cout << Quant << "\t\t\t";  int p = Ifake->getPrice(); cout << p*Quant << endl;
				}//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				cout << "|------------------------------------------------------------------------------------------------------------------|" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				char *ch; ch = new char[6]; cout << "Item_SKU : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.getline(ch, 6); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
				char *ch2; ch2 = new char[30]; cout << "Description : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.getline(ch2, 30);
				int indexx = findSalelineitem(SLI, start, sizeofSalelineitem, ch, ch2);
				if (index != -1) {
					SLI[indexx]->deletesaleslineitem();
					SLI[indexx] = nullptr;
					for (int i = indexx; i < sizeofSalelineitem; i++) {
						SLI[i] = SLI[i + 1];
					}
					SLI[sizeofSalelineitem - 1] = nullptr;
					sizeofSalelineitem--; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					cout << "If u Want to Save this changes and add it in list press S : ";
					char save; cin >> save;
					if (save == 'S' || save == 's') {
						printinfileSLI(SLI, sizeofSalelineitem);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
						cout << "Item Information successfully saved" << endl;
					}
					else {
						goto SKU;
					}

				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
					cout << "!!!!Item No Found!!!!" << endl;
					goto SKU;
				}
			}
			if (Sale == 4) {
				int lll = sizeofSalelineitem;
				for (int i = start; i < sizeofSalelineitem; i++) {
					SLI[i] = nullptr;
					lll--;
				}
				sizeofSalelineitem = lll;
				for (int i = 0; i < sizeofSale; i++) {
					int I = S[i]->getID();
					if (I == x) {
						S[i]->setstatus("Canceled");
					}
				}
				printinfileS(S, sizeofSale);
				sizeofSale = openfileS(S, C, size, R);
			}
		}
		else {
			return true;
		}
		return false;
	};
	bool MakePayment() {
      system("cls");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
	  cout << "Make Payment" << endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
	int *ID = new int; int *O = new int; *O = -1; int *ID2 = new int; cout << "Sales ID : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cin >> *ID;
	for (int i = 0; i < sizeofSale; i++) {
		*ID2 = S[i]->getID();
		if (*ID == *ID2) {
			*O = i;
		}
	}
	if (*O != -1) {
		Sales *s; int *oo = new int;
		for (int i = 0; i < sizeofReceipt; i++) {
			s = R[i]->getsale();
			if (*ID == s->getID()) {
				*oo = i;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\tCusomer Name\t\t"; cout << "Total Sales Amount\t\t"; cout << "Amount Paid\t\t"; cout << "Remaining Amount\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		R[*oo]->setReceiptNo(sizeofSalelineitem);
		printinfileR(R, sizeofReceipt);
		Customer *CC = S[*O]->getcustomer(); char *ch = CC->getCNIC();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t"; CC->printname(); double TSA = R[*O]->getAmount();
		cout << "\t\t\t" << TSA << "\t\t\t"; double A = CC->getamountpayable();
		cout << TSA - A << "\t\t\t";
		cout << A << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		int sizeofsale2 = sizeofSale;
		if (A == 0 || A<0) {
			char *ch = getlatestdate();
			R[*oo]->setDate(ch);
		}
		else {
			R[*oo]->setDate("Amount Left");
		}
		if (A != 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "\t\t\t\tAmount You Want to Pay Now : "; double II; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cin >> II; double change = 0; double DD = A - II;
			if (DD < 0) { change = change - DD; }
			if (DD < 0) {
				DD = 0;
			}
			CC->setamountpayable(DD);
			int index = findcustomerthoughall(C, size, ch, "\0", "\0", "\0", "\0");
			C[index]->setamountpayable(DD);
			printinfileC(C, size); //int sizeofsale2 = sizeofSale;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
			cout << "\t\t\tThanks For Amount !!!!!Your Remaining Amount Is : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << C[index]->getamountpayable() << endl;
			if (change > 0) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79); cout << "\t\t\tYOur Change Is : "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << change << endl; }
			if ((DD) == 0) {
				S[*O]->setstatus("Completed");
				printinfileS(S, sizeofSale);
			}
			if ((DD) == 0) {
				char *ch2 = getlatestdate();
				R[*oo]->setDate(ch2);
			}
			else {
				R[*oo]->setDate("Amount Left");
			}
		}

		else {
			S[*O]->setstatus("Completed");
			printinfileS(S, sizeofSale);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			cout << "\t\t\t\tYour Whole fees is charged!!!!NO charges Left!!!!Thanks for coming" << endl;
		}
		printinfileC(C, size);
		size = openfileC();
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
		cout << "Sorry No Such Sales ID Avaialble!!!!!Invalid Sales ID" << endl;
	}
	printinfileR(R, sizeofReceipt);
	return true;
	};



	/*Input in All the Pointers Means  
	i)Sales Pointer 
	ii)Customeer Pointer
	iii)Item Pointer
	iV)Sales Line Item Pointer
	v) Receipt Pointer
	*/
	void InputFromFileInAllPointers() {
		size = openfileC();
		printinfileC(C, size);
		sizeofitems = openfileI(I);
		printinfileI(I, sizeofitems);
		sizeofSale = openfileS(S, C, size, R);
		printinfileS(S, sizeofSale);
		sizeofSalelineitem = openfileSLI(SLI, S, I, sizeofSale, sizeofitems);
		printinfileSLI(SLI, sizeofSalelineitem);
		sizeofReceipt = openfileR(R, S, sizeofReceipt);
		printinfileR(R, sizeofReceipt);
	}


	/*Finding Functions*/
	int  findSalelineitem(SalesLineItem **SLI, int start, int sizeofSalelineitem, char *SKU, char*Name) {
		Helper H;
		for (int i = start; i < sizeofSalelineitem; i++) {
			Item *Ifake = SLI[i]->getitem();
			char *I = Ifake->getItem_SKU();
			if (H.mystrcmp(I, SKU)) {
				return i;
			}
		}
		for (int i = start; i < sizeofSalelineitem; i++) {
			Item *Ifake = SLI[i]->getitem();
			char *name = Ifake->getDescription();
			if (H.mystrcmp(name, Name)) {
				return i;
			}
		}
		return -1;
	}
	int foundcustomer(Customer** CC, char ch[20], int size) {
		Helper H; char* ch2;
		for (int i = 0; i < size; i++) {
			ch2 = C[i]->getCNIC();
			if (H.mystrcmp(ch2, ch)) {
				return i;
			}
			ch2 = nullptr;
		}
		return -1;
	}
	int foundItem(Item** I, char ch[20], int size) {
		Helper H; char* ch2;
		for (int i = 0; i < size; i++) {
			ch2 = I[i]->getItem_SKU();
			//H.mystrcpy(ch2,C[i]->getCNIC);
			if (H.mystrcmp(ch2, ch)) {
				return i;
			}
		}
		return -1;
	}
	int findcustomerthoughall(Customer** C, int size, char* cnic, char* name, char* email, char* phone, char* type) {
		Helper H;
		if (cnic[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getCNIC();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, cnic)) {
					return i;
				}
			}
		}
		if (name[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getname();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, name)) {
					return i;
				}
			}
		}if (email[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getEmail();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, email)) {
					return i;
				}
			}
		}
		if (phone[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getPhonenumber();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, phone)) {
					return i;
				}
			}
		}
		if (type[0] != '\0') {
			int t = type[0]; int m = 0;
			for (int i = 0; i < size; i++) {
				m = C[i]->getType();
				if (m == i) {
					return i;
				}
			}
		}
		return -1;
	}
	int finditemthoughall(Item** C, int size, char* SKu, char* description, double price, int Quantity, char* date) {
		Helper H; size = openfileI(C);
		if (SKu[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getItem_SKU();
				if (H.mystrcmp(ch2, SKu)) {
					return i;
				}
			}
		}
		if (description[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getDescription();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, description)) {
					return i;
				}
			}
		}if (price != 0) {
			for (int i = 0; i < size; i++) {
				double ch2 = C[i]->getPrice();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (price == ch2) {
					return i;
				}
			}
		}
		if (Quantity != 0) {
			for (int i = 0; i < size; i++) {
				int ch2 = C[i]->getAvailableQuanntity();
				if (Quantity == ch2) {
					return i;
				}
			}
		}

		if (date[0] != '\0') {
			char* ch2;
			for (int i = 0; i < size; i++) {
				ch2 = C[i]->getDate();
				//H.mystrcpy(ch2,C[i]->getCNIC);
				if (H.mystrcmp(ch2, date)) {
					return i;
				}
			}
		}
		return -1;
	}
	
	/*All Functions of Filing*/
	int openfileI(Item**& I);
	void printinfileI(Item**I, int size);
	void deleteinfileI(Item**I, int size);
	int openfileC();
	void printinfileC(Customer** C, int size);
	int openfileS(Sales**& S, Customer** C, int size, Receipt** R);
	void printinfileS(Sales** S, int size);
	int openfileSLI(SalesLineItem **&R, Sales** S, Item**I, int sizesale, int sizeitem);
	void printinfileSLI(SalesLineItem** R, int size);
	int openfileR(Receipt **&R, Sales** S, int size);
	void printinfileR(Receipt** R, int size);
	
	/*General Functions needed*/
	void AddnewSale(Sales **S, int &size, Customer **CC, int size2, int IDDD, char * DDDate, char* CNICCC) {
		Sales **S2;
		S2 = new Sales*[size + 1]; for (int i = 0; i < size + 1; i++) { S2[i] = new Sales; }

		size2 = openfileC(); Helper H;
		int index = foundcustomer(CC, CNICCC, size2); char *ch; ch = CC[index]->getCNIC(); char *ch2 = new char[strlen(ch) + 1]; H.mystrcpy(ch2, ch);
		CC[index]->setCNIC(ch2);
		S2[size]->setcustomer(CC[index]);
		S2[size]->setdate(DDDate);
		S2[size]->setID(IDDD);
		S2[size]->setstatus("Pending"); Receipt **R; R = nullptr;
		size = openfileS(S, CC, size2, R);
		for (int i = 0; i < size; i++) {
			S2[i] = S[i];
		}
		size++;
		printinfileS(S2, size);
	}
	void Addnewsaleitem(SalesLineItem **SLI, int &sizeofSalelineitem, char *d, int Q, int x) {
		SalesLineItem **SS;
		SS = new SalesLineItem*[sizeofSalelineitem + 1];
		/*Customer**C = nullptr; int Size2 = 0;
		Size2 = openfileC();*/
		Receipt **R = nullptr; Item **I = nullptr; int sizeofitem = openfileI(I);
		Sales**sales = nullptr; int sizeofsale = 0;  sizeofsale = openfileS(sales, C, size, R);
		sizeofSalelineitem = openfileSLI(SLI, sales, I, sizeofsale, sizeofitem);

		for (int i = 0; i < sizeofSalelineitem + 1; i++) {
			SS[i] = new SalesLineItem;
		}
		SS[sizeofSalelineitem] = new SalesLineItem;
		SS[sizeofSalelineitem]->setquantity(Q);
		SS[sizeofSalelineitem]->setline(sizeofSalelineitem + 1); sizeofitem = openfileI(I);
		sizeofsale = openfileS(sales, C, size, R);
		Item *ch; int index = finditemthoughall(I, sizeofitem, d, "\0", 0, 0, "\0");
		ch = I[index]; SS[sizeofSalelineitem]->setitem(ch);
		size = openfileC();
		sizeofsale = openfileS(sales, C, size, R);
		Sales *S1; int original = 0;
		for (int i = 0; i < sizeofsale; i++) {
			int m = sales[i]->getID();
			if (m == x) {
				original = i;
			}
		}sizeofsale = openfileS(sales, C, size, R);
		SS[sizeofSalelineitem]->setsale(sales[original]);
		sizeofitem = openfileI(I);
		for (int i = 0; i < sizeofSalelineitem; i++) {
			SS[i] = SLI[i];
		}
		sizeofSalelineitem++;
		printinfileSLI(SS, sizeofSalelineitem);
	}
	
	/*Destructor*/
	~POS()
	{
		if (I != nullptr) {
			I = nullptr;
			delete I;
		}
		if (C != nullptr) {
			C = nullptr; delete C;
		}
		if (S != nullptr) {
			S = nullptr; delete S;
		}
		if (SLI != nullptr) {
			SLI = nullptr; delete SLI;
		}
		if (R != nullptr) {
			R = nullptr; delete R;
		}
	}
};