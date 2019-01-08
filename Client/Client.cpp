// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "InitWinsock.h"

#define CLIENT_LOGER//turns on the client loger from loger.h
#include "Loger.h"


#pragma comment (lib, "ws2_32.lib")

int main() // We can pass in a command line option!! 
{
	Win_sock_client win_s_c;

	//string s(argv[1]);

	std::string str_data = "helllo";

	if (win_s_c.Connect_Init("127.0.0.1", 54000)) //server port 54000 
	{
		loger("Error Can't start Winsock!")
			return 1;
	}
	while (true)
	{
		std::cout << std::endl;
		//std::cin >> str_data ;
		std::getline(std::cin, str_data);
		if (win_s_c.send_data(str_data) == SOCKET_ERROR)
		{
			_loger("FAILD to send Data", WSAGetLastError())
		}
	}
	std::getchar();
}


