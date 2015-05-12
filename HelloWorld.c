
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#include <string.h> // string function definitions
#include <fcntl.h> // File control definitions
#include <errno.h> // Error number definitions
#include <termios.h> // POSIX terminal control definitions
#include <time.h>   // time calls
#include <stdlib.h>   // time calls

#define TIMEOUT 10 // timeout waiting for messages from the serial device
#define INPUT_BUFFER_SIZE 128 // for possible future optimizations"

int open_serial(char * device, uint16_t baudrate) {
	int result;

	printf("Opening ESUMS device at %s...\n", device);
	result = open(device, O_RDWR | O_NOCTTY | O_NDELAY);

	if (result < 0) {
		perror("Error opening Serial port");
	}
	else {

		//fcntl(result, F_SETFL, FNDELAY); // To make reading non-blocking ?
		fcntl(result, F_SETFL, 0); // To restore normal blocking read from the port

		printf("Configuring port %s...\n", device);

		struct termios port_settings;

		tcgetattr(result, &port_settings); // get current options

		cfsetispeed(&port_settings, B115200);    // set baud rates to 115200
		cfsetospeed(&port_settings, B115200);

		port_settings.c_cflag &= ~PARENB;	// Set 8N1, No Parity
		port_settings.c_cflag &= ~CSTOPB;
		port_settings.c_cflag &= ~CSIZE;
		port_settings.c_cflag |= CS8;

		port_settings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // Raw input mode

		port_settings.c_oflag &= ~OPOST; // Raw output mode

		tcsetattr(result, TCSANOW, &port_settings);    // apply the settings to the port
	    sleep(1); // wait a bit
        }
	return result;
	
}

int send_byte(int device, uint8_t b) {
	int n;
	unsigned char data[1];
	data[0] = b;

	n = write(device, data, 1);
	if (n < 0) {
		perror("Error writing to Serial device");
		return -1;
	}
	return 0;
}

int main(char* argv[]) {
	int port = open_serial("/dev/ttyATH0", 115200);
	send_byte(port, (uint8_t) 'H');
	send_byte(port, (uint8_t) 'e');
	send_byte(port, (uint8_t) 'l');
	send_byte(port, (uint8_t) 'l');
	send_byte(port, (uint8_t) 'o');
	send_byte(port, (uint8_t) ' ');
	send_byte(port, (uint8_t) 'W');
	send_byte(port, (uint8_t) 'o');
	send_byte(port, (uint8_t) 'r');
	send_byte(port, (uint8_t) 'l');
	send_byte(port, (uint8_t) 'd');
	send_byte(port, (uint8_t) '!');
	
	return 0;
}
