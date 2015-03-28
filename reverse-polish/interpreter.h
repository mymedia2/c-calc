#ifndef GRV_INTERRETER
#define GRV_INTERRETER

extern int grv_errno;
#define GRV_ERR_MEM 127
#define GRV_ERR_SYMBOLS 126
#define GRV_ERR_OPERATORS 125

int grv_reverse_polish_interpreter(char* result);

#endif // GRV_INTERRETER
