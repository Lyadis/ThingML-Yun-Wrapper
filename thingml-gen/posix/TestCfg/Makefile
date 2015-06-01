CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = LinuxSerial.c Test.c Bridge.c TestCfg.c runtime.c
OBJS = LinuxSerial.o Test.o Bridge.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg