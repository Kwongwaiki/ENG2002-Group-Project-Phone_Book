#include <iostream>
#include <string>
using namespace std;
class phoneRec
{
private: /*to store input data*/
	string user_name3, user_nickname3, user_email_address3, user_last_time_date3;
	int user_phone_num3;

public:
	//constructor and destructor are not needed
	void Set_begginning(string name, string nickname, string email_address, string last_time_date, int phone_num);  /*display those input data*/
	void Set_User_info_string(string name, string nickname, string email_address, string last_time_date);   /*save input data to private elements*/
	void Set_User_info_int(int phone_num); /*save input data to private elements*/

	/*for accessing private elements*/
	string p_user_name3();
	string p_user_nickname3();
	string p_user_email_address3();
	string p_user_last_time_date3();
	int p_user_phone_num3();

	/*for displaying each phone records*/
	void data_record();

};
