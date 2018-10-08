#ifndef LOG_H
#define LOG_H

#include "../lib/stdint.h"

void LOG_INFO(char * buf, size_t len);
void LOG_DEBUG(char * buf, size_t len);
void LOG_ERROR(char * buf, size_t len);
void LOG_FATAL(char * buf, size_t len);
void LOG_BASE(char * buf, size_t len, char * prompt, size_t prompt_len);
#endif //LOG_H