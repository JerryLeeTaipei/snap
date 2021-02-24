
INC_DBUS = `pkg-config --cflags dbus-1`
LIB_DBUS = `pkg-config --libs dbus-1`

INCLUDES = ${INC_DBUS}
LIBS = ${LIB_DBUS}

CFLAGS   += ${INCLUDES}
LDFLAGS  += ${LIBS} 

EXE = dbus_s dbus_c

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ 

dbus_s: dbus_s.o
	$(info build $@)
	$(CC) -o $@ $^ $(LDFLAGS)

dbus_c: dbus_c.o
	$(info build $@)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(EXE)

install:
	cp dbus_s $(DESTDIR)$(PREFIX)/
	cp dbus_c $(DESTDIR)$(PREFIX)/

.PHONY: install clean
