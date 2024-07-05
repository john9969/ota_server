#ifndef API__H
#define API__H

#include <iostream>
class Api {
	enum STATE {
		STATE_RES =0,
		STATE_INPROGRESS,
		STATE_DONE,
		STATE_PROCESS_FAIL,
		STATE_INIT
	};
	enum ERR_CODE {
		ERR_CODE_OPEN_FILE_FAIL	=	0,
		ERR_CODE_DIR_EMPTY		=	1,
		ERR_CODE_COMMENT_WRONG_FORM =2
	};
public:
	Api();
	virtual ~Api();
	virtual void setDir(const std::string& dir) =0;
	virtual void setComment(const std::string& comment) = 0;
	virtual void run() = 0;
	virtual uint32_t getProcess() = 0;
	virtual uint32_t getState()	= 0;
	virtual uint32_t getErrCode() = 0;

};



#endif // !API__H
