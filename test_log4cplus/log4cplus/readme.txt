本模块使用 log4cplus-1.2.1

1、嵌入该模块到工程的根目录
2、c++-》常规-》附加包含目录
../log4cplus/include
3、把相应的dll已移植过去就可以
4、代码的使用
CLogDefine::initFile("main.log");
TRACELOG(__FUNCTION__, "This ishahhahhh"  << " just at" << "est." << std::endl);
DEBUGLOG(__FUNCTION__, "This is a bool: " << true);
INFOLOG(__FUNCTION__, "This is a char: " << 'x');
WARNLOG(__FUNCTION__, "This is a int: " << 1000);
演示效果
2017-12-05 09:38:26-func(16)[WARN]<7364> - WARNLOG#9255#WARNLOG
2017-12-05 09:38:26-func(13)[TRACE]<7364> - TRACELOG#9256#TRACELOG
2017-12-05 09:38:26-func(14)[DEBUG]<7364> - DEBUGLOG#9256#DEBUGLOG
2017-12-05 09:38:26-func(15)[INFO]<7364> - INFOLOG#9256#INFOLOG

