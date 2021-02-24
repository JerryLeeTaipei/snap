SUBDIRS := app/dbus app/hardware-observe  client  server

all: $(SUBDIRS)

$(SUBDIRS):
	$(info Build the snap $@")
	cd $@; \
	snapcraft --destructive-mode

.PHONY: all $(SUBDIRS)
