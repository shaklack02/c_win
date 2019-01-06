#pragma	once
#include "pch.h"


#include <string>
#include <iostream>
#include <WS2tcpip.h>

// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

class Win_sock_client {
private:
	////////////////////////////////////////////////////////////
	// INITIALIZE WINSOCK
	////////////////////////////////////////////////////////////

	// Structure to store the WinSock version. This is filled in
	// on the call to WSAStartup()
	WSADATA data;

	// To start WinSock, the required version must be passed to
	// WSAStartup(). This server is going to use WinSock version
	// 2 so I create a word that will store 2 and 2 in hex i.e.
	// 0x0202
	WORD version;

	// Start WinSock
	int wsOk;
	
	////////////////////////////////////////////////////////////
	// CONNECT TO THE SERVER
	////////////////////////////////////////////////////////////

	// Create a hint structure for the server
	sockaddr_in server;
													   // Socket creation, note that the socket type is datagram
	SOCKET out;

	// Write out to that socket
	//string s(argv[1]);

public:
	Win_sock_client(); //constractor
	~Win_sock_client(); //diconstractor
	int send_data(std::string str_data);
};

