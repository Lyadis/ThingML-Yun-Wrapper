CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = LinuxSerial.c Bridge.c Test.c TestCfg.c runtime.c
OBJS = LinuxSerial.o Bridge.o Test.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg