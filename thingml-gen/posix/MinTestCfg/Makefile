CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = LinuxSerial.c test.c MinTestCfg.c runtime.c
OBJS = LinuxSerial.o test.o MinTestCfg.o runtime.o

all : MinTestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

MinTestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ MinTestCfg