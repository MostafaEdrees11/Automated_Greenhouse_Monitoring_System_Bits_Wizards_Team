#include "LIB/Error_States.h"
#include "LIB/stdTypes.h"

#include "APP/AGMS/AGMS_int.h"

#define Slave	0
#define Master	1

#define Code	Master


#if Code == Master
int main()
{
	AGMS_enuInit_AutomaticControl();

	while(1)
	{
		AGMS_enuRunning_AutomaticControl();
	}
}

#elif Code == Slave
int main()
{
	AGMS_enuInit_Display();

	while(1)
	{
		AGMS_enuRunning_Display();
	}
}
#endif
