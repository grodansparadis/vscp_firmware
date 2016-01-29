/**
 * @brief           TCP Module for Modtronix TCP/IP Stack
 * @file            tcp.h
 * @author          <a href="www.modtronix.com">Modtronix Engineering</a>
 * @dependencies    stacktsk.h
 * @compiler        MPLAB C18 v2.10 or higher <br>
 *                  HITECH PICC-18 V8.35PL3 or higher
 * @ingroup         mod_tcpip_base_tcp
 *
 *
 * @section description Description
 **********************************
 * This module contains the TCP code.
 * <br>For a detailed description, see the @ref mod_tcpip_base_tcp section of this document - in 
 * [Modules] [TCP/IP Stack] [TCP/IP Base Protocols].
 *
 *
 * @subsection tcp_conf Configuration
 *****************************************
 * The following defines are used to configure this module, and should be placed
 * in the projdefs.h (or similar) file.
 * For details, see @ref mod_conf_projdefs "Project Configuration".
 * To configure the module, the required
 * defines should be uncommended, and the rest commented out.
 @code
 //*********************************************************************
 //-------------------- TCP Configuration --------------------
 //*********************************************************************
 //Maximum number of times a connection be retried before closing it down.
 #define TCP_MAX_RETRY_COUNTS    (3)

 //TCP Timeout value to begin with.
 #define TCP_START_TIMEOUT_VAL   ((TICK)TICK_SECOND * (TICK)60)

 //Define ports
 #define TCP_LOCAL_PORT_START_NUMBER (1024)
 #define TCP_LOCAL_PORT_END_NUMBER   (5000)

 //When defined, the code will be compiled for optimal speed. If not defined, code is defined for smallest size.
 #define TCP_SPEED_OPTIMIZE
 @endcode
 *********************************************************************/

 /*********************************************************************
 * Software License Agreement
 *
 * The software supplied herewith by Modtronix Engineering is based on v2.20.04.01
 * of the Microchip TCP/IP stack. The original code base is owned by Microchip
 * Technology Incorporated (the Company), and is protected under applicable
 * copyright laws. The modifications are owned by Modtronix Engineering, and is
 * protected under applicable copyright laws. The software supplied herewith is
 * intended and supplied to you, the Company customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller based products manufactured
 * by Modtronix Engineering. The code may be modified and can be used free of charge
 * for non commercial and commercial applications. All rights are reserved. Any use
 * in violation of the foregoing restrictions may subject the user to criminal
 * sanctions under applicable laws, as well as to civil liability for the breach
 * of the terms and conditions of this license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN 'AS IS' CONDITION. NO WARRANTIES, WHETHER EXPRESS,
 * IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE
 * COMPANY SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 **********************************************************************
 * File History
 *
 * 2001-05-8, Nilesh Rajbharti:
 *    - Original
 * 2002-05-22, Nilesh Rajbharti:
 *    - Rev 2.0 (See version.log for detail)
 * 2005-09-01, David Hosken (DH):
 *    - Created documentation for existing code
 *********************************************************************/


/////////////////////////////////////////////////
//  TCP - documentation module
/**
@defgroup mod_tcpip_base_tcp TCP
@ingroup mod_tcpip_base
The TCP layer of the Modtronix TCP/IP stack is implemented by the file "tcp.c". The header
file "tcp.h" defines the services provided by the layer. In this stack architecture, TCP is an
active layer. It fetches TCP packets and responds to the remote host according to the TCP state
machine. The TCP module is also implemented as a cooperative task, performing automatic operations
without the knowledge of the main application.

"tcp.h" provides TCP socket services and hides all TCP packet handling from the caller. The layer
allows from 2 to 253 TCP sockets, the number limited only by available memory and compiler used. With
more than one socket, higher level applications can maintain multiple simultaneous TCP connections
and there could be more than one application using this layer. This facility is useful when HTTP Server
is used. It is important to know that each socket consumes approximately 36 bytes (check source file
for actual consumption) and increases overall TCP processing time.

Unlike other TCP/IP implementations, all sockets in the Modtronix TCP/IP Stack share one or more common
transmit buffers. This approach reduces overall RAM requirements, but it may create a potential problem,
where a few sockets reserve all available transmit buffers and do not release them on time for other
sockets to use. Under these circumstances, remote hosts and/or local applications would not be able to
contact the stack. To avoid this, users must make sure that there are enough transmit buffers for all
sockets. On the receive side, there is only one receive buffer. If a socket receives its data, the owner
of that socket must fetch and discard the receive buffer in one task time in order for the other sockets
to receive their data. This design mandates that once a task detects a packet it is interested in, it
must consume the complete packet in one task time. A task cannot fetch part of a packet during one task
time and expect to fetch the rest of the packet later.

As required by TCP specifications, each TCP segment contains a checksum that covers the entire TCP packet,
including the data area. To reduce RAM requirements, the TCP layer uses the MAC buffer in the NIC as
storage and performs the checksum calculation in the MAC buffer itself. If the NIC is used as a MAC, the
NIC SRAM is used as a buffer space. But if SLIP is used as a MAC, the microcontrollerÆs internal data
RAM is used.

The TCP layer of the Modtronix TCP/IP Stack implements most of the TCP state machine states proposed by
RFC793. It also implements automatic retry and timed operations, which users can enable or disable by
the compile time definition TCP_NO_WAIT_FOR_ACK. When automatic retry is enabled, each socket transmit
buffer is reserved until an acknowledgement from the remote host is received. This design effectively
creates a transmit window of one TCP segment. Thus, data throughput would be considerably lower than
that in "No Retry" mode. If only the HTTP Server application is used, the user may disable automatic
retry and effectively increase throughput. If the main applicationÆs logic requires that each packet
be acknowledged before a new one can be transmitted, the user should enable the "Automatic Retry" mode.
With Automatic Retry enabled, some opened connections may not get served on time, and the remote host
may get time-out or RESET errors.


@section mod_tcpip_user_tcp_conf Configuration
For details on configuring this module, see @ref tcp_conf section of tcp.h file.
*/

#ifndef TCP_H
#define TCP_H

#include "net\ip.h"
#include "net\tick.h"

/** A TCP socket. Is a number from 0-255 that identifies a TCP socket */
typedef BYTE TCP_SOCKET;

/**
 * Maximum number of times a connection be retried before
 * closing it down.
 */
#if !defined(TCP_MAX_RETRY_COUNTS)      //To change this default value, define it in projdefs.h
#define TCP_MAX_RETRY_COUNTS    (3)
#endif

/**
 * TCP Timeout value to begin with.
 */
#if !defined(TCP_START_TIMEOUT_VAL)     //To change this default value, define it in projdefs.h
#define TCP_START_TIMEOUT_VAL   ((TICK16) ((TICK16)TICKS_PER_SECOND * (TICK16)60) )
#endif

#if !defined(TCP_LOCAL_PORT_START_NUMBER)   //To change this default value, define it in projdefs.h
#define TCP_LOCAL_PORT_START_NUMBER (1024)
#endif

#if !defined(TCP_LOCAL_PORT_END_NUMBER)     //To change this default value, define it in projdefs.h
#define TCP_LOCAL_PORT_END_NUMBER   (5000)
#endif

#define INVALID_SOCKET      (0xfe)
#define UNKNOWN_SOCKET      (0xff)

#define REMOTE_HOST(s)      (TCB[s].remote)


/**
 * TCP States as defined by rfc793
 */
typedef enum _TCP_STATE
{
    TCP_CLOSED,     ///< RFC793 CLOSED
    TCP_LISTEN,     ///< RFC793 LISTEN
    TCP_SYN_RCVD,   ///< RFC793 SYN-RECEIVED
    TCP_SYN_SENT,   ///< RFC793 SYN-SENT
    TCP_EST,        ///< RFC793 ESTABLISHED
    TCP_FIN_WAIT_1, ///< RFC793 FIN-WAIT-1
    TCP_CLOSING,    ///< RFC793 CLOSING
    TCP_TIMED_WAIT, ///< RFC793 TIME-WAIT
    TCP_SEND_RST,
    TCP_DATA_READY,
    TCP_LAST_ACK,   ///< RFC793 LAST-ACK
    TCP_CLOSE,      
    TCP_INVALID
} TCP_STATE;

/**
 * Socket info.
 * Union is used to create anonymous structure members.
 */
typedef struct _SOCKET_INFO
{
    TCP_STATE smState;		//1 byte

    NODE_INFO remote;		//10 bytes
    WORD localPort;		    //2 bytes
    WORD remotePort;	    //2 bytes

    BUFFER TxBuffer;		//1 byte
    WORD TxCount;			//2 bytes
    WORD RxCount;			//2 bytes - Length of TCP Data (NOT including header, only data) that still has to be read

    DWORD SND_SEQ;			//4 bytes
    DWORD SND_ACK;			//4 bytes

    BYTE RetryCount;		//1 byte
    TICK16 startTick;   	//2 bytes
    TICK16 TimeOut;			//2 bytes

    struct
    {
        unsigned int bServer        : 1;
        //
        unsigned int bIsPutReady    : 1;
        //Indicates that the first byte of the TCP Data has to be read. This is the first byte after the TCP header
        unsigned int bFirstRead     : 1;
        //Only one TCP socket will ever have this flag set at a given time. This indicates that the
        //MAC RX Ring Buffer pointer is currently set to this socket's packet. Any function that
        //reads the MAC RX Ring Buffer, will read data from this socket's packet.
        unsigned int bIsGetReady    : 1;
        //Is set as soon as the TCPPut() or TCPPutArray() functions is called for a socket, cleared when flushed
        unsigned int bIsTxInProgress : 1;
    } Flags;				//1 byte

} SOCKET_INFO;	//34 bytes


#if !defined(THIS_IS_TCP)
/**
 * These are all the sockets supported by this TCP.
 */
extern SOCKET_INFO TCB[MAX_SOCKETS];
#endif


/**
 * Initialize all socket info.
 * This function is called only one during lifetime of the application.
 */
void TCPInit(void);


/**
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param port      A TCP port to be opened.
 *
 * @return          Given port is opened and returned on success
 *                  INVALID_SOCKET if no more sockets left.
 */
TCP_SOCKET TCPListen(WORD port);


/**
 * By default this function is not included in source. You must define
 * STACK_CLIENT_MODE to be able to use this function.
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param remote    Remote node address info
 * @param port      remote port to be connected.
 *
 * @return          A new socket is created, connection request is
 *                  sent and socket handle is returned.
 */
TCP_SOCKET TCPConnect(NODE_INFO *remote, WORD port);


/**
 * A socket is said to be connected if it is not
 * in LISTEN and CLOSED mode.  Socket may be in
 * SYN_RCVD or FIN_WAIT_1 and may contain socket data.
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         Socket to be checked for connection.
 *
 * @return          TRUE    if given socket is connected<br>
 *                  FALSE   if given socket is not connected.
 */
BOOL TCPIsConnected(TCP_SOCKET s);


/**
 * A disconnect request is sent for given socket.
 *
 * @preCondition    TCPInit() is already called AND<br>
 *                  TCPIsPutReady(s) == TRUE
 *
 * @param s         Socket to be disconnected.
 */
void TCPDisconnect(TCP_SOCKET s);


/**
 * Each socket maintains only one transmit buffer. Hence until a data packet
 * is acknowledeged by remote node, socket will not be ready for next transmission.
 * All control transmission such as Connect, Disconnect do not
 * consume/reserve any transmit buffer. This function will check:
 * - If the given socket is valid, is not equal to INVALID_SOCKET for example
 * - If there is an available TX Buffer for writing data to via TCPPut() and TCPPutArray() functions.
 * - If the given socket is ready for transmission
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         socket to test
 *
 * @return          TRUE if socket 's' is free to transmit, and it is a valid socket<br>
 *                  FALSE if socket 's' is not free to transmit, or an invalid socket was given.
 */
BOOL TCPIsPutReady(TCP_SOCKET s);


/**
 * Returns the maximum size the TCP data is allowed to be. This value should never be execeed when
 * writting data to the TCP transmit buffer before calling TCPFlush().
 * For slip:
 *  = MAC_TX_BUFFER_SIZE - sizeof(IP_HEADER) - sizeof(TCP_HEADER)
 *  = MAC_TX_BUFFER_SIZE - 20 - 20 = MAC_TX_BUFFER_SIZE - 40
 * For RTL MAC
 *  = MAC_TX_BUFFER_SIZE - SIZEOF_MAC_HEADER - sizeof(IP_HEADER) - sizeof(TCP_HEADER)
 *  = MAC_TX_BUFFER_SIZE - 14 - 20 - 20 = MAC_TX_BUFFER_SIZE - 54
 */
#define SIZEOF_MAC_HEADER 14
#if defined(STACK_USE_SLIP)
    #define TCPGetMaxDataLength() (MAC_TX_BUFFER_SIZE - sizeof(IP_HEADER) - sizeof(TCP_HEADER))
#else
    #define TCPGetMaxDataLength() (MAC_TX_BUFFER_SIZE - SIZEOF_MAC_HEADER - sizeof(IP_HEADER) - sizeof(TCP_HEADER))
#endif


/**
 * Write the given byte to the given socket's transmit buffer.
 * The data is NOT sent yet, and the TCPFlush() function must be called
 * to send all data contained in the transmit buffer.
 *
 * @preCondition    TCPIsPutReady() == TRUE
 *
 * @param s         socket to use
 * @param byte      a data byte to send
 *
 * @return          TRUE if transmit buffer is still ready to accept more data bytes <br>
 *                  FALSE if transmit buffer can no longer accept any more data byte.<br>
 *                  If FALSE is returned, then TCPIsPutReady() has to be called again before
 *                  calling TCPPut() or TCPPutArray() functions!
 */
BOOL TCPPut(TCP_SOCKET s, BYTE byte);


/**
 * Given number of data bytes from the given array are put into the given socket's
 * transmit buffer. The data is NOT sent yet, and the TCPFlush() function must be called
 * to send all data contained in the transmit buffer.
 *
 * If there is not enough space in the transmit buffer for all the data, the contents of
 * the transmit buffer will be sent, and this function will return the actual amount of
 * bytes that were sent. In this case, it is VERY IMPORTANT to call the TCPIsPutReady()
 * function again before calling the TCPPut() or TCPPutArray() functions! This will however
 * only happen if the transmit buffer fills up. The transmit buffer for TCP data is
 * = (MAC_TX_BUFFER_SIZE - 54), which is usually 970 bytes. If writing less then this to
 * the transmit buffer before calling TCPFlush(), then this function will always return the
 * requested number of bytes!
 *
 * @preCondition    TCPIsPutReady() == TRUE
 *
 * @param s         socket to use
 * @param[in] buffer Buffer containing data that has to be sent.
 * @param count     Number of bytes to send
 *
 * @return          TRUE if transmit buffer is still ready to accept more data bytes <br>
 *                  FALSE if transmit buffer can no longer accept any more data byte.<br>
 *                  If FALSE is returned, then TCPIsPutReady() has to be called again before
 *                  calling TCPPut() or TCPPutArray() functions!
 */
BOOL TCPPutArray(TCP_SOCKET s, BYTE *buffer, WORD count);

/**
 * All and any data associated with this socket
 * is marked as ready for transmission.
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         Socket whose data is to be transmitted.
 *
 * @return          TRUE is action was performed <br>
 *                  FALSE if not
 */
BOOL TCPFlush(TCP_SOCKET s);


/**
 * A socket is said to be "Get" ready when it has already received some data.
 * Sometime, a socket may be closed, but it still may contain data.
 * Thus in order to ensure reuse of a socket, caller must make sure that it reads
 * a socket, if it is ready. This function also checks that the given socket is
 * valid, is not equal to INVALID_SOCKET for example
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         socket to test
 *
 * @return          TRUE if socket 's' contains any data.<br>
 *                  FALSE if socket 's' does not contain any data.
 */
BOOL TCPIsGetReady(TCP_SOCKET s);


/**
 * This function reads the next byte from the current TCP packet.
 * Reads a single byte from the given socket into the given byte pointer
 *
 * @preCondition    TCPInit() is already called     AND
 *                  TCPIsGetReady(s) == TRUE
 *
 * @param s         socket
 * @param byte      Pointer to a byte.
 *
 * @return          TRUE if a byte was read.
 *                  FALSE if byte was not read.
 */
BOOL TCPGet(TCP_SOCKET s, BYTE *byte);


/**
 * Read the requested number of bytes from the given socket into the given buffer.
 *
 * @preCondition    TCPInit() is already called AND <br>
 *                  TCPIsGetReady(s) == TRUE
 *
 * @param s         socket
 * @param[in] buffer Buffer to hold received data.
 * @param count     Buffer length
 *
 * @return          Number of bytes loaded into buffer.
 */
WORD TCPGetArray(TCP_SOCKET s, BYTE *buffer, WORD count);


/**
 * Discard any data contained in the given socket's receive buffer.
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         socket
 *
 * @return          TRUE if socket received data was discarded <br>
 *                  FALSE if socket received data was already discarded
 */
BOOL TCPDiscard(TCP_SOCKET s);


/**
 * Performs TCP tasks.
 *
 * @preCondition    TCPInit() is already called AND <br>
 *                  TCP segment is ready in MAC buffer
 *
 * @param remote    Remote node info
 * @param localIP   Local IP address
 * @param len       Total length of TCP semgent.
 *
 * @return          TRUE if this function has completed its task <br>
 *                  FALSE otherwise
 */
BOOL TCPProcess(NODE_INFO *remote, IP_ADDR *localIP, WORD len);


/**
 * Each socket FSM is executed for any timeout situation.
 * 
 * @preCondition    TCPInit() is already called.
 */
void TCPTick(void);


/**
 * Returns a pointer to the SOCKET_INFO structure for the given socket.
 *
 * @preCondition    TCPInit() is already called.
 *
 * @param s         socket
 *
 * @return          Returns a pointer to the SOCKET_INFO structure for the given socket.
 */
SOCKET_INFO* TCPGetSocketInfo(TCP_SOCKET s);

#endif
