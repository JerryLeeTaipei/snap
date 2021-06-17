README

(1) Install the snap

$ snap install test-snapd-service_1.0_amd64.snap --dangerous

(2) Check the statuts of the snap

$ sudo snap changes
ID   Status  Spawn               Ready               Summary
18   Done    today at 14:39 CST  today at 14:39 CST  Install "test-snapd-service" snap from file "test-snapd-service_1.0_amd64.snap"

(3) List all the services added by that snap:

$ sudo snap services test-snapd-service
Service                                                Startup  Current  Notes
test-snapd-service.test-snapd-endure-service           enabled  active   -
test-snapd-service.test-snapd-other-service            enabled  active   -
test-snapd-service.test-snapd-service                  enabled  active   -
test-snapd-service.test-snapd-service-refuses-to-stop  enabled  active   -
test-snapd-service.test-snapd-sighup-all-service       enabled  active   -
test-snapd-service.test-snapd-sighup-service           enabled  active   -
test-snapd-service.test-snapd-sigterm-all-service      enabled  active   -
test-snapd-service.test-snapd-sigterm-service          enabled  active   -
test-snapd-service.test-snapd-sigusr1-all-service      enabled  active   -
test-snapd-service.test-snapd-sigusr1-service          enabled  active   -
test-snapd-service.test-snapd-sigusr2-all-service      enabled  active   -
test-snapd-service.test-snapd-sigusr2-service          enabled  active   -


(4) Manage services

(4.1)Restarting services:

$ sudo snap restart test-snapd-service

(4.2) Stopping an individual service:

$ sudo snap stop test-snapd-service.ONE_SERVICE_NAME

(4.3) Starting an individual service:

$ sudo snap start test-snapd-service.ONE_SERVICE_NAME

(4.2) Restarting an individual service:

$ sudo snap restart test-snapd-service.ONE_SERVICE_NAME

(4.3) To prevent a service from starting on the next boot, use the --disable option:

$ sudo snap stop --disable  test-snapd-service.ONE_SERVICE_NAME

(4.4) re-enable the automatic starting of a service when the system boots:

$ sudo snap stop --enable  test-snapd-service.ONE_SERVICE_NAME

(5) Inspecting logs

To see the log output for a snap’s services,

$ snap logs test-snapd-service
$ snap logs test-snapd-service.test-snapd-service

Adding the -f option will keep log output open

$ snap logs -f test-snapd-service.test-snapd-service


