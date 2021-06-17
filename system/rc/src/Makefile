
# snapcraft will copy anything from here
INSTALL_DIR := ../install

CFLAGS   += ${INCLUDES}
LDFLAGS  += ${LIBS} 

EXE = hello rc

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ 

rc: rc.o
	$(info build $@)
	$(CC) -o $@ $^ $(LDFLAGS)

hello: hello.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(EXE)

install:
	echo "$(PWD)"
	mkdir -p ${INSTALL_DIR}/bin
	cp rc ${INSTALL_DIR}/bin/
	cp hello ${INSTALL_DIR}/bin/

.PHONY: install clean
