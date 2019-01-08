#pragma once


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


//=====================Server Class===============================

class Win_sock_Server
{
public:
	WSADATA data;
	WORD version;

	int wsOk;

	// Create a hint structure for the server
	sockaddr_in serverHint;
	// Socket creation, note that the socket type is datagram
	SOCKET sin;

	sockaddr_in client; // Use to hold the client information (port / ip address)

	Win_sock_Server();
	~Win_sock_Server();

	int Server_Connect_Init(const char *IP, const int Port);
	//int Server_send_data(std::string str_data);

};

