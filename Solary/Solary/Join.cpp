#include "Header.h"
void hello_menu() {
	system("cls");
	int choice;
	cout << "\t\t             �����������!         " << endl;
	cout << "\t\t     --------------------------\n\n" << endl;
	cout << "\t\t***********���� �����******************" << endl;
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t*\t[������� 1]����������������   *\n";
	cout << "\t\t*\t[������� 2]������������������ *\n";
	cout << "\t\t*\t[������� 3]������ ������?     *\n";
	cout << "\t\t*\t[������� 4]�����              *\n";
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t***************************************\n";
	cout << "\n\t��� �����: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������! ������� ���������� ��������:";
	}
	switch (choice) {
	case 1: {
		login();
		break;
	}
	case 2: {
		registration();
		break;
	}
	case 3: {
		forgot_pass();
		break;
	}
	case 4: {
		exit();
		break;
	}
	default: {
		cout << "�� ���� ������������ ��������!" << endl;
		hello_menu();
	}
	}

}

/*
			�����
*/

void login() {
	system("cls");
	string username, password;
	string line;
	bool success = false, admin_success = false, not_ban = true;
	cout << "\n\n\t\t            ���� ����������         " << endl;
	cout << "\t\t        -----------------------\n" << endl;
	cout << "\t\t\t ���� ������ ���������" << endl;
	cout << "\t\t\t ����� �������� back" << endl;
	cout << "\n\t\t\t������� ��� ������������: ";
	cin >> username;
	if (username == "back") {
		hello_menu();
	}
	cout << "\t\t\t������� ������: ";
	cin >> password;
	if (username == "back") {
		hello_menu();
	}
	/*if (username == "back" || password =="back") {
		hello_menu();
	}*/
	ifstream file_login("data.txt"), check_admin("adminlist.txt");
	if (!file_login.is_open() && !check_admin.is_open()) {
		cout << "������ � ������" << endl;
		Sleep(2000);
		hello_menu();
	}
	else {
		while (getline(file_login, line)) {
			if (line == username + " " + password) {
				success = true;
				break;
			}
		}
		string admin_name;
		while (check_admin >> admin_name) {
			if (admin_name == username) {
				admin_success = true;
				break;
			}
		}

	}
	file_login.close(), check_admin.close();


	string ban, check_username;
	ifstream check_banlist("banlist.txt");
	if (!check_banlist.is_open()) {
		cout << "������!" << endl;
		Sleep(2000);
		hello_menu();
	}
	else {
		while (check_banlist >> check_username >> ban) {
			if (check_username == username) {
				not_ban = false;
				break;
			}
		}
	}
	check_banlist.close();
	if (success && not_ban) {
		if (admin_success) {
			system("cls");
			cout << "���� � ����� �������������� �������� �������!\n" << "���������..." << endl;
			ofstream file_who_join("online.txt");
			file_who_join << username;
			file_who_join.close();
			Sleep(2000);
			system("cls");
			admin();
		}
		else {
			system("cls");
			cout << "���� �������� �������!\n" << "���������..." << endl;
			ofstream file_who_join("online.txt");
			file_who_join << username;
			file_who_join.close();
			Sleep(2000);
			system("cls");
			menu();
		}
	}
	else {
		if (not_ban == false) {
			system("cls");
			cout << "��� ������� ������������" << endl;
			Sleep(3000);
			hello_menu();
		}
		else {
			cout << "������ �����: ������������ ��� ������������ ��� ������." << endl;
			cout << "���������� ��� ���" << endl;
			Sleep(2000);
			login();
		}
	}
}


/*
			������ ������
*/

void forgot_pass() {
	system("cls");
	int choice;
	cout << "\n\n\t\t            ���� ������������� ������         " << endl;
	cout << "\t\t        ---------------------------------\n" << endl;
	cout << "\t\t\t������?! ������ �� ��� �������" << endl;
	cout << "\t\t\t[������� 1]����������� ������\n" << "\t\t\t[������� 2]����" << endl;
	cout << "\t\t\t��� �����:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������! ������� ���������� ��������:";
	}
	switch (choice) {
	case 1: {
		password_recovery();
		break;
	}
	case 2: {
		system("cls");
		cout << "���������..." << endl;
		Sleep(2000);
		system("cls");
		hello_menu();
		break;
	}
	default: {
		cout << "�� ���� ������������ ��������!" << endl;
		forgot_pass();
	}
	}
}
void password_recovery() {
	system("cls");
	string search_username, username, password;
	bool success = false;
	cout << "\n\n\t\t            ������������� ������         " << endl;
	cout << "\t\t        ----------------------------\n" << endl;
	cout << "\t\t\t������� ��� ������������: ";
	cin >> search_username;
	ifstream file_pass("data.txt");
	while (file_pass >> username >> password) {
		if (username == search_username) {
			success = true;
			break;
		}
	}
	if (success) {
		cout << "\t\t\t��� ������:" << password << endl;
	}
	else {
		cout << "\t\t\t������������� �� ��������������" << endl;
	}
	file_pass.close();
	system("pause");
	system("cls");
	hello_menu();
}
/*
			�����������
*/

void registration() {
	int choice;
	string reg_name, reg_pass, reg_position, check_username, check_password;
	system("cls");
	cout << "\t\t           ���� ����������         " << endl;
	cout << "\t\t        ---------------------\n\n" << endl;
	cout << "\t\t\t���� ������ ��������� ����� �������� back\n" << "\t\t\t������� ������ ��� �����������\n" << "\t\t\t�����:";
	cin >> reg_name;
	cout << "\t\t\t������:";
	cin >> reg_pass;
	if (reg_name == "back" || reg_pass == "back") {
		hello_menu();
	}
	ifstream check("data.txt");
	while (check >> check_username >> check_password) {
		if (reg_name == check_username) {
			cout << "������ ������������ ��� ���� � �������" << endl;
			Sleep(2000);
			registration();
		}
	}
	check.close();
	cout << "���� ���������?\n" << "[������� 1]Front-end\n" << "[������� 2]Back-end\n" << "[������� 3]�������-��������" << endl;
	cout << "��� �����:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������!" << endl;
	}
	switch (choice) {
	case 1: {
		reg_position = "Front-end";
		break;
	}
	case 2: {
		reg_position = "Back-end";
		break;
	}
	case 3: {
		reg_position = "business";
		break;
	}
	default: {
		cout << "������! ������� ���������� ��������:";
		registration();
	}
	}
	ofstream file_position;
	file_position.open("position.txt", ofstream::app);
	file_position << reg_name << ' ' << reg_position << endl;
	file_position.close();


	ofstream file_registration;
	file_registration.open("data.txt", ofstream::app);
	if (!file_registration.is_open()) {
		cout << "������ � ������" << endl;
	}
	else {
		file_registration << reg_name << ' ' << reg_pass << endl;
		system("cls");
		cout << "����������� �������\n" << "���������..." << endl;
	}
	file_registration.close();
	Sleep(2000);
	system("cls");
	hello_menu();
}

/*
		���������� �����
*/

void exit() {
	int timer;
	system("cls");
	for (timer = 5; timer > 0; timer--) {
		cout << "\n\n\n\t\t\t��������� �������� ������ ����� " << timer << endl;
		Sleep(1000);
		system("cls");
	}
	exit(0);
}
