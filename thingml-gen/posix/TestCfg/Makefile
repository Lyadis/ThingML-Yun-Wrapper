CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = Bridge.c Test.c LinuxSerial2.c TestCfg.c runtime.c
OBJS = Bridge.o Test.o LinuxSerial2.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg