SUBDIRS := app/dbus  client  server

all: $(SUBDIRS)

$(SUBDIRS):
	$(info Build the snap $@")
	cd $@; \
	snapcraft --destructive-mode

.PHONY: all $(SUBDIRS)
