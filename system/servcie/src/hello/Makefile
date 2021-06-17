
# snapcraft will copy anything from here
INSTALL_DIR := ../install

CFLAGS   += ${INCLUDES}
LDFLAGS  += ${LIBS} 

EXE = hello 

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ 

hello: hello.o
	$(info build $@)
	$(CC) -o $@ $^ $(LDFLAGS)


clean:
	rm -f *.o $(EXE)

install:
	echo "$(PWD)"
	mkdir -p ${INSTALL_DIR}/bin
	cp hello ${INSTALL_DIR}/bin/

.PHONY: install clean
