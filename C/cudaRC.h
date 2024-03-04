#pragma once

#ifndef _WINSOCK2API_
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#endif // !_WINSOCK2API_

#include <stdint.h>

#pragma region in
#ifndef AE2F
#ifndef AE2F_EXPORT
#define AE2F __declspec(dllimport)
#else
#define AE2F __declspec(dllexport)
#endif // !AE2F_EXPORT
#endif // !AE2F

#ifndef AE2F_UNIT
#define AE2F_UNIT

#ifndef AE2F_CPP_PREFIX
#ifdef AE2F_CPP
#define AE2F_CPP_PREFIX extern "C"
#else
#define AE2F_CPP_PREFIX
#endif // AE2F_CPP
#endif // !AE2F_CPP_PREFIX

union ae2f_Unit {
#define ae2f_Unit_param \
	void* raw; \
	int8_t* bt1; \
	uint8_t* ubt1; \
	int16_t* bt2; \
	uint16_t* ubt2; \
	int32_t* bt4; \
	uint32_t* ubt4; \
	int64_t* bt8; \
	uint64_t* ubt8; \
	int64_t num; \
	uint64_t unum; \
	float* rFloat; \
	double* rDouble; \

	ae2f_Unit_param
};

/// <param name="a">: pretype (const/struct/union/unsigned)</param>
/// <param name="b">: type name</param>
#define ae2f_Unit_v(a, b) union virtual_##b { a b##* p; ae2f_Unit_param }
#endif // !AE2F_UNIT

#ifdef AE2F_UNIT
#ifndef AE2F_DYNAMIC
#define AE2F_DYNAMIC

typedef struct ae2f_Dynamic {
	union ae2f_Unit c;
	uint64_t len;
}*ptr_ae2f_Dynamic;

#endif // !AE2F_CONTAINER_ARRAY
#endif // AE2F_UNIT
#pragma endregion

#ifdef AE2F_PATH_C
#ifndef AE2F_EXPORT
#pragma comment(lib, AE2F_PATH_CPP "/cudaRC")
#endif // !AE2F_EXPORT
#endif // AE2F_PATH_C


#ifndef AE2F_CUDARC_FUN
#define AE2F_CUDARC_FUN
#pragma region defines
/// <param name="a">: Pointer sockaddr_in pure</param>
/// <param name="b">: IP Address</param>
/// <param name="c">: Port</param>
AE2F_CPP_PREFIX AE2F
struct sockaddr_in* ae2f_cudaRC_address(
	struct sockaddr_in* a,
	const char* b,
	u_short c
);

/// <param name="a">: Socket</param>
/// <param name="b">: Server Address</param>
/// <param name="c">: Map Key</param>
/// <param name="d">: Map Value Setter</param>
AE2F_CPP_PREFIX AE2F
int ae2f_cudaRC_sendPack(
	SOCKET a,
	struct sockaddr_in* b,
	const char* c,      // map key
	ptr_ae2f_Dynamic d  // map value
);

/// <param name="a">: Socket</param>
/// <param name="b">: Server Address</param>
/// <param name="c">: Dll Name</param>
/// <param name="d">: Function Name or Pointer</param>
AE2F_CPP_PREFIX AE2F
int ae2f_cudaRC_sendRun(
	SOCKET a,
	struct sockaddr_in* b,
	const char* c,
	const char* d
);

/// <param name="a">: Socket</param>
/// <param name="b">: Server Address</param>
/// <param name="c">: Key name to del</param>
AE2F_CPP_PREFIX AE2F
int ae2f_cudaRC_sendDel(
	SOCKET a,
	struct sockaddr_in* b,
	const char* c
);

/// <param name="a">: Socket</param>
/// <param name="b">: Socket Address</param>
/// <param name="c">: Buffer Receiver</param>
AE2F_CPP_PREFIX AE2F
int ae2f_cudaRC_recv(
	SOCKET a, 
	struct sockaddr* b, 
	ptr_ae2f_Dynamic c
);

/// <param name="a">: Socket Setter   [WSADATA*]</param>
#define ae2f_cudaRC_startup(a) WSAStartup(MAKEWORD(2, 2), ((LPWSADATA)a))

/// <param name="a">: Client Socket     [SOCKET]</param>
/// <param name="b">: Server Address    [struct sockaddr_in*]</param>
/// <param name="c">: Map Key           [const char*]</param>
/// <param name="d">: Map Value Setter  [ptr_ae2f_Dynamic]</param>
#define ae2f_cudaRC_sendSet(a, b, c, d) ae2f_cudaRC_sendPack(((SOCKET)a), ((struct sockaddr_in*)b), ((const char*)c), ((ptr_ae2f_Dynamic)d))

/// <param name="a">: Client Socket     [SOCKET]</param>
/// <param name="b">: Server Address    [struct sockaddr_in*]</param>
/// <param name="c">: Map Key           [const char*]</param>
#define ae2f_cudaRC_sendGet(a, b, c) ae2f_cudaRC_sendPack(((SOCKET)a), ((struct sockaddr_in*)b), ((const char*)c), ((ptr_ae2f_Dynamic)0))

/// <param name="a">: Client Socket [SOCKET]</param>
#define ae2f_cudaRC_initSock(a) (a = socket(AF_INET, SOCK_STREAM, 0))

/// <param name="a">: Client Socket [SOCKET]</param>
#define ae2f_cudaRC_closeSock(a) closesocket((SOCKET)a)

#define ae2f_cudaRC_done WSACleanup()

/// <param name="a">: Socket			[SOCKET]</param>
/// <param name="b">: Socket Address	[struct sockaddr]</param>
#define ae2f_cudaRC_connect(a, b) connect(a, (struct sockaddr*)&b, sizeof(b))
#pragma endregion
#endif // !AE2F_CUDARC_FUN