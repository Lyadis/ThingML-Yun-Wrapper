CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = Test.c LinuxSerial.c Bridge.c TestCfg.c runtime.c
OBJS = Test.o LinuxSerial.o Bridge.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg