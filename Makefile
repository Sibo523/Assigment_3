
# CC = gcc
# CFLAGS = -Wall
# AR = ar  

# all: StrList mini

# StrList: Main.o libStrList.a
# 	$(CC) $(CFLAGS) -o $@ $^

# libStrList.a: StrList.o
# 	$(AR) -rcs $@ $^

# Main.o: Main.c StrList.h
# 	$(CC) $(CFLAGS) -c $<

# mini:test_StrList.o
# 	$(CC) $(CFLAGS) -o $@ $^

# test_StrList.o:test_StrList.c StrList.h
# 	$(CC) $(CFLAGS) -c $<

# .PHONY: clean all  

# clean:  
# 	rm -f *.o *.a StrList mini

# # all:StrList

# # StrList: Main.o StrList.o
# # 	gcc -Wall Main.o StrList.o -o StrList
# # main.o: Main.c StrList.h
# # 	gcc -Wall -c Main.c
# # StrList.o: StrList.c StrList.h
# # 	gcc -Wall -c StrList.c

# # .PHONY: clean all

# # clean:
# # 	rm *.o StrList
CC = gcc
CFLAGS = -Wall
AR = ar

all: StrList mini

StrList: Main.o libStrList.a
	$(CC) $(CFLAGS) -o $@ $^

libStrList.a: StrList.o
	$(AR) -rcs $@ $^

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c $<

mini: test_StrList.o libStrList.a
	$(CC) $(CFLAGS) -o $@ $^

test_StrList.o: test_StrList.c StrList.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o *.a StrList mini

