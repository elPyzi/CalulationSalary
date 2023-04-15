#include "Header.h"
void admin() {
	system("cls");
	int choice;
	cout << "\t\t           Приветствую Администратор         " << endl;
	cout << "\t\t        -------------------------------\n\n" << endl;
	cout << "\t\t****************Меню********************" << endl;
	cout << "\t\t*                                      *" << endl;
	cout << "\t\t*   [Нажмите 1] Вывести штатное        *" << endl;
	cout << "\t\t*               расписание             *" << endl;
	cout << "\t\t*   [Нажмите 2] Заблокировать          *" << endl;
	cout << "\t\t*               пользователя           *" << endl;
	cout << "\t\t*   [Нажмите 3] Разблокировать         *" << endl;
	cout << "\t\t*               пользователя           *" << endl;
	cout << "\t\t*   [Нажмите 4] Рассчитать зп          *" << endl;
	cout << "\t\t*   [Нажмите 5] Выйти                  *" << endl;
	cout << "\t\t*                                      *" << endl;
	cout << "\t\t****************************************" << endl;
	cout << "\n\t\tВаш выбор: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Введите корректное значение:";
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
		cout << "Вы ввели некорректное значение!" << endl;
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
		cout << "Ошибка в данных" << endl;
		Sleep(2000);
		admin();
	}
	else {
		cout << "\n\n\t\t            Меню блокировки         " << endl;
		cout << "\t\t        -----------------------\n" << endl;
		cout << "\t\t\t Если хотите вернуться" << endl;
		cout << "\t\t\t назад напишите back" << endl;
		cout << "\n\t\t\tВведите имя пользователя";
		cout << "\n\t\t\tкоторого хотите заблокировать:";
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
		cout << "\t\t\tПользователь заблокирован!\n" << "\t\t\tЖелаете продолжить или выйти?\n" << "\t\t\t[Нажмите 1]Продолжить\n\t\t\t[Нажмите 2]Выйти" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка! Введите корректное значение:";
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
			cout << "Вы ввели некорректное значение!" << endl;
			admin();
		}
		}
	}
	else {
		cout << "Проиошла ошибка" << endl;
		Sleep(2000);
		ban_user();
	}
}
void unloack() {
	system("cls");
	string username;
	cout << "\n\n\t\t            Меню разблокировки         " << endl;
	cout << "\t\t        -----------------------\n" << endl;
	cout << "\t\t\t Если хотите вернуться" << endl;
	cout << "\t\t\t назад напишите back" << endl;
	cout << "\n\t\t\tВведите имя пользователя: ";
	cin >> username;
	if (username == "back") {
		admin();
	}
	username = username + " " + "ban";
	ifstream infile("banlist.txt");
	ofstream outfile("temp.txt");

	if (!infile.is_open() || !outfile.is_open()) {
		cerr << "Ошибка открытия файла!" << endl;
	}

	string line;
	bool found = false;
	while (getline(infile, line)) {
		if (line != username) {			// Так если строка(line) не равна кого хотим разбанить то мы ее переписываем в др файл
			outfile << line << endl;     // переписываем для того что бы в др файле были те люди которых мы не хотим разбанить
		}								 //если находим чела то уст флаг что он найден
		else {
			found = true;
			break;
		}
	}

	infile.close();
	outfile.close();

	if (found) { // если нужная строка была найдена переименовываем временный файл в исходный
		remove("banlist.txt");
		rename("temp.txt", "banlist.txt");
		int choice;
		cout << "\t\t\tПользователь разблокирован!\n" << "\t\t\tЖелаете продолжить или выйти?\n" << "\t\t\t[Нажмите 1]Продолжить\n\t\t\t[Нажмите 2]Выйти" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка! Введите корректное значение:";
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
			cout << "Вы вели некорректное значение!" << endl;
			admin();
		}
		}
	}
	else {
		remove("temp.txt");
		cout << "Проиошла ошибка" << endl;
		Sleep(2000);
		unloack();
	}
}
