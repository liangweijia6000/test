OBJS = server.o
CC = g++
client:$(OBJS)
	$(CC) $(OBJS) -o server
client.o:server.cpp server.h
	$(CC) -c $< -o server.o

.PHONY:clean
clean:
	rm *.o server 
