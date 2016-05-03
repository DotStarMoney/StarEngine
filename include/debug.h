#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_LEVEL 0


#if(DEBUG_LEVEL == 1)
#define DEBUG_ERROR_MISUSE
#elif(DEBUG_LEVEL == 2)
#define DEBUG_ERROR_LOGGING
#define DEBUG_ERROR_MISUSE
#endif


#define DEBUG_ASSERT(_COND_, _ERRMSG_) _COND_


#endif