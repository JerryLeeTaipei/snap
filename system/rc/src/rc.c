#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>
#include <stdio.h>

#include "lib/pci.h"

extern char **environ;

int lspci(void)
{
  struct pci_access *pacc;
  struct pci_dev *dev;
  unsigned int c;
  char namebuf[1024], *name;

  pacc = pci_alloc();		/* Get the pci_access structure */
  /* Set all options you want -- here we stick with the defaults */
  pci_init(pacc);		/* Initialize the PCI library */
  pci_scan_bus(pacc);		/* We want to get the list of devices */
  for (dev=pacc->devices; dev; dev=dev->next)	/* Iterate over all devices */
    {
      pci_fill_info(dev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);	/* Fill in header info we need */
      c = pci_read_byte(dev, PCI_INTERRUPT_PIN);				/* Read config register directly */
      printf("%04x:%02x:%02x.%d vendor=%04x device=%04x class=%04x irq=%d (pin %d) base0=%lx",
	     dev->domain, dev->bus, dev->dev, dev->func, dev->vendor_id, dev->device_id,
	     dev->device_class, dev->irq, c, (long) dev->base_addr[0]);

      /* Look up and print the full name of the device */
      name = pci_lookup_name(pacc, namebuf, sizeof(namebuf), PCI_LOOKUP_DEVICE, dev->vendor_id, dev->device_id);
      printf(" (%s)\n", name);
    }
  pci_cleanup(pacc);		/* Close everything */
  return 0;
}



int main (int argc, char *argv[])
{
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1){
        perror("rc\n");// error, failed to fork()
    } else if (pid > 0) {// parent
        int status;
        waitpid(pid, &status, 0);
    }else {     // we are the child
        execlp("hello","hello",(char*)NULL);
        _exit(1);   // exec never returns
    }
    setlogmask (LOG_UPTO (LOG_NOTICE));

    openlog ("rc", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog (LOG_NOTICE, "Program started by User %d", getuid ());

    while (1){
        syslog (LOG_NOTICE, "running");
        lspci();
        sleep(15);
    }

    closelog ();
    return 0;
}
