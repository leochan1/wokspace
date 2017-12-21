// test_log4cplus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../log4cplus/LogDefine.h"
void func()
{
	TRACELOG(__FUNCTION__, "This ishahhahhh"  << " just at" << "est." << std::endl);
	DEBUGLOG(__FUNCTION__, "This is a bool: " << true);
	INFOLOG(__FUNCTION__, "This is a char: " << 'x');
	WARNLOG(__FUNCTION__, "This is a int: " << 1000);
	for (int i = 0; i < 10000; ++i) {
		TRACELOG(__FUNCTION__, "TRACELOG#" << i  << "#TRACELOG");
		DEBUGLOG(__FUNCTION__, "DEBUGLOG#" << i  << "#DEBUGLOG");
		INFOLOG(__FUNCTION__, "INFOLOG#" << i  << "#INFOLOG");
		WARNLOG(__FUNCTION__, "WARNLOG#" << i  << "#WARNLOG");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	CLogDefine::initFile("main.log");
	func();
	getchar();
	return 0;
}

