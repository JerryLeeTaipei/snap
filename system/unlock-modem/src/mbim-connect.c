#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>
#include <fcntl.h> // open function
#include <unistd.h> // close function


static int mbim_proxy_connect(void) {
    int sock;
    struct sockaddr_un addr;
    socklen_t socklen;

    const char *n = "mbim-proxy";
    sock = socket(AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC, 0);

    if (sock == -1) {
        return -1;
    }

    addr.sun_family = AF_UNIX;
    memcpy(addr.sun_path + 1, n, strlen(n));
    addr.sun_path[0] = '\0';
    socklen = offsetof(struct sockaddr_un, sun_path) + strlen(n) + 1;

    if (connect(sock, (struct sockaddr *)&addr, socklen) != 0) {
          printf ("Fail to connect '%s', errno: %d (%s)\n", n, errno, strerror(errno));
            close(sock);
            sock = -1;
    }

    printf("%s('%s') = %d\n", __func__, n, sock);

    return sock;
}

int main(void){
	int rc = -1;

	rc = mbim_proxy_connect();
	if ( rc == -1 )
		printf("mbim_proxy_connect() failed!\n");
	else
		printf("mbim_proxy_connect() connected\n");

	if ( rc > 0 )
		close(rc);

	return 0;

}
