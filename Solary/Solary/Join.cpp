#include "Header.h"
void hello_menu() {
	system("cls");
	int choice;
	cout << "\t\t             Приветствую!         " << endl;
	cout << "\t\t     --------------------------\n\n" << endl;
	cout << "\t\t***********Меню входа******************" << endl;
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t*\t[Нажмите 1]Авторизироваться   *\n";
	cout << "\t\t*\t[Нажмите 2]Зарегистрироваться *\n";
	cout << "\t\t*\t[Нажмите 3]Забыли пароль?     *\n";
	cout << "\t\t*\t[Нажмите 4]Выйти              *\n";
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t***************************************\n";
	cout << "\n\tВаш выбор: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Введите корректное значение:";
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
		cout << "Вы вели некорректное значение!" << endl;
		hello_menu();
	}
	}

}

/*
			Логин
*/

void login() {
	system("cls");
	string username, password;
	string line;
	bool success = false, admin_success = false, not_ban = true;
	cout << "\n\n\t\t            Меню заполнения         " << endl;
	cout << "\t\t        -----------------------\n" << endl;
	cout << "\t\t\t Если хотите вернуться" << endl;
	cout << "\t\t\t назад напишите back" << endl;
	cout << "\n\t\t\tВведите имя пользователя: ";
	cin >> username;
	if (username == "back") {
		hello_menu();
	}
	cout << "\t\t\tВведите пароль: ";
	cin >> password;
	if (username == "back") {
		hello_menu();
	}
	/*if (username == "back" || password =="back") {
		hello_menu();
	}*/
	ifstream file_login("data.txt"), check_admin("adminlist.txt");
	if (!file_login.is_open() && !check_admin.is_open()) {
		cout << "Ошибка в данных" << endl;
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
		cout << "Ошибка!" << endl;
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
			cout << "Вход в режим администратора выполнен успешно!\n" << "Подождите..." << endl;
			ofstream file_who_join("online.txt");
			file_who_join << username;
			file_who_join.close();
			Sleep(2000);
			system("cls");
			admin();
		}
		else {
			system("cls");
			cout << "Вход выполнен успешно!\n" << "Подождите..." << endl;
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
			cout << "Ваш аккаунт заблокирован" << endl;
			Sleep(3000);
			hello_menu();
		}
		else {
			cout << "Ошибка входа: неправильное имя пользователя или пароль." << endl;
			cout << "Попробуйте еще раз" << endl;
			Sleep(2000);
			login();
		}
	}
}


/*
			Забыли пароль
*/

void forgot_pass() {
	system("cls");
	int choice;
	cout << "\n\n\t\t            Меню востоновления пароля         " << endl;
	cout << "\t\t        ---------------------------------\n" << endl;
	cout << "\t\t\tЗабыли?! Сейчас мы вам поможем" << endl;
	cout << "\t\t\t[Нажмите 1]Востоновить пароль\n" << "\t\t\t[Нажмите 2]Меню" << endl;
	cout << "\t\t\tВаш выбор:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Введите корректное значение:";
	}
	switch (choice) {
	case 1: {
		password_recovery();
		break;
	}
	case 2: {
		system("cls");
		cout << "Подождите..." << endl;
		Sleep(2000);
		system("cls");
		hello_menu();
		break;
	}
	default: {
		cout << "Вы вели некорректное значение!" << endl;
		forgot_pass();
	}
	}
}
void password_recovery() {
	system("cls");
	string search_username, username, password;
	bool success = false;
	cout << "\n\n\t\t            Востоновления пароля         " << endl;
	cout << "\t\t        ----------------------------\n" << endl;
	cout << "\t\t\tВведите имя пользователя: ";
	cin >> search_username;
	ifstream file_pass("data.txt");
	while (file_pass >> username >> password) {
		if (username == search_username) {
			success = true;
			break;
		}
	}
	if (success) {
		cout << "\t\t\tВаш пароль:" << password << endl;
	}
	else {
		cout << "\t\t\tПользователся не зарегестирован" << endl;
	}
	file_pass.close();
	system("pause");
	system("cls");
	hello_menu();
}
/*
			Регистрация
*/

void registration() {
	int choice;
	string reg_name, reg_pass, reg_position, check_username, check_password;
	system("cls");
	cout << "\t\t           Меню заполнения         " << endl;
	cout << "\t\t        ---------------------\n\n" << endl;
	cout << "\t\t\tЕсли хотите вернуться назад напишите back\n" << "\t\t\tВведите данные для регистрации\n" << "\t\t\tЛогин:";
	cin >> reg_name;
	cout << "\t\t\tПароль:";
	cin >> reg_pass;
	if (reg_name == "back" || reg_pass == "back") {
		hello_menu();
	}
	ifstream check("data.txt");
	while (check >> check_username >> check_password) {
		if (reg_name == check_username) {
			cout << "Данный пользователь уже есть в системе" << endl;
			Sleep(2000);
			registration();
		}
	}
	check.close();
	cout << "Ваша должность?\n" << "[Нажмите 1]Front-end\n" << "[Нажмите 2]Back-end\n" << "[Нажмите 3]Бизнесс-аналитик" << endl;
	cout << "Ваш выбор:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!" << endl;
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
		cout << "Ошибка! Введите корректное значение:";
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
		cout << "Ошибка в данных" << endl;
	}
	else {
		file_registration << reg_name << ' ' << reg_pass << endl;
		system("cls");
		cout << "Регистрация успешна\n" << "Подождите..." << endl;
	}
	file_registration.close();
	Sleep(2000);
	system("cls");
	hello_menu();
}

/*
		Завершение проги
*/

void exit() {
	int timer;
	system("cls");
	for (timer = 5; timer > 0; timer--) {
		cout << "\n\n\n\t\t\tПрограмма завершит работу через " << timer << endl;
		Sleep(1000);
		system("cls");
	}
	exit(0);
}
