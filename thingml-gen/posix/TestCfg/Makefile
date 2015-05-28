CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = Bridge.c LinuxSerial.c Test.c TestCfg.c runtime.c
OBJS = Bridge.o LinuxSerial.o Test.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg