#include <iostream>
#include <string>
#include "phoneRec.h"
using namespace std;
class phoneBk  // class phoneBk holding a number of phoneRec objects
{
public:  //in 3 groups of data
	phoneRec Family[100]; /*set 100 to be constant of array*/
	phoneRec Friend[100];
	phoneRec Junk[100];
};
