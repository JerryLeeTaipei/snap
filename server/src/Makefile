INC_DBUS = `pkg-config --cflags dbus-1`
LIB_DBUS = `pkg-config --libs dbus-1`

INCLUDES = ${INC_DBUS}
LIBS = ${LIB_DBUS}

CFLAGS   += ${INCLUDES}
LDFLAGS  += ${LIBS}

EXE = dbus_s

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

$(EXE): $(EXE).o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(CC) -o $@ $^ $(LDFLAGS)

install:
	cp $(EXE) $(DESTDIR)$(PREFIX)/

.PHONY: install clean
