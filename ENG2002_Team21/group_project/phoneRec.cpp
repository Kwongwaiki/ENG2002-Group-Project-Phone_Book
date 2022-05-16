#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class phoneRec
{
private:
	string user_name3, user_nickname3, user_email_address3, user_last_time_date3;
	int user_phone_num3;

public:
	void Set_begginning(string name, string nickname, string email_address, string last_time_date, int phone_num);
	void Set_User_info_string(string name, string nickname, string email_address, string last_time_date);
	void Set_User_info_int(int phone_num); /*for phonebk displayment*/

	/*for phonebk access private elements*/
	string p_user_name3();
	string p_user_nickname3();
	string p_user_email_address3();
	string p_user_last_time_date3();
	int p_user_phone_num3();

	/*for phonebk access private elements*/
	void data_record();

};