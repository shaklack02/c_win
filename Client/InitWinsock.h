#pragma once

#ifndef Init_WINSOCK_H
#define Init_WINSOCK_H

#include <string>
#include <iostream>
#include <WS2tcpip.h>


// Include the Winsock library (lib) file

class Win_sock_client {
public:

	WSADATA data;
	WORD version;

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
	Win_sock_client();
	~Win_sock_client();

	int Connect_Init(const char *, const int);
	int send_data(std::string str_data);
};

#endif