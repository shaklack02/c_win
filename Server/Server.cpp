// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "Loger.h"

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main() {
	cout << ">>>WINSOCK SEREVER\n";

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;


	addrinfo *Results = NULL;

	if (!getaddrinfo("127.0.0.1", "255", &hints, &Results)) {
		loger("->Ready To Create SOCKET and bind Address")

		SOCKET listenSocket = INVALID_SOCKET;

		listenSocket = socket(Results->ai_family, Results->ai_socktype, Results->ai_protocol);
		if (listenSocket != INVALID_SOCKET) {
			loger("->Socket is created...")

			if (bind(listenSocket, Results->ai_addr, Results->ai_addrlen) != SOCKET_ERROR) {

				//cout << "and bind successfully\n [" << getsockname(listenSocket, Results->ai_addr, (int *)Results->ai_addrlen) << "]\n";

				if (!listen(listenSocket, SOMAXCONN)) {
					loger("->waiting for Client to connect")

					SOCKET clientSocket = INVALID_SOCKET;
					clientSocket = accept(listenSocket, NULL, NULL);
					if (clientSocket != INVALID_SOCKET) {
						cout << "->Client Has Connected\nWaiting for Messages...";
						int iResult = 1;
						while (true) {
							char BufferRcv[9000];
							iResult = recv(clientSocket, BufferRcv, 9000, 0);
							if (iResult > 0) {
								cout << "\nBuffer Received : \n" << BufferRcv;
							}
						}
					}

				}
			}
			else { cout << "Error Binding Socket!!!"; }

		}

	}
	cin.get();
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
