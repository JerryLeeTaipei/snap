Build:
	$ snapcraft --destructive-mode
	
Install:
	$ sudo snap install dbus-c_0.1_amd64.snap --dangerous --devmode
	
Test:
	Execute the following in a new terminal:
		$ dbus-c "Hi Jerry"
