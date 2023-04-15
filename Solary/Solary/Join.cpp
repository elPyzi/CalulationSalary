#include "Header.h"
void hello_menu() {
	system("chcp 1251");
	system("cls");
	int choice;
	cout << "\t\t             Ïðèâåòñòâóþ!         " << endl;
	cout << "\t\t     --------------------------\n\n" << endl;
	cout << "\t\t***********Ìåíþ âõîäà******************" << endl;
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t*\t[Íàæìèòå 1]Àâòîðèçèðîâàòüñÿ   *\n";
	cout << "\t\t*\t[Íàæìèòå 2]Çàðåãèñòðèðîâàòüñÿ *\n";
	cout << "\t\t*\t[Íàæìèòå 3]Çàáûëè ïàðîëü?     *\n";
	cout << "\t\t*\t[Íàæìèòå 4]Âûéòè              *\n";
	cout << "\t\t*\t\t\t\t      *\n";
	cout << "\t\t***************************************\n";
	cout << "\n\tÂàø âûáîð: ";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Îøèáêà! Ââåäèòå êîððåêòíîå çíà÷åíèå:";
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
		cout << "Âû âåëè íåêîððåêòíîå çíà÷åíèå!" << endl;
		hello_menu();
	}
	}

}

/*
			Ëîãèí
*/

void login() {
	system("cls");
	string username, password;
	string line;
	bool success = false, admin_success = false, not_ban = true;
	cout << "\n\n\t\t            Ìåíþ çàïîëíåíèÿ         " << endl;
	cout << "\t\t        -----------------------\n" << endl;
	cout << "\t\t\t Åñëè õîòèòå âåðíóòüñÿ" << endl;
	cout << "\t\t\t íàçàä íàïèøèòå back" << endl;
	cout << "\n\t\t\tÂâåäèòå èìÿ ïîëüçîâàòåëÿ: ";
	cin >> username;
	if (username == "back") {
		hello_menu();
	}
	cout << "\t\t\tÂâåäèòå ïàðîëü: ";
	cin >> password;
	if (username == "back") {
		hello_menu();
	}
	/*if (username == "back" || password =="back") {
		hello_menu();
	}*/
	ifstream file_login("data.txt"), check_admin("adminlist.txt");
	if (!file_login.is_open() && !check_admin.is_open()) {
		cout << "Îøèáêà â äàííûõ" << endl;
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
		cout << "Îøèáêà!" << endl;
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
			cout << "Âõîä â ðåæèì àäìèíèñòðàòîðà âûïîëíåí óñïåøíî!\n" << "Ïîäîæäèòå..." << endl;
			ofstream file_who_join("online.txt");
			file_who_join << username;
			file_who_join.close();
			Sleep(2000);
			system("cls");
			admin();
		}
		else {
			system("cls");
			cout << "Âõîä âûïîëíåí óñïåøíî!\n" << "Ïîäîæäèòå..." << endl;
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
			cout << "Âàø àêêàóíò çàáëîêèðîâàí" << endl;
			Sleep(3000);
			hello_menu();
		}
		else {
			cout << "Îøèáêà âõîäà: íåïðàâèëüíîå èìÿ ïîëüçîâàòåëÿ èëè ïàðîëü." << endl;
			cout << "Ïîïðîáóéòå åùå ðàç" << endl;
			Sleep(2000);
			login();
		}
	}
}


/*
			Çàáûëè ïàðîëü
*/

void forgot_pass() {
	system("cls");
	int choice;
	cout << "\n\n\t\t            Ìåíþ âîñòîíîâëåíèÿ ïàðîëÿ         " << endl;
	cout << "\t\t        ---------------------------------\n" << endl;
	cout << "\t\t\tÇàáûëè?! Ñåé÷àñ ìû âàì ïîìîæåì" << endl;
	cout << "\t\t\t[Íàæìèòå 1]Âîñòîíîâèòü ïàðîëü\n" << "\t\t\t[Íàæìèòå 2]Ìåíþ" << endl;
	cout << "\t\t\tÂàø âûáîð:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Îøèáêà! Ââåäèòå êîððåêòíîå çíà÷åíèå:";
	}
	switch (choice) {
	case 1: {
		password_recovery();
		break;
	}
	case 2: {
		system("cls");
		cout << "Ïîäîæäèòå..." << endl;
		Sleep(2000);
		system("cls");
		hello_menu();
		break;
	}
	default: {
		cout << "Âû âåëè íåêîððåêòíîå çíà÷åíèå!" << endl;
		forgot_pass();
	}
	}
}
void password_recovery() {
	system("cls");
	string search_username, username, password;
	bool success = false;
	cout << "\n\n\t\t            Âîñòîíîâëåíèÿ ïàðîëÿ         " << endl;
	cout << "\t\t        ----------------------------\n" << endl;
	cout << "\t\t\tÂâåäèòå èìÿ ïîëüçîâàòåëÿ: ";
	cin >> search_username;
	ifstream file_pass("data.txt");
	while (file_pass >> username >> password) {
		if (username == search_username) {
			success = true;
			break;
		}
	}
	if (success) {
		cout << "\t\t\tÂàø ïàðîëü:" << password << endl;
	}
	else {
		cout << "\t\t\tÏîëüçîâàòåëñÿ íå çàðåãåñòèðîâàí" << endl;
	}
	file_pass.close();
	system("pause");
	system("cls");
	hello_menu();
}
/*
			Ðåãèñòðàöèÿ
*/

void registration() {
	int choice;
	string reg_name, reg_pass, reg_position, check_username, check_password;
	system("cls");
	cout << "\t\t           Ìåíþ çàïîëíåíèÿ         " << endl;
	cout << "\t\t        ---------------------\n\n" << endl;
	cout << "\t\t\tÅñëè õîòèòå âåðíóòüñÿ íàçàä íàïèøèòå back\n" << "\t\t\tÂâåäèòå äàííûå äëÿ ðåãèñòðàöèè\n" << "\t\t\tËîãèí:";
	cin >> reg_name;
	cout << "\t\t\tÏàðîëü:";
	cin >> reg_pass;
	if (reg_name == "back" || reg_pass == "back") {
		hello_menu();
	}
	ifstream check("data.txt");
	while (check >> check_username >> check_password) {
		if (reg_name == check_username) {
			cout << "Äàííûé ïîëüçîâàòåëü óæå åñòü â ñèñòåìå" << endl;
			Sleep(2000);
			registration();
		}
	}
	check.close();
	cout << "Âàøà äîëæíîñòü?\n" << "[Íàæìèòå 1]Front-end\n" << "[Íàæìèòå 2]Back-end\n" << "[Íàæìèòå 3]Áèçíåññ-àíàëèòèê" << endl;
	cout << "Âàø âûáîð:";
	while (!(cin >> choice) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Îøèáêà!" << endl;
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
		cout << "Îøèáêà! Ââåäèòå êîððåêòíîå çíà÷åíèå:";
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
		cout << "Îøèáêà â äàííûõ" << endl;
	}
	else {
		file_registration << reg_name << ' ' << reg_pass << endl;
		system("cls");
		cout << "Ðåãèñòðàöèÿ óñïåøíà\n" << "Ïîäîæäèòå..." << endl;
	}
	file_registration.close();
	Sleep(2000);
	system("cls");
	hello_menu();
}

/*
		Çàâåðøåíèå ïðîãè
*/

void exit() {
	int timer;
	system("cls");
	for (timer = 5; timer > 0; timer--) {
		cout << "\n\n\n\t\t\tÏðîãðàììà çàâåðøèò ðàáîòó ÷åðåç " << timer << endl;
		Sleep(1000);
		system("cls");
	}
	exit(0);
}
