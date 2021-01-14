export $(dbus-launch)

dbus_s.o: dbus_s.c
	gcc -Wall -c $< `pkg-config --cflags dbus-1`

dbus_s: dbus_s.o
	gcc dbus_s.o -o dbus_s `pkg-config --libs dbus-1`

install: dbus_s
	cp $< $(DESTDIR)$(PREFIX)/dbus_s
