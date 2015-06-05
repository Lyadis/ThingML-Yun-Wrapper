CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = Test.c Bridge.c LinuxSerial2.c TestCfg.c runtime.c
OBJS = Test.o Bridge.o LinuxSerial2.o TestCfg.o runtime.o

all : TestCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

TestCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ TestCfg