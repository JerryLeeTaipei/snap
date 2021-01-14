dbus_c.o: dbus_c.c
	gcc -Wall -c $< `pkg-config --cflags dbus-1`

dbus_c: dbus_c.o
	gcc dbus_c.o -o dbus_c `pkg-config --libs dbus-1`

install: dbus_c
	cp $< $(DESTDIR)$(PREFIX)/dbus_c
