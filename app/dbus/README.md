
Build:
	$ snapcraft --destructive-mode
	
Install:
	$ sudo snap install dbus-app_0.1_amd64.snap --dangerous
	
Test:
	Execute the following in a new terminal:

        $ snap connect dbus-app:dbus-plug dbus-app:dbus-slot
	$ dbus-app.dbus-s
	
	Execute the following in a new terminal:

	$ dbus-app.dbus-c "Hi Jerry"
		
	You should see the following message in the first terminal window:

	"receive message Hi Jerry"
