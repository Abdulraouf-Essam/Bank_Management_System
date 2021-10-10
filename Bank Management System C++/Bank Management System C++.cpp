#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
int index = 0;

struct ACOUNT
{
	string Name;
	int Acount_Number;
	char Tybe;
	int Password_Pass;
	long double Money;
};

void create_an_new_account(ACOUNT Client[], int N);
void Inquire_about_an_account(ACOUNT Client[], int N);
void Edit_account_information(ACOUNT Client[], int N);
void For_pull_And_deposit(ACOUNT Client[], int N);
void Balance_transfer(ACOUNT Client[], int N);
void Information_All_Acounts(ACOUNT Client[], int N);
void Delet_Acount(ACOUNT Client[], int N);

int main()
{
	int operation_number, Number_All_Acount_In_Project;
	ACOUNT Client[250];
	Number_All_Acount_In_Project = 250;
	while (true)
	{
		cout << "\n                          MAIN MENU                         \n" <<
			"                         -----------                       \n\n\n" <<
			"          01. To Create an new account, click        \" 1 \" \n\n\n" <<
			"          02. To Inquire about an account, click     \" 2 \" \n\n\n" <<
			"          03. Edit account information, click        \" 3 \" \n\n\n" <<
			"          04. For Pull and deposit , click           \" 4 \" \n\n\n" <<
			"          05. Balance transfer, click                \" 5 \" \n\n\n" <<
			"          06. To View all accounts, click            \" 6 \" \n\n\n" <<
			"          07. To Delete account, click               \" 7 \" \n\n\n" <<
			"          08. To Exit the program, click             \" 8 \" \n\n\n          ";

		cin >> operation_number;

		system("cls");

		switch (operation_number)
		{
		case 1:create_an_new_account(Client, Number_All_Acount_In_Project); index++; break;
		case 2:Inquire_about_an_account(Client, Number_All_Acount_In_Project); break;
		case 3:Edit_account_information(Client, Number_All_Acount_In_Project); break;
		case 4:For_pull_And_deposit(Client, Number_All_Acount_In_Project); break;
		case 5:Balance_transfer(Client, Number_All_Acount_In_Project); break;
		case 6:Information_All_Acounts(Client, Number_All_Acount_In_Project); break;
		case 7:Delet_Acount(Client, Number_All_Acount_In_Project); break;
		case 8:return 0; break;
		}
	}
}

void create_an_new_account(ACOUNT Client[], int N)
{
	short check = 0, test = false;

	do
	{
		system("cls");
		cout << "\n\n\n          Enter the name of the account holder...";
		cin.ignore();
		getline(cin, Client[index].Name);

		cout << "\n          Enter the account number...";
		cin >> Client[index].Acount_Number;

		while (index > 0)
		{
			for (int i = 0; i < index; i++)
			{
				if (Client[index].Acount_Number == Client[i].Acount_Number)
					test = true;
			}

			if (test)
			{
				cout << "\n          This account number already exists, \n          try again please...";
				test = false;
			}
			else
				break;

			cin >> Client[index].Acount_Number;
		}

		cout << "\n          Enter the account type ( - C - , - S - )...";
		cin >> Client[index].Tybe;

		cout << "\n          Enter the Password...";
		cin >> Client[index].Password_Pass;
		cout << "\n          Enter an amount of money...";
		cin >> Client[index].Money;

		if (Client[index].Tybe == 'S')
		{
			while (Client[index].Money <= 0 || Client[index].Money < 500)
			{
				if (Client[index].Money <= 0)
					cout << "\n          The amount of money is not correct, \n          try again please...\n";

				if (Client[index].Money < 500)
					cout << "\n          (-- Please enter 500 $ or more... --)\n          ";

				cin >> Client[index].Money;
			}
		}
		else
		{
			while (Client[index].Money <= 0 || Client[index].Money < 1000)
			{
				if (Client[index].Money <= 0)
					cout << "\n          The amount of money is not correct, \n          try again please...";

				if (Client[index].Money < 1000)
					cout << "\n          (-- Please enter 1000 $ or more... --)\n          ";

				cin >> Client[index].Money;
			}
		}

		cout << "\n\n\n               ---- Please check the information again ----\n\n\n" <<
			"              01. correct         02. incorrec, Edit again\n          ";
		cin >> check;

	} while (check != 1);
	system("cls");
	cout << "\n\n             ✲✧✧✲  Account successfully created  ✲✧✧✲\n\n\n\n";
}
void Inquire_about_an_account(ACOUNT Client[], int N)
{
	int i = 0, Amount_Of_Money = 0, index_client_in_struct = -1;
	int Number = 0, Password = 0;

	cout << "\n\n\n          Enter the account number...";
	cin >> Number;

	while (i < index)
	{
		if (Client[i].Acount_Number == Number)
		{
			index_client_in_struct = i;
			break;
		}

		if (index_client_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number;
			i = 0;
		}

		i++;
	}

	cout << "\n          Enter the Password...";
	cin >> Password;

	while (Password != Client[index_client_in_struct].Password_Pass)
	{
		cout << "\n          The password is incorrect X\n          Try again...";
		cin >> Password;
	}

	system("cls");

	cout << "\n\n                       --- Account Information ---\n\n";
	cout << "\n          the name of the account holder is : " << Client[index_client_in_struct].Name << "\n";
	cout << "\n          the account number is : " << Client[index_client_in_struct].Acount_Number << "\n";
	cout << "\n          the account Password is : " << Client[index_client_in_struct].Password_Pass << "\n\n";
	cout << "\n          The Balance = " << Client[index_client_in_struct].Money << " $\n\n";

}
void Edit_account_information(ACOUNT Client[], int N)
{
	int i = 0, Number = 0, Password = 0, process_Number, index_client_in_struct = -1;
	cout << "\n          Enter the account number...";
	cin >> Number;

	while (i < index)
	{
		if (Client[i].Acount_Number == Number)
		{
			index_client_in_struct = i;
			break;
		}

		if (index_client_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number;
			i = 0;
		}

		i++;
	}


	cout << "\n          Enter the Password...";
	cin >> Password;

	while (Password != Client[i].Password_Pass)
	{
		cout << "\n          The password is incorrect X\n          Try again...";
		cin >> Password;
	}

	system("cls");
	do
	{
		cout << "\n\n                       --- Account Information ---\n\n";
		cout << "\n          the name of the account holder is : " << Client[i].Name << "\n";
		cout << "\n          the account number is : " << Client[i].Acount_Number << "\n";
		cout << "\n          the account Password is : " << Client[i].Password_Pass << "\n";
		cout << "\n          The Balance = " << Client[i].Money << " $\n\n\n";

		cout << "\n\n                       --- Choose the process ---\n\n" <<
			"              01. Name editing\n" <<
			"              02. Edit account number\n" <<
			"              03. Edit password\n" <<
			"              00. To finish click \" 0 \" \n";

		cin >> process_Number;
		system("cls");
		switch (process_Number)
		{
		case 1:cout << "\n          Enter the new name..."; cin.ignore(); getline(cin, Client[i].Name); break;
		case 2:cout << "\n          Enter the new account number..."; cin >> Client[i].Acount_Number; break;
		case 3:cout << "\n          Enter the new password..."; cin >> Client[i].Password_Pass; break;
		}

		system("cls");

	} while (process_Number != 0);

}
void For_pull_And_deposit(ACOUNT Client[], int N)
{
	long double Amount_Of_Money = 0;
	int i = 0, Number = 0, Password = 0, index_client_in_struct = -1, number_of_pull_or_deposit = 0;

	cout << "\n          Enter the account number...";
	cin >> Number;


	while (i < index)
	{
		if (Client[i].Acount_Number == Number)
		{
			index_client_in_struct = i;
			break;
		}

		if (index_client_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number;
			i = 0;
		}

		i++;
	}


	cout << "\n          Enter the Password...";
	cin >> Password;

	while (Password != Client[i].Password_Pass)
	{
		cout << "\n          The password is incorrect X\n          Try again...";
		cin >> Password;
		system("cls");
	}
	system("cls");
	cout << "\n\n                     ---Account Information---\n\n";
	cout << "\n          the name of the account holder is : " << Client[i].Name << "\n";
	cout << "\n          the account number is : " << Client[i].Acount_Number << "\n";
	cout << "\n          the account Password is : " << Client[i].Password_Pass << "\n";
	cout << "\n          The Balance = " << Client[i].Money << "\n";


	cout << "\n          Please choose...\n\n               01. Pull     or     02. Deposit\n";
	cin >> number_of_pull_or_deposit;

	cout << "\n          Please enter the amount of money...";
	cin >> Amount_Of_Money;

	while (Amount_Of_Money <= 0 && number_of_pull_or_deposit == 1)
	{
		cout << "\n          The amount of money is not Enouph, \n          try again please...";
		cin >> Amount_Of_Money;
	}

	while (Amount_Of_Money <= 0 && number_of_pull_or_deposit == 2)
	{
		cout << "\n          The amount of money is not Correct, \n          try again please...";
		cin >> Amount_Of_Money;
	}

	system("cls");

	if (number_of_pull_or_deposit == 1)
		Client[index_client_in_struct].Money -= Amount_Of_Money;
	else
		Client[index_client_in_struct].Money += Amount_Of_Money;

	cout << "\n\n\n          Your balance is now = " << Client[index_client_in_struct].Money << " $\n\n\n";

}
void Balance_transfer(ACOUNT Client[], int N)
{
	long double Amount_Of_Money = 0, check = 1;
	int i = 0, Number_1 = 0, Number_2 = 0, Password = 0, index_client_1_in_struct = -1, index_client_2_in_struct = -1;

	cout << "\n          Enter the account number... ";
	cin >> Number_1;


	while (i < index)
	{
		if (Client[i].Acount_Number == Number_1)
		{
			index_client_1_in_struct = i;
			break;
		}

		if (index_client_1_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number_1;
			i = 0;
		}

		i++;
	}

	i = 0;

	cout << "\n          Enter the account number you want to transfer money to... ";
	cin >> Number_2;

	while (i < index)
	{
		if (Client[i].Acount_Number == Number_2)
		{
			index_client_2_in_struct = i;
			break;
		}

		if (index_client_2_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number_2;
			i = 0;
		}

		i++;
	}

	cout << "\n          Please enter the amount of money...";
	cin >> Amount_Of_Money;

	while (Amount_Of_Money <= 0 || Amount_Of_Money > Client[index_client_1_in_struct].Money)
	{
		cout << "\n          The amount of money is not Enouph, \n          01. try again       or      02. Exit";
		cin >> check;

		if (check != 1)
			break;

		cin >> Amount_Of_Money;
	}

	Client[index_client_2_in_struct].Money += Amount_Of_Money;
	Client[index_client_1_in_struct].Money -= Amount_Of_Money;

	cout << "\n          Your balance is now = " << Client[index_client_1_in_struct].Money << " $\n";
}
void Information_All_Acounts(ACOUNT Client[], int N)
{
	int Back_button_to_main_menu;
	cout << "\n                                                        ---- All accounts ----\n";
	cout << "                                                             -----------                       \n\n";
	cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n|         | The name of the account holder|           | The account number|           | Account type |           | The account Password|           | The Balance           |";
	cout << "\n|---------|-------------------------------|-----------|-------------------|-----------|--------------|-----------|---------------------|-----------|-----------------------|";
	for (int i = 0; i < index; i++)
	{
		string S1 = "", S2 = "", S3 = "";

		S1 += to_string(Client[i].Acount_Number);
		S2 += to_string(Client[i].Password_Pass);
		S3 += to_string(Client[i].Money);

		if (i < 10)
			cout << "\n|    " << i + 1 << "    | " << Client[i].Name;
		else if (i < 100)
			cout << "\n|   " << i + 1 << "    | " << Client[i].Name;
		else
			cout << "\n|   " << i + 1 << "   | " << Client[i].Name << "";

		for (int j = Client[i].Name.size(); j < 30; j++)
			cout << " ";

		cout << "|   =====>  " << "| " << S1;

		for (int j = S1.size(); j < 18; j++)
			cout << " ";

		cout << "|   =====>  " << "| " << Client[i].Tybe;

		for (int j = 1; j < 13; j++)
			cout << " ";

		cout << "|   =====>  " << "| " << S2;

		for (int j = S2.size(); j < 20; j++)
			cout << " ";

		cout << "|   =====>  " << "| " << S3;

		for (int j = S3.size(); j < 22; j++)
			cout << " ";

		cout << "|";
		cout << "\n|=========|===============================|===========|===================|===========|==============|===========|=====================|===========|=======================|";
	}


	cout << "\n\n\n\                                                      -------------------------\n";
	cout << "                                                  --- | to Close, Click \" 0 \" | ---";
	cout << "\n                                                      ------------------------- ";

	cin >> Back_button_to_main_menu;
	system("cls");

}
void Delet_Acount(ACOUNT Client[], int N)
{
	int i = 0, Number = 0, Password = 0, number_of_delet = 0, index_client_in_struct = -1;
	cout << "\n          Enter the account number...";
	cin >> Number;


	while (i < index)
	{
		if (Client[i].Acount_Number == Number)
		{
			index_client_in_struct = i;
			break;
		}

		if (index_client_in_struct == -1 && i == (index - 1))
		{
			cout << "\n          There is no account with this number, \n          try again please...";
			cin >> Number;
			i = 0;
		}

		i++;
	}


	cout << "\n          Enter the Password...";
	cin >> Password;

	while (Password != Client[i].Password_Pass)
	{
		cout << "\n          The password is incorrect X\n          Try again...";
		cin >> Password;
		system("cls");
	}
	system("cls");

	index_client_in_struct = i;

	cout << "\n\n                       --- Account Information ---\n\n";
	cout << "\n          the name of the account holder is : " << Client[i].Name << "\n";
	cout << "\n          the account number is : " << Client[i].Acount_Number << "\n";
	cout << "\n          the account Password is : " << Client[i].Password_Pass << "\n";
	cout << "\n          The Balance = " << Client[i].Money << " $\n\n\n";



	cout << "\n          01. Confirm account deletion, click \" 1 \"          or          02. for cancel, click \" 2 \" \n";

	cin >> number_of_delet;

	if (number_of_delet == 1)
	{
		Client[index_client_in_struct].Name = Client[index - 1].Name;
		Client[index_client_in_struct].Acount_Number = Client[index - 1].Acount_Number;
		Client[index_client_in_struct].Password_Pass = Client[index - 1].Acount_Number;
		Client[index_client_in_struct].Money = Client[index - 1].Acount_Number;
		system("cls");

		cout << "\n\n             ✲✧✧✲  Account successfully Deleted  ✲✧✧✲\n\n\n\n";

	}

	index--;
}