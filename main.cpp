#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <iostream>
#include <SerialStream.h>
int main()
{
    LibSerial::SerialStream my_serial_stream;
    my_serial_stream.Open("/dev/ttyS0");
    my_serial_stream.SetBaudRate( LibSerial::SerialStreamBuf::BAUD_115200 );
    int sock;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
        //exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        //exit(2);
    }

    while(1)
    {
        bytes_read = recvfrom(sock, buf, 1024, 0, NULL, NULL);
        buf[bytes_read] = '\0';
        std::cout << buf << std::endl;
        my_serial_stream << buf;
    }

    return 0;
}