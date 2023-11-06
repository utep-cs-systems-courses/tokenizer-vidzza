CFLAGS=-g -O3

OBJS = uimain.o tokenizer.o history.o

# first target is built by default
all: tok

# include file dependencies

tok: $(OBJS)
	cc -o tok $(CFLAGS) $(OBJS)


clean:
	rm -f *.o tok

run:tok
	./tok


