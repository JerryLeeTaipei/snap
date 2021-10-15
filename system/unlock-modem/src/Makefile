
CFLAGS   += ${INCLUDES}
LDFLAGS  += ${LIBS} 

EXE = mbim-connect

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ 

mbim-connect: mbim-connect.o
	$(info build $@)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(EXE)

install:
	echo "$(PWD)"
	mkdir -p ${SNAPCRAFT_PART_INSTALL}/usr/local/bin
	cp mbim-connect ${SNAPCRAFT_PART_INSTALL}/usr/local/bin/

.PHONY: install clean
