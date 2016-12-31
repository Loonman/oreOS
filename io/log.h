#ifndef LOG_H
#define LOG_H

void LOG_INFO(char * buf, int len);
void LOG_DEBUG(char * buf, int len);
void LOG_ERROR(char * buf, int len);
void LOG_FATAL(char * buf, int len);
void LOG_BASE(char * buf, int len, char * prompt, int prompt_len);
#endif //LOG_H