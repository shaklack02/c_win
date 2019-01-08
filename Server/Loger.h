#pragma once
#ifndef LOGER_H
#define LOGER_H
#include <iostream>


#ifdef CLIENT_LOGER

#define s_loger(n_name) std::cout<<"<LIENT LOGER+STOP> "<< name <<std::endl; std::cin.get();
#define _loger(n_name,name) std::cout<<"<CLIENT LOGER> "<< n_name <<" "<< name <<std::endl; 
#define T_loger(n_name,name, s_name, t_name) std::cout<<"<CLIENT LOGER> "<< n_name <<" "<< name <<" " << s_name << " " << t_name <<std::endl; 
#define loger(n_name) std::cout<<"<CLIENT LOGER> "<<  n_name <<std::endl; 

#endif // SERVER_LOGER

#ifdef SERVER_LOGER
#define s_loger(n_name) std::cout<<"<SERVER LOGER+STOP> "<< name <<std::endl; std::cin.get();
#define _loger(n_name,name) std::cout<<"<SERVER LOGER> "<< n_name <<" "<< name <<std::endl; 
#define T_loger(n_name,name, s_name, t_name) std::cout<<"<<SERVER LOGER> "<< n_name <<" "<< name <<" " << s_name << " " << t_name <<std::endl; 
#define loger(n_name) std::cout<<"<SERVER LOGER> "<<  n_name <<std::endl; 
#endif // CLIENT_LOGER

#ifdef HEADER_WINSOCK_ERROR_LOGER 
#define s_loger(n_name) std::cout<<"<ERROR LOGER+STOP> "<< name <<std::endl; std::cin.get();
#define _loger(n_name,name) std::cout<<"<ERROR LOGER> "<< n_name <<" "<< name <<std::endl; 
#define T_loger(n_name,name, s_name, t_name) std::cout<<"<ERROR LOGER> "<< n_name <<" "<< name <<" " << s_name << " " << t_name <<std::endl; 
#define loger(n_name) std::cout<<"<ERROR LOGER> "<<  n_name <<std::endl; 
#endif // HEADER_WINSOCK_ERROR_LOGER 



#endif