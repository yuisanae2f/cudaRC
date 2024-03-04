# cudaRC.h
generates the request message for the [cudaTheatre server](https://github.com/yuisanae2f/cudaRC/tree/Theatre).

# Crucial Dependencies
## [CPure](https://github.com/yuisanae2f/CPure)
Performs the dynamic allocation on managing heap memory.
## [Windows](https://www.microsoft.com/ko-kr/windows/)
This library runs on Windows.

# ae2f_cudaRC_address
```c
struct sockaddr_in* ae2f_cudaRC_address(
	struct sockaddr_in* pureSockAddr,
	const char* ip,
	u_short port
);
```
sets the `puresockAddr` with `ip` and `port`.

# ae2f_cudaRC_sendPack
```c
int ae2f_cudaRC_sendPack(
	SOCKET sock,
	struct sockaddr_in* sockAddr,
	const char* key,
	ptr_ae2f_Dynamic value 
);
```
generates and sends the request and wait for the response.  
Provided the `value` not zero, it sends [set](https://github.com/yuisanae2f/cudaRC/blob/Theatre/req/cdrc.md#set) request with `value`.  
Otherwise it sends [get](https://github.com/yuisanae2f/cudaRC/blob/Theatre/req/cdrc.md#get) request.

# ae2f_cudaRC_sendDel
```c
int ae2f_cudaRC_sendDel(
	SOCKET sock,
	struct sockaddr_in* sockAddr,
	const char* key
);
```
generates and sends the request and wait for the response.  
requests the server to delete the value which has a key of `key` from the [heap](https://github.com/yuisanae2f/cudaRC/blob/Theatre/README.md#Map).

# ae2f_cudaRC_sendRun
```c
int ae2f_cudaRC_sendRun(
	SOCKET sock,
	struct sockaddr_in* sockAddr,
	const char* dll,
	const char* function
);
```
generates and sends the request and wait for the response.  
requests the server to run the `function` from `dll`.

# Ex
Following code sends the request to the server to add the value of `Thing` with a key of `keyTest234`.
```c
#define AE2F_CPP

#include <stdio.h>
#include "./headers/cudaRC.h"

#pragma comment(lib, "../x64/Release/cudaRC")

int main() {
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in server;
    char server_reply[2000];
    struct ae2f_Dynamic srvrply = { server_reply, 2000 };
    int recv_size;

    ae2f_cudaRC_startup(&wsaData);
    ae2f_cudaRC_initSock(s);

    // Host
#define port 8080
#define serverIP "127.0.0.1"

    ae2f_cudaRC_address(&server, serverIP, port);
    ae2f_cudaRC_connect(s, server);

    printf("Connected to the server.\n");

    struct ae2f_Dynamic valueSuggestion = { (void*)"Thing", 5 };

    ae2f_cudaRC_sendSet(s, &server, "keyTest234", &valueSuggestion);

    printf("Transmission completed.\n");

    if ((recv_size = ae2f_cudaRC_recv(s, (sockaddr*)&server, &srvrply)) == SOCKET_ERROR) {
        printf("?");
        return 1;
    }

    printf("Received value:\n");
    printf("%.*s\n", recv_size, server_reply);

    // Closing the socket
    ae2f_cudaRC_closeSock(s);

    // Terminating WinSock
    ae2f_cudaRC_done;

    return 0;
}
```