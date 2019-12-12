#pragma once
#include <Siv3D.hpp>

class MySocketServer {
private:
	static TCPServer *server;
	static bool connected;
	static char data[18];
public:
	MySocketServer() = delete;
	static void initialize();	//初期化
	static void finalize();		//終了化
	static void update();
	static bool isConnection();//現在接続されているかどうか

};