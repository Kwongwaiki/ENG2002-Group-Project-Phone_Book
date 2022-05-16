/*
Class number: 2
Team number: 21
Assignment no.:2
Task number: 1
Kwong Wai Ki 19030979D
Lam Chin Shing 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "phoneBk.h"

using namespace std;
int familyN = 1;   //number of records (family)  //no record when they equal to 1
int friendN = 1;   //number of records (friend)
int junkN = 1;   //number of records (junk)

bool menu();     //menu for insert and check those information about the phone records
void Task1();   // function for displaying a sorted list of phone records based on the last-call date and time (latest first)
void date(string);   //change format of the string (last-call date and time)
bool password();   //check the user name and password
void data_record(string, string, string, string, int, int);   //save user input (phone records) to Phonebook.cpp
void pre_record();   //get past phone records from Phonebook.cpp
phoneBk Setting;   

int main()
{
	bool exitflag = false;
	cout << "Welcome to Phone Organizer!" << endl;
	exitflag = password();   //exit the program if password is wrong
	pre_record();   //get past phone records
	while (exitflag == false)
	{
		exitflag = menu();   //exit if chosen option 4
	}
	
	return 0;
}

void pre_record()
{
	int cnt=0;
	char rec[100];   //used to temporarily store the data got from Phonebook.cpp
	string group;   //the group that those data belong to
	string name, nickname, email_address, last_time_date;  
	int phone_num;   
	string group1 = "Family";
	string group2 = "Friend";
	string group3 = "Junk";
	ifstream fin1("Phonebook.cpp");   //open file Phonebook.cpp to get past phone records
	if (!fin1) {
		cout << "Phone book file: opening error!\n";   //check if file Phonebook.cpp gets problems
	}
	while (fin1.getline(rec, 100)) {   //get the data and classify the data
		cnt = cnt + 1;   //current position of the opened file
		switch (cnt % 6) {
			case 1: group = rec; break;
			case 2: name = rec; break;
			case 3: nickname = rec; break;
			case 4: email_address = rec; break;
			case 5: last_time_date = rec; break;
			case 0: phone_num = atoi(rec); break;
		}
		if (cnt % 6 == 0) {   //when get all data of one phone record
			if (group == group1) {   //store the data to phoneBk's private elements by groups
				Setting.Family[familyN].Set_User_info_string(name, nickname, email_address, last_time_date);
				Setting.Family[familyN].Set_User_info_int(phone_num);
				familyN = familyN + 1;
			}
			if (group == group2) {
				Setting.Friend[friendN].Set_User_info_string(name, nickname, email_address, last_time_date);
				Setting.Friend[friendN].Set_User_info_int(phone_num);
				friendN = friendN + 1;
			}
			if (group == group3) {
				Setting.Junk[junkN].Set_User_info_string(name, nickname, email_address, last_time_date);
				Setting.Junk[junkN].Set_User_info_int(phone_num);
				junkN = junkN + 1;
			}
		}
	}
	fin1.close();   //close the file Phonebook.cpp
	cout << "Phone book records can be shown in [2] now. \n";
}
void data_record(string name, string nickname, string email_address, string last_time_date, int phone_num, int choice2)
{
	string group;
	ofstream fout1("Phonebook.cpp", ios::app);  //open file Phonebook.cpp to store the user input (phone records)
	switch (choice2)
	{
	case 1: group = "Family"; break;   //save the info (groupings)
	case 2: group = "Friend"; break;
	case 3: group = "Junk"; break;
	}
	fout1 << group << "\n";
	fout1 << name << "\n";
	fout1 << nickname << "\n";
	fout1 << email_address << "\n";
	fout1 << last_time_date << "\n";
	fout1 << phone_num << "\n";
	fout1.close();   //close the file Phonebook.cpp
}

bool menu()
{
	char choice;   //option (the parts of menu)
	string name, nickname, email_address, last_time_date;   //to store the data of each phone record
	int phone_num;
	cout << "[1] Insert an information: \n";
	cout << "[2] Check the group: \n";
	cout << "[3] Look for phone records: \n";
	cout << "[4] Exit the console: \n";
	cout << "Your choice: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		cout << "Please insert the name: ";
		cin.ignore();
		getline(cin, name);   
		cout << "Please insert the nickname: ";
		getline(cin, nickname);
		cout << "Please insert the email address: ";
		cin >> email_address;
		do
		{
			cout << "Please input his/her last call date time (9-digit number like 2011081328): ";
			cin >> last_time_date;
		} while (last_time_date.length() != 10);
		do
		{
			cout << "Please input his/her phone number (8-digit integer and not started with 0): ";
			cin >> phone_num;
		} while ((phone_num <9999999) || (phone_num>100000000));

		int choice2;
		do {
			cout << "Which group do you want to insert in? (1.Family 2.Friend 3.Junk): " << endl;
			cin >> choice2;   //to determine which group the phone record belongs to
		} while ((choice2 < 1) || (choice2 > 3));
		data_record(name, nickname, email_address, last_time_date, phone_num, choice2);   //save the phone record to an output file
		switch (choice2)   //add the phone record to variable "(phoneBk) Setting"
		{
		case 1:
			cout << "Insert to Family!" << endl;
			Setting.Family[familyN].Set_begginning(name, nickname, email_address, last_time_date, phone_num);
			Setting.Family[familyN].Set_User_info_string(name, nickname, email_address, last_time_date);
			Setting.Family[familyN].Set_User_info_int(phone_num);
			familyN = familyN + 1;
			cout << "--------------------------------------------------------------" << endl;
			break;
		case 2:
			cout << "Insert to Friend!" << endl;
			Setting.Friend[friendN].Set_begginning(name, nickname, email_address, last_time_date, phone_num);
			Setting.Friend[friendN].Set_User_info_string(name, nickname, email_address, last_time_date);
			Setting.Friend[friendN].Set_User_info_int(phone_num);
			friendN = friendN + 1;
			cout << "--------------------------------------------------------------" << endl;
			break;
		case 3:
			cout << "Insert to Junk!" << endl;
			Setting.Junk[junkN].Set_begginning(name, nickname, email_address, last_time_date, phone_num);
			Setting.Junk[junkN].Set_User_info_string(name, nickname, email_address, last_time_date);
			Setting.Junk[junkN].Set_User_info_int(phone_num);
			junkN = junkN + 1;
			cout << "--------------------------------------------------------------" << endl;
			break;
		}
		break;
	case '2':   // to get the data from variable "(phoneBk) Setting" (by groups)
			cout << "Those data are under Family Group: " << endl;
			for (int i = 1; i < familyN+1; i++)
			{
				if (familyN == 1) { cout << "No record. \n"; break; }
				Setting.Family[i].data_record();
			}
			cout << "-----------------------------------\n";
			cout << "Those data are under Friend Group: " << endl;
			for (int i = 1; i < friendN+1; i++)
			{
				if (friendN == 1) { cout << "No record. \n"; break; }
				Setting.Friend[i].data_record();
			}
			cout << "-----------------------------------\n";
			cout << "Those data are under Junk Group: " << endl;
			for (int i = 1; i < junkN+1; i++)
			{
				if (junkN == 1) { cout << "No record. \n"; break; }
				Setting.Junk[i].data_record();
			}
			cout << "-----------------------------------\n";
		break;
	case '3':
		Task1();   // displays a sorted list of phone records based on the last-call date and time (latest first)
		break;
	case '4':   //Exit
		cout << "Goodbye!\n";
		return true;
	default:   //require to input a vaild input
		cout << "Please input a valid input." << endl;
		break;
	}
	return false;

}
/*--------------------------------------------PhoneRec------------------------------------------------------------*/
void phoneRec::Set_begginning(string name, string nickname, string email_address,string last_time_date,int phone_num)
{   // to display the latest user input (phone records)
	cout << "New phone record is added. \n";
	cout << "His/Her name is " << name << endl;
	cout << "His/Her nickname is " << nickname << endl;
	cout << "His/Her 's email address is " << email_address << endl;
	cout << "His/Her 's last time call day is " << last_time_date << endl;
	cout << "His/Her 's phone number is " << phone_num << endl;
	cout << " " << endl;

}
void phoneRec::Set_User_info_string(string name, string nickname, string email_address,string last_time_date)
{   //store the data to private elements in class phoneRec
	user_name3 = name;
	user_nickname3 = nickname;
	user_email_address3 = email_address;
	user_last_time_date3 = last_time_date;
}
void phoneRec::Set_User_info_int(int phone_num)
{   //store the data to private elements in class phoneRec
	user_phone_num3 = phone_num;
}

/*get data from private elements in class phoneRec*/
string phoneRec::p_user_name3() 
{
	return user_name3;
}
string phoneRec::p_user_nickname3()
{
	return user_nickname3;
}
string phoneRec::p_user_email_address3()
{
	return user_email_address3;
}
string phoneRec::p_user_last_time_date3()
{
	return user_last_time_date3;
}
int phoneRec::p_user_phone_num3()
{
	return user_phone_num3;
}

void phoneRec::data_record()   //show info about a phone record
{
	if (user_phone_num3!=0) {
		cout << user_name3 << " || " << user_nickname3 << " || " << user_email_address3 << " || " << user_last_time_date3 << " || " << user_phone_num3 << "\n";
		}
}
/*--------------------------------------------------------------------------------------------------------------------------*/

void Task1()
{
	string listT[100];   //to store the data of last-call date and time
	string listN[100];   //to store the data of nicknames
	string cnt;
	string cnt1;
	string temp;
	int choice;
	int max=1;   //total number of data in an user-given group
	string format;
	string temp1, temp2;
	do {
		cout << "Which group of phone records do you want? (1.Family 2.Friend 3.Junk 4.Exit):";   //choose the group that user wants to know
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Sorted list of phone records (Family): " << endl;
			max = familyN;
			if (max == 1){cout << "No record. \n\n"; }   //when max=1, means there is no record
			break;
		case 2:
			cout << "Sorted list of phone records (Friend): " << endl;
			max = friendN;
			if (max == 1) { cout << "No record. \n\n"; }
			break;
		case 3:
			cout << "Sorted list of phone records (Junk): " << endl;
			max = junkN;
			if (max == 1) { cout << "No record. \n\n"; }
			break;
		case 4:
			break;
		default:
			cout << "Please input a valid input.\n" << endl;
			break;
		}
	} while ((choice<1) || (choice>4));

	if (choice == 4) { cout << "It's now return to menu. \n";}
	else if (max != 1) {
		for (int i = 1; i < max + 1; i++) {   //get data from variable "(phoneBk) Setting"
			switch (choice)
			{
			case 1:
				listT[i] = Setting.Family[i].p_user_last_time_date3();
				listN[i] = Setting.Family[i].p_user_nickname3();
				break;
			case 2:
				listT[i] = Setting.Friend[i].p_user_last_time_date3();
				listN[i] = Setting.Friend[i].p_user_nickname3();
				break;
			case 3:
				listT[i] = Setting.Junk[i].p_user_last_time_date3();
				listN[i] = Setting.Junk[i].p_user_nickname3();
				break;
			}
		}
		for (int i = 1; i < max; i++) {   //order of the date and time   //latest first
			for (int j = 1; j < max - i; j++) {
				temp1 = listT[j];
				temp2 = listT[j + 1];
				if (temp1 < temp2) {
					cnt1 = listT[j];
					listT[j] = listT[j + 1];
					listT[j + 1] = cnt1;
					cnt1 = listN[j];
					listN[j] = listN[j + 1];
					listN[j + 1] = cnt1;
				}
			}
		}
		for (int i = 1; i < max; i++) {   //display sorted list of phone records
			cout << listN[i] << " : ";   //show the nickname
			format = listT[i];
			date(format);   //change the format of the dat and time
			cout << "\n\n";
		}
	}
}

void date(string rec)
{
	int month;
	string convert;
	cout << rec[4] << rec[5];  //show the date
	convert = rec[2];
	month = stoi(convert);   //change to int
	convert = rec[3];
	month = month * 10 + stoi(convert);   //change to int and get the exact value of month
	switch (month)   
	{
	case 1: cout << " January "; break;
	case 2: cout << " February "; break;
	case 3: cout << " March "; break;
	case 4: cout << " April "; break;
	case 5: cout << " May "; break;
	case 6: cout << " June "; break;
	case 7: cout << " July "; break;
	case 8: cout << " August "; break;
	case 9: cout << " September "; break;
	case 10: cout << " October "; break;
	case 11: cout << " November "; break;
	case 12: cout << " December "; break;
	}
	cout << "20" << rec[0] << rec[1] << " " << rec[6] << rec[7] << ":" << rec[8] << rec[9];  //year and time
}

bool password()
{
	char pw[100];   //store the password
	bool check = false;
	bool check1 = false;
	char pw_user[100];   //store the data of registered account (username and password)
	char pw_rec[100];
	int attempt = 0;   //times for the user enter the password

	cout << "Please login with a username or create a new account: ";
	cin.getline(pw_user,100);   //if it's not the registered username, it will craete a new account automatically
	cout << "Password: ";
	cin.getline(pw, 100);

	ifstream fin1("Password_Record.cpp");   //open file Password_Record.cpp to get the data of registered account
	if (!fin1) {
		cout << "Password file: opening error!\n";
	}
	while (fin1.getline(pw_rec, 100)) {   //find the registered username with password in the file
		if (check == true) {
			do {
				if (strcmp(pw_rec, pw) == 0) {
					check1 = true;
					cout << "Access successfully. \n\n";   //correct username and password
					break;
				}
				if (attempt == 2) {
					cout << "Only 3 attempts are allowed. Goodbye! \n";   //exit the program if user still can't log in after 3 attemts
					return true;
				}
				if (attempt < 2) {   //wrong username and password
					cout << "Please try again: ";
					cin.getline(pw, 100);
					attempt++;
				}
			} while ((attempt < 3) || (check1 != true));
			break;
		}
		if (strcmp(pw_rec, pw_user)==0) {
			check = true;
		}
	}
	fin1.close();
	if (check == false) {   //store the data of new account to the output file
		ofstream fout1("Password_Record.cpp", ios::app);
		fout1 << "\n" << pw_user << "\n";
		fout1 << pw;
		fout1.close();
		cout << "New account is created.\n\n";
	}
	return false;
}