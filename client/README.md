Build:
	$ snapcraft --destructive-mode
	
Install:
	$ sudo snap install dbus-c_0.1_amd64.snap --dangerous
	
Test:
	Execute the following in a new terminal:
                $ snap connect dbus-c:dbus-plug dbus-s:dbus-slot
		$ dbus-c "Hi Jerry"
