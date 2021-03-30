CC = g++
RECV = recv
RECV_SRC = recv_main.cpp
RECV2 = recv_v2
RECV2_SRC = recv_v2.cpp
SEND = send
SEND_SRC = send_main.cpp
SEND2 = send2
SEND2_SRC = send_main2.cpp
all:
	${CC} -o ${RECV} ${RECV_SRC}
	${CC} -o ${RECV2} ${RECV2_SRC} 
	${CC} -o ${SEND} ${SEND_SRC}
	${CC} -o ${SEND2} ${SEND2_SRC}
clean:
	rm -rf ${RECV}
	rm -rf ${RECV2}
	rm -rf ${SEND}
	rm -rf ${SEND2}
