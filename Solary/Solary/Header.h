#pragma once
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void hello_menu();
void login();
void registration();
void forgot_pass();
void exit();
void menu();
void password_recovery();
void colculation_solary();
void info_solary();
void Staffing_table(int a);
void print_table(int business, int front, int back);
void info_calculation();
void calculation(string position,string username);
void print_solary(float clen_solary,float solary,int work_hour,int prize,string username, float hourlyRate);
void admin();
void ban_user();
void unloack();