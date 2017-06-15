#ifndef __UART_DATA_H__
#define __UART_DATA_H__

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>      
#include <termios.h>    
#include <errno.h>  
#include <pthread.h>
#include <cstring>

typedef class WSA_UART {

public:
    int  fd;  

    int  baudrate;
    char port[20];
    char stop_bit;
    char data_len;
    char check_bit[10];

    int interval_send_data;

    bool running;

    char send_buf[512];
    char recv_buf[512];

    WSA_UART *wsa_uart;

    pthread_t recv_thread;
    pthread_t send_thread;

    int  help ( int argc );
    int  init_uart_port ( void );

    int  get_baudrate ( char *baudRateString );

    int  uart_send ( int fd, char *data, int datalen );
    int  uart_recv ( int fd, char *data, int datalen );

    static void *recv_data_thread ( void *arg );
    static void *send_data_thread ( void *arg );

    int uart_init(char* uart_port, char* uart_baudrate, char* uart_stop_bit, char* uart_data_len, char* uart_check_bit, char* uart_interval_send_data, char* uart_send_data);
    void uart_close(void);
} WSA_UART;

#endif // __UART_DATA_H__