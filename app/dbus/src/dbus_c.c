#include <dbus/dbus.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
int db_send(DBusConnection *dbconn, char *word)
{
    DBusMessage *dbmsg;
    int i;
 
    dbmsg = dbus_message_new_signal("/client/signal/Object", // object name of the signal
                                  "client.signal.Type",      // interface name of the signal
                                  "Test");                   // name of the signal
    if (!dbmsg) {
        return -1;
    }
 
    if (!dbus_message_append_args(dbmsg, DBUS_TYPE_STRING, &word, DBUS_TYPE_INVALID)) {
        return -1;
    }
 
    if (!dbus_connection_send(dbconn, dbmsg, NULL)) {
        return -1;
    }
    dbus_connection_flush(dbconn);
    printf("send message %s\n", word); 
    dbus_message_unref(dbmsg);
    return 0;
}
 
int main(int argc, char *argv[])
{
    DBusError dberr;
    DBusConnection *dbconn;
    int i;
    char *msg=NULL;
 
    if ( argc < 2 )
        msg = argv[0];
    else
        msg = argv[1];

    dbus_error_init(&dberr); 
    dbconn = dbus_bus_get(DBUS_BUS_SESSION, &dberr);
    if (dbus_error_is_set(&dberr)) {
        return -1;
    }
 
    db_send(dbconn, msg); 
    dbus_connection_unref(dbconn);
 
    return 0;
}
