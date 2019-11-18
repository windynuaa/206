
CFLAG += -lm
CFLAG += -O2

CC := gcc

OBJS += serial.o
OBJS += get_rssi.o

TARGET := serial_test


$(TARGET): $(OBJS) main.o
	$(CC) $^ $(CFLAG) -o $@


serial.o: serial.c
	$(CC) -c $^ $(CFLAG) -o $@
	
main.o: main.c
	$(CC) -c $^ $(CFLAG) -o $@

get_rssi.o: get_rssi.c
	$(CC) -c $^ $(CFLAG) -o $@

clean:
	rm *.o
	rm $(TARGET)

