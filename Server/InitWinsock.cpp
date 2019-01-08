
#include "InitWinsock.h"

#define HEADER_WINSOCK_ERROR_LOGER 
#include "Loger.h"

Win_sock_client::Win_sock_client()
{
	// To start WinSock, the required version must be passed to
	// WSAStartup(). This server is going to use WinSock version
	// 2 so I create a word that will store 2 and 2 in hex i.e.
	// 0x0202
	version = MAKEWORD(2, 2);

	// Start WinSock
	wsOk = WSAStartup(version, &data);

}

Win_sock_client::~Win_sock_client()
{
	// Close the socket
	closesocket(out);
	// Close down Winsock
	WSACleanup();
	loger("Diconstractor called")
}

int Win_sock_client::Connect_Init(const char *IP, const int Port) 
{

	if (wsOk != 0)
	{
		// Not ok! Get out quickly
		_loger("Can't start Winsock! ", wsOk)
			return 1;
	}

	////////////////////////////////////////////////////////////
	// CONNECT TO THE SERVER
	////////////////////////////////////////////////////////////

	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(Port); // Little to big endian conversion
	inet_pton(AF_INET, IP, &server.sin_addr); // Convert from string to byte array
													   // Socket creation, note that the socket type is datagram
	out = socket(AF_INET, SOCK_DGRAM, 0);
	return 0;
}

int Win_sock_client::send_data(std::string str_data)
{
	if (wsOk != 0)
	{
		// Not ok! Get out quickly
		_loger("Winsock not STARTED! ", wsOk)
			return 1;
	}

	return sendto(out, str_data.c_str(), str_data.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	
}

//=====================Server Class===============================

Win_sock_Server::Win_sock_Server()
{
	// To start WinSock, the required version must be passed to
	// WSAStartup(). This server is going to use WinSock version
	// 2 so I create a word that will store 2 and 2 in hex i.e.
	// 0x0202
	version = MAKEWORD(2, 2);

	// Start WinSock
	wsOk = WSAStartup(version, &data);

}

Win_sock_Server::~Win_sock_Server()
{
	// Close socket
	closesocket(sin);

	// Shutdown winsock
	WSACleanup();
	loger("Diconstractor called")
}

int Win_sock_Server::Server_Connect_Init(const char *IP, const int Port)
{

	if (wsOk != 0)
	{
		// Not ok! Get out quickly
		_loger("Can't start Winsock! ", wsOk)
			return 1;
	}

	////////////////////////////////////////////////////////////
	// SOCKET CREATION AND BINDING
	////////////////////////////////////////////////////////////

	// Create a socket, notice that it is a user datagram socket (UDP)
	sin = socket(AF_INET, SOCK_DGRAM, 0);

	// Create a server hint structure for the server	
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	serverHint.sin_family = AF_INET; // Address format is IPv4
	serverHint.sin_port = htons(54000); // Convert from little to big endian

										// Try and bind the socket to the IP and port
	if (bind(sin, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		_loger("Can't bind socket! ", WSAGetLastError() )
		return 1; //Error could not Bind
	}

	return 0;
}

