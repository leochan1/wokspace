#include <time.h> 
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#ifdef _DEBUG
#pragma comment(lib,"../log4cplus/lib/log4cplusD.lib")
#else
#pragma comment(lib,"../log4cplus/lib/log4cplus.lib")
#endif // _DEBUG
using namespace log4cplus;
#include <stdio.h>  
#include <direct.h>  
#include <io.h>
#define MAXPATH  1024
std::string getFullPatg()
{
	char buffer[MAXPATH],szPath[MAXPATH]={0};   
	_getcwd(buffer,MAXPATH);  
	printf("%s",buffer); 
	sprintf(szPath,"%s/log/",buffer);
	if ( access(szPath,0) )
		mkdir(szPath);
	return std::string(szPath);
}
using namespace std;
class CLogDefine{
private:
	static std::string m_szTitile;
	static std::string m_szFuncName;
	Logger _logger;
private:
	CLogDefine(){
		SharedAppenderPtr _append (new RollingFileAppender(m_szTitile, 200*1024, 10));
		_append->setName("LogDefine");
		time_t tmp_time=time(NULL);  
		struct tm *p;  
		p = localtime(&tmp_time);  
		char szDate[100]={0};
		sprintf(szDate,"%04d-%02d-%02d %02d:%02d:%02d-", p->tm_year+1900, p->tm_mon+1, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec); 
		std::string pattern = "%c(%L)[%p]<%t> - %m%n";
		std::auto_ptr<Layout> _layout(new PatternLayout(pattern));
		_append->setLayout( _layout );
		std::string szLogger = std::string(szDate) + m_szFuncName;
		_logger = Logger::getInstance(szLogger);
		_logger.addAppender(_append);
		_logger.setLogLevel(ALL_LOG_LEVEL);
	}
public:
	~CLogDefine(){}
	static void initFile(string str)
	{
		time_t tmp_time=time(NULL);  
		struct tm *p;  
		p = localtime(&tmp_time);  
		char szDate[100]={0};
		sprintf(szDate, "%d-%d-%d_", p->tm_year, p->tm_mon, p->tm_mday); 
		m_szTitile = getFullPatg() + szDate + str;
		std::locale::global(std::locale("chs"));
	}
	static void setFuncName(string szFuncname)
	{
		m_szFuncName = szFuncname;
	}
	static Logger  getInstance()
	{
		static CLogDefine instance;
		return instance._logger;
	}
};
std::string CLogDefine::m_szTitile="";
std::string CLogDefine::m_szFuncName="";
#define FUNCTION_NAME(str)\
CLogDefine::setFuncName(str);
#define TRACELOG(strFunc,p) \
FUNCTION_NAME(strFunc)\
LOG4CPLUS_TRACE(CLogDefine::getInstance(), p)
#define DEBUGLOG(strFunc,p) \
FUNCTION_NAME(strFunc)\
LOG4CPLUS_DEBUG(CLogDefine::getInstance(), p)
#define INFOLOG(strFunc,p) \
FUNCTION_NAME(strFunc)\
LOG4CPLUS_INFO(CLogDefine::getInstance(), p)
#define WARNLOG(strFunc,p) \
FUNCTION_NAME(strFunc)\
LOG4CPLUS_WARN(CLogDefine::getInstance(), p)
#define ERRORLOG(strFunc,p) \
FUNCTION_NAME(strFunc)\
LOG4CPLUS_ERROR(CLogDefine::getInstance(), p)

