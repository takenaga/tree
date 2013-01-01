CC	= gcc
OBJS	= bt.o compare.o insert.o test.o
RM	= rm

test:	$(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

clean:
	@$(RM) $(OBJS) test

# sub1.o: header.h
