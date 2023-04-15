#include "Header.h"

void menu() {
	system("cls");
	int choice;
	cout << "\t\t           ����������� ������������         " << endl;
	cout << "\t\t        ------------------------------\n\n" << endl;
	cout << "\t\t*******************����*********************" << endl;
	cout << "\t\t*                                          *" << endl;
	cout << "\t\t*   [������� 1] ������ ���������� �        *" << endl;
	cout << "\t\t*               ������� ���������� �����   *" << endl;
	cout << "\t\t*   [������� 2] ���������� ����������      *" << endl;
	cout << "\t\t*               �����                      *" << endl;
	cout << "\t\t*   [������� 3] �����                      *" << endl;
	cout << "\t\t*                                          *" << endl;
	cout << "\t\t********************************************" << endl;
	cout << "\n\t\t��� �����: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������! ������� ���������� ��������:";
	}
	switch (choice) {
	case 1: {
		info_solary();
		break;
	}
	case 2: {
		colculation_solary();
		break;
	}
	case 3: {
		hello_menu();
		break;
	}
	default: {
		cout << "�� ����� ������������ ��������!" << endl;
		menu();
	}
	}
}
/*
���� � ��
*/
void info_solary() {
	int choice;
	system("cls");
	cout << "\t\t           ���������� � �������         " << endl;
	cout << "\t\t        --------------------------\n\n" << endl;
	cout << "\t\t********************����*******************" << endl;
	cout << "\t\t*                                         *" << endl;
	cout << "\t\t*     [������� 1]��� �������������        *" << endl;
	cout << "\t\t*                ���������� �����?        *" << endl;
	cout << "\t\t*     [������� 2]������� �������          *" << endl;
	cout << "\t\t*                ����������               *" << endl;
	cout << "\t\t*     [������� 3]��������� �����          *" << endl;
	cout << "\t\t*                                         *" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "��� �����:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������! ������� ���������� ��������:";
	}
	switch (choice) {
	case 1: {
		info_calculation();
		break;
	}
	case 2: {
		Staffing_table(0);
		break;
	}
	case 3: {
		menu();
		break;
	}
	default: {
		cout << "�� ����� ������������ ��������!" << endl;
		info_solary();
	}
	}
}

void info_calculation() {
	system("cls");
	cout << "********************************************************************************************************************" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*                                         ���������� � ��                                                          *" << endl;
	cout << "*                                    --------------------------                                                    *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*  �������� - ��� �������� �����, ������� �������� �������� �� ����������� ������.                                 *" << endl;
	cout << "*  ������ �������� ����� �������� �� ������ ��������, ����� ��� ������������, ���� ������, �������� ������� � �.�  *" << endl;
	cout << "*  ������ �������� ������ ���������� ����� ��������� ������ �� ���������� ������������ ����� ��� ����.             *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*  ������� ������������ �� ��������� �������:                                                                      *" << endl;
	cout << "*  ��=(�����������+������ �� ���* ���������� ������������ �����)-(����� � ����������)                              *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*                                                �����!!                                                           *" << endl;
	cout << "*                                     �� ����������� ���� ������� �����                                            *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "********************************************************************************************************************" << endl;
	system("pause");
	menu();
}



/*
����� ����
*/


/*
������� ��
*/
void colculation_solary() {
	system("cls");
	bool success = false;
	string position, username, online_person;
	ifstream file_online;
	file_online.open("online.txt");
	if (!file_online.is_open()) {
		cout << "������ � ������!" << endl;
		menu();
	}
	else {

		file_online >> online_person;
		file_online.close();
		ifstream file_post("position.txt");
		if (!file_post.is_open()) {
			cout << "������ � ������!" << endl;
			menu();
		}
		else {
			while (file_post >> username >> position) {
				if (username == online_person) {
					success = true;
					break;
				}
			}
			file_post.close();
			if (success) {
				calculation(position, online_person);
			}
			else {
				cout << "������!";
				system("pause");
				system("cls");
				menu();
			}
			system("pause");
			system("cls");
			menu();
		}
	}
}


//������ �� 
void calculation(string position, string username) {
	const float front = 26.7857, back = 28.2738, business = 24.5535, prize = 6000;
	float coefficient = 0, clean_solary = 0, solary = 0;
	int work_hour, choice;
	if (position == "Back-end") {
		coefficient = back;
	}
	if (position == "Front-end") {
		coefficient = front;
	}
	if (position == "business") {
		coefficient = business;
	}
	cout << "������� ���������� ������������� �����:";
	while (!(cin >> work_hour) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		system("cls");
		cout << "������! ������� ���������� ��������:";
		calculation(position, username);
	}
	if (work_hour < 144) {
		solary = coefficient * work_hour;
		clean_solary = coefficient * work_hour - (((coefficient * work_hour) * 12) / 100);
		print_solary(clean_solary, solary, work_hour, 0, username, coefficient);

	}
	else {
		cout << "�� �������� �����������?\n" << "[������� 1]��\n" << "[������� 2]���" << endl;
		cout << "��� �����:" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������! ������� ���������� ��������:";
		}
		switch (choice) {
		case 1: {
			solary = (coefficient * work_hour) + prize;
			clean_solary = ((coefficient * work_hour) + prize) - ((((coefficient * work_hour) + prize) * 12) / 100);
			print_solary(clean_solary, solary, work_hour, prize, username, coefficient);
			break;
		}
		case 2: {
			solary = (coefficient * work_hour) * 2;
			clean_solary = ((coefficient * work_hour) * 2) - ((((coefficient * work_hour) * 2) * 12) / 100);
			print_solary(clean_solary, solary, work_hour, 0, username, coefficient);
			break;
		}
		default: {
			cout << "�� ����� ������������ ��������!" << endl;
			calculation(position, username);
		}
		}
	}
}


//����� �����
void print_solary(float clen_solary, float solary, int work_hour, int prize, string usernmae, float hourlyRate) {
	system("cls");
	cout << "\t\t-------------------------------------------" << endl;
	cout << "\t\t�������� ��� '�����-�����'" << endl;
	cout << "\t\t�����: ��. ���������, �. 39" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << setw(30) << left << "\t\t���: " << usernmae << endl;
	cout << setw(30) << left << "\t\t��������� ������: $" << fixed << setprecision(2) << hourlyRate << endl;
	cout << setw(30) << left << "\t\t�����������: $" << fixed << setprecision(2) << prize << endl;
	cout << setw(30) << left << "\t\t������������ ����: " << work_hour << endl;
	cout << setw(30) << left << "\t\t���������� �����:" << fixed << setprecision(2) << "13%" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << setw(30) << left << "\t\t����� � �������: $" << fixed << setprecision(2) << solary << endl;
	cout << "\t\t-------------------------------------------" << endl;
}


/*
���� � �����������
*/
void Staffing_table(int a) {//����� � ����� ���������� ��� �� ������� 
	system("cls");
	int back = 0, front = 0, business = 0;//Back-end    business    Front-end
	string serach_position, position;
	ifstream file_table;
	file_table.open("position.txt");
	serach_position = "business";
	while (file_table >> position && !file_table.eof()) {
		if (position == serach_position) {
			business++;
		}
	}
	file_table.close();
	file_table.open("position.txt");
	serach_position = "Back-end";
	while (file_table >> position && !file_table.eof()) {
		if (position == serach_position) {
			front++;

		}
	}file_table.close();
	file_table.open("position.txt");
	serach_position = "Front-end";
	while (file_table >> position && !file_table.eof()) {
		if (position == serach_position) {
			front++;

		}
	}
	if (a == 1) {
		print_table(business, front, front);
		system("pause");
		admin();
	}
	else {
		print_table(business, front, front);
		system("pause");
		info_solary();
	}
	file_table.close();
}
void print_table(int business, int front, int back) {
	cout << "\t\t\t������� ����������" << endl;
	cout << "\t\t\t--------------------------" << endl;
	cout << "\t\t�� ������ � 2023-01-01 �� 2023-12-31\n\n" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "*  ������������  | ���������        | ���������� ������� ������|����� (� �����) *" << endl;
	cout << "* Developer      | Front-end        | " << setw(24) << front << " | 18.000$        *" << endl;
	cout << "* Developer      | Back-end         | " << setw(24) << back << " | 19.000$        *" << endl;
	cout << "* Developer      | ������-��������  | " << setw(24) << business << " | 16.500$        *" << endl;
	cout << "*********************************************************************************" << endl;

}

