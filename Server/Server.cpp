// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cstdlib>
#include <iostream>
#include <WS2tcpip.h>
#include "InitWinsock.h"

#define SERVER_LOGER // Turns on the server loger from the loger.h
#include "Loger.h"

// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

// Saves us from typing std::cout << etc. etc. etc.
using namespace std;

// Main entry point into the server
void main()
{
	Win_sock_Server win_s_s;
	
	// Start WinSock
	
	if (win_s_s.Server_Connect_Init("127.0.0.1", 54000))
		loger("Error Can't start Winsock OR Bind !")

	////////////////////////////////////////////////////////////
	// MAIN LOOP SETUP AND ENTRY
	////////////////////////////////////////////////////////////

	
	int clientLength = sizeof(win_s_s.client); // The size of the client information

	char buf[1024];
	loger("SERVER STARTED !!")
	// Enter a loop
	while (true)
	{
		ZeroMemory(&win_s_s.client, clientLength); // Clear the client structure
		ZeroMemory(buf, 1024); // Clear the receive buffer

		// Wait for message
		int bytesIn = recvfrom(win_s_s.sin, buf, 1024, 0, (sockaddr*)&win_s_s.client, &clientLength);

		if (bytesIn == SOCKET_ERROR)
		{
			_loger( "Error receiving from client ", WSAGetLastError() )
			continue;
		}

		// Display message and client info
		char clientIp[256]; // Create enough space to convert the address byte array
		ZeroMemory(clientIp, 256); // to string of characters

		// Convert from byte array to chars
        inet_ntop(AF_INET, &win_s_s.client.sin_addr, clientIp, 256);

		// Display the message / who sent it
		T_loger( "Message recv from ", clientIp ," : " , buf )
	}


}