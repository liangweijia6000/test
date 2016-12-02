OBJS = client.o
CC = g++
client:$(OBJS)
	$(CC) $(OBJS) -g -o client
client.o:client.cpp client.h
	$(CC) -c $< -g -o client.o -g

.PHONY:clean
clean:
	rm *.o client
