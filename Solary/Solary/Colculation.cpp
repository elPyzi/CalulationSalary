#include "Header.h"

void menu() {
	system("cls");
	int choice;
	cout << "\t\t           Приветствую Пользователь         " << endl;
	cout << "\t\t        ------------------------------\n\n" << endl;
	cout << "\t\t*******************Меню*********************" << endl;
	cout << "\t\t*                                          *" << endl;
	cout << "\t\t*   [Нажмите 1] Узнать информацию о        *" << endl;
	cout << "\t\t*               расчёте заработной платы   *" << endl;
	cout << "\t\t*   [Нажмите 2] Рассчитать заработную      *" << endl;
	cout << "\t\t*               плату                      *" << endl;
	cout << "\t\t*   [Нажмите 3] Выйти                      *" << endl;
	cout << "\t\t*                                          *" << endl;
	cout << "\t\t********************************************" << endl;
	cout << "\n\t\tВаш выбор: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Введите корректное значение:";
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
		cout << "Вы ввели некорректное значение!" << endl;
		menu();
	}
	}
}
/*
Инфа о зп
*/
void info_solary() {
	int choice;
	system("cls");
	cout << "\t\t           Информация о расчёте         " << endl;
	cout << "\t\t        --------------------------\n\n" << endl;
	cout << "\t\t********************Меню*******************" << endl;
	cout << "\t\t*                                         *" << endl;
	cout << "\t\t*     [Нажмите 1]Как расчитывается        *" << endl;
	cout << "\t\t*                заработная плата?        *" << endl;
	cout << "\t\t*     [Нажмите 2]Вывести штатное          *" << endl;
	cout << "\t\t*                расписание               *" << endl;
	cout << "\t\t*     [Нажмите 3]Вернуться назад          *" << endl;
	cout << "\t\t*                                         *" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "Ваш выбор:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Введите корректное значение:";
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
		cout << "Вы ввели некорректное значение!" << endl;
		info_solary();
	}
	}
}

void info_calculation() {
	system("cls");
	cout << "********************************************************************************************************************" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*                                         Информация о зп                                                          *" << endl;
	cout << "*                                    --------------------------                                                    *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*  Зарплата - это денежная сумма, которую работник получает за выполненную работу.                                 *" << endl;
	cout << "*  Размер зарплаты может зависеть от многих факторов, таких как квалификация, опыт работы, рыночные условия и т.д  *" << endl;
	cout << "*  Расчет зарплаты обычно происходит путем умножения ставки на количество отработанных часов или дней.             *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*  Рассчет производится по следующей формуле:                                                                      *" << endl;
	cout << "*  ЗП=(Премиальные+Ставка за час* количество отработанных часов)-(налог и отчисления)                              *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "*                                                Важно!!                                                           *" << endl;
	cout << "*                                     За премиальные тоже берется налог                                            *" << endl;
	cout << "*                                                                                                                  *" << endl;
	cout << "********************************************************************************************************************" << endl;
	system("pause");
	menu();
}



/*
конец инфы
*/


/*
Рассчет зп
*/
void colculation_solary() {
	system("cls");
	bool success = false;
	string position, username, online_person;
	ifstream file_online;
	file_online.open("online.txt");
	if (!file_online.is_open()) {
		cout << "Ошибка в данных!" << endl;
		menu();
	}
	else {

		file_online >> online_person;
		file_online.close();
		ifstream file_post("position.txt");
		if (!file_post.is_open()) {
			cout << "Ошибка в данных!" << endl;
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
				cout << "Ошибка!";
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


//Расчет зп 
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
	cout << "Введите количество проработанных часов:";
	while (!(cin >> work_hour) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		system("cls");
		cout << "Ошибка! Введите корректное значение:";
		calculation(position, username);
	}
	if (work_hour < 144) {
		solary = coefficient * work_hour;
		clean_solary = coefficient * work_hour - (((coefficient * work_hour) * 12) / 100);
		print_solary(clean_solary, solary, work_hour, 0, username, coefficient);

	}
	else {
		cout << "Вы работали добровольно?\n" << "[Нажмите 1]Да\n" << "[Нажмите 2]Нет" << endl;
		cout << "Ваш выбор:" << endl;
		while (!(cin >> choice) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка! Введите корректное значение:";
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
			cout << "Вы ввели некорректное значение!" << endl;
			calculation(position, username);
		}
		}
	}
}


//Вывод зпшки
void print_solary(float clen_solary, float solary, int work_hour, int prize, string usernmae, float hourlyRate) {
	system("cls");
	cout << "\t\t-------------------------------------------" << endl;
	cout << "\t\tКомпания ООО 'Пыжик-Чижик'" << endl;
	cout << "\t\tАдрес: ул. Платонова, д. 39" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << setw(30) << left << "\t\tИмя: " << usernmae << endl;
	cout << setw(30) << left << "\t\tПочасовая ставка: $" << fixed << setprecision(2) << hourlyRate << endl;
	cout << setw(30) << left << "\t\tПремиальные: $" << fixed << setprecision(2) << prize << endl;
	cout << setw(30) << left << "\t\tОтработанные часы: " << work_hour << endl;
	cout << setw(30) << left << "\t\tПодоходный налог:" << fixed << setprecision(2) << "13%" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	cout << setw(30) << left << "\t\tИтого к выплате: $" << fixed << setprecision(2) << solary << endl;
	cout << "\t\t-------------------------------------------" << endl;
}


/*
Инфа о сотрудниках
*/
void Staffing_table(int a) {//поиск в файле должностей что бы вывести 
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
	cout << "\t\t\tШтатное расписание" << endl;
	cout << "\t\t\t--------------------------" << endl;
	cout << "\t\tНа период с 2023-01-01 по 2023-12-31\n\n" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "*  Наименование  | Должность        | Количество штатных единиц|Оклад (в месяц) *" << endl;
	cout << "* Developer      | Front-end        | " << setw(24) << front << " | 18.000$        *" << endl;
	cout << "* Developer      | Back-end         | " << setw(24) << back << " | 19.000$        *" << endl;
	cout << "* Developer      | Бизнес-аналитик  | " << setw(24) << business << " | 16.500$        *" << endl;
	cout << "*********************************************************************************" << endl;

}

