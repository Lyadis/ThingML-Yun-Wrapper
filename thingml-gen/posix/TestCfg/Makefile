CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = MinTest.c LinuxSerial.c TestCfg.c runtime.c
OBJS = MinTest.o LinuxSerial.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg