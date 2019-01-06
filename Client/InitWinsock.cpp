
#include "InitWinsock.h"
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
