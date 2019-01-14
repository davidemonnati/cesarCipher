CC=gcc

VPATH = src include
HDIR = include

vpath %.c src
vpath %.h $(HDIR)

OBJDIR=obj
CFLAGS  = -g -Wall -I$(HDIR)

all: CC

CC: $(OBJDIR)/cc.o $(OBJDIR)/cipher.o 
	$(CC) $^ $(CFLAGS) -o $@

$(OBJDIR)/%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/cc.o: cc.c cipher.c cipher.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PONY: install uninstall clean

install:
	@echo "Installing cesarCipher..."
	@cp ./CC /usr/local/bin/CC
	@echo "Done" 

uninstall:
	@echo "Uninstalling cesarCipher..."
	@rm /usr/local/bin/CC
	@echo "Done."

clean:
	rm $(OBJDIR)/*.o CC