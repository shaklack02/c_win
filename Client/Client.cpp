// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#include "Win_sock.h"
#include "../intermediate/Loger.h"




void main(int argc, char* argv[]) // We can pass in a command line option!! 
{
	Win_sock_client win_s_c();
	int sendOk;
	// Write out to that socket
	//string s(argv[1]);
	std::string str_data = "helllo";
	sendOk = win_s_c.send_data(str_data);
	if (sendOk == SOCKET_ERROR)
	{
		_loger( "(That didn't work!) -> FAILD to send Data" ,WSAGetLastError())
	}
}
