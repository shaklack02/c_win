// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "Loger.h"

#pragma comment(lib, "Ws2_32.lib")



int main() {
	loger("WINSOCK CLIENT")

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	addrinfo hints;
	memset(&hints, 0, sizeof(hints)); // must be nulled. Otherwise the GetAddrInfoEx function will fail with WSANO_RECOVERY.
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	addrinfo *Results = NULL;

	if (!getaddrinfo("127.0.0.1", "255", &hints, &Results)) {

		loger("Ready To Create SOCKET and Connect to SERVER")

		SOCKET connectSocket = INVALID_SOCKET;

		connectSocket = socket(Results->ai_family, Results->ai_socktype, Results->ai_protocol);

		if (connectSocket != INVALID_SOCKET) {
			loger( "Created Socket Successfully ...connecting to server")

			if (connect(connectSocket, Results->ai_addr, Results->ai_addrlen) != SOCKET_ERROR) {
				loger("Connected To Server Successfully ")

				std::string Message;
				while (true) {

					loger("Enter A Message :")

					std::getline(std::cin, Message);

					if (send(connectSocket, Message.c_str(), sizeof(Message), 0) != SOCKET_ERROR) {
						loger( "MESSAGE IS SENT\n")
					}
				}
			}
		}
	}



	std::cin.get();
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
