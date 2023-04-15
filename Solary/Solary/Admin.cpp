#include "Header.h"
void admin() {
	system("cls");
	int choice;
	cout << "\t\t           ����������� �������������         " << endl;
	cout << "\t\t        -------------------------------\n\n" << endl;
	cout << "\t\t****************����********************" << endl;
	cout << "\t\t*                                      *" << endl;
	cout << "\t\t*   [������� 1] ������� �������        *" << endl;
	cout << "\t\t*               ����������             *" << endl;
	cout << "\t\t*   [������� 2] �������������          *" << endl;
	cout << "\t\t*               ������������           *" << endl;
	cout << "\t\t*   [������� 3] ��������������         *" << endl;
	cout << "\t\t*               ������������           *" << endl;
	cout << "\t\t*   [������� 4] ���������� ��          *" << endl;
	cout << "\t\t*   [������� 5] �����                  *" << endl;
	cout << "\t\t*                                      *" << endl;
	cout << "\t\t****************************************" << endl;
	cout << "\n\t\t��� �����: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������! ������� ���������� ��������:";
	}
	switch (choice) {
	case 1: {
		Staffing_table(1);
		break;
	}
	case 2: {
		ban_user();
		break;
	}
	case 3: {
		unloack();
		break;
	}
	case 4: {
		colculation_solary();
		break;
	}
	case 5: {
		hello_menu();
		break;
	}
	default: {
		cout << "�� ����� ������������ ��������!" << endl;
		admin();
	}
	}
}

void ban_user() {
	system("cls");
	string ban = "ban", ban_username, username, password;
	ifstream users("data.txt");
	ofstream ban_user_list("banlist.txt", ios::app);
	bool success = false;
	if (!users.is_open() && !ban_user_list.is_open()) {
		cout << "������ � ������" << endl;
		Sleep(2000);
		admin();
	}
	else {
		cout << "\n\n\t\t            ���� ����������         " << endl;
		cout << "\t\t        -----------------------\n" << endl;
		cout << "\t\t\t ���� ������ ���������" << endl;
		cout << "\t\t\t ����� �������� back" << endl;
		cout << "\n\t\t\t������� ��� ������������";
		cout << "\n\t\t\t�������� ������ �������������:";
		cin >> ban_username;
		if (ban_username == "back") {
			admin();
		}
		while (users >> username >> password) {
			if (username == ban_username) {
				ban_user_list << ban_username << ' ' << ban << endl;
				success = true;
				break;
			}
		}
	}
	ban_user_list.close();
	users.close();
	if (success) {
		int choice;
		cout << "\t\t\t������������ ������������!\n" << "\t\t\t������� ���������� ��� �����?\n" << "\t\t\t[������� 1]����������\n\t\t\t[������� 2]�����" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������! ������� ���������� ��������:";
		}
		switch (choice) {
		case 1: {
			ban_user();
			break;
		}
		case 2: {
			admin();
			break;
		}
		default: {
			cout << "�� ����� ������������ ��������!" << endl;
			admin();
		}
		}
	}
	else {
		cout << "�������� ������" << endl;
		Sleep(2000);
		ban_user();
	}
}
void unloack() {
	system("cls");
	string username;
	cout << "\n\n\t\t            ���� �������������         " << endl;
	cout << "\t\t        -----------------------\n" << endl;
	cout << "\t\t\t ���� ������ ���������" << endl;
	cout << "\t\t\t ����� �������� back" << endl;
	cout << "\n\t\t\t������� ��� ������������: ";
	cin >> username;
	if (username == "back") {
		admin();
	}
	username = username + " " + "ban";
	ifstream infile("banlist.txt");
	ofstream outfile("temp.txt");

	if (!infile.is_open() || !outfile.is_open()) {
		cerr << "������ �������� �����!" << endl;
	}

	string line;
	bool found = false;
	while (getline(infile, line)) {
		if (line != username) {			// ��� ���� ������(line) �� ����� ���� ����� ��������� �� �� �� ������������ � �� ����
			outfile << line << endl;     // ������������ ��� ���� ��� �� � �� ����� ���� �� ���� ������� �� �� ����� ���������
		}								 //���� ������� ���� �� ��� ���� ��� �� ������
		else {
			found = true;
			break;
		}
	}

	infile.close();
	outfile.close();

	if (found) { // ���� ������ ������ ���� ������� ��������������� ��������� ���� � ��������
		remove("banlist.txt");
		rename("temp.txt", "banlist.txt");
		int choice;
		cout << "\t\t\t������������ �������������!\n" << "\t\t\t������� ���������� ��� �����?\n" << "\t\t\t[������� 1]����������\n\t\t\t[������� 2]�����" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������! ������� ���������� ��������:";
		}
		switch (choice) {
		case 1: {
			unloack();
			break;
		}
		case 2: {
			admin();
			break;
		}
		default: {
			cout << "�� ���� ������������ ��������!" << endl;
			admin();
		}
		}
	}
	else {
		remove("temp.txt");
		cout << "�������� ������" << endl;
		Sleep(2000);
		unloack();
	}
}
