# What are we about?
This project's vision is to enable folks to enjoy their aquariums by creating an easy to use automation platform on which the community can add/update modules.  

The code and documentation are to be 100% open-source.  Submissions are to be done via Pull Requests so we can ensure consistency.  

No decision on license yet, but if you wish to use this as a foundation for a business, go ahead!  As a responsible citizen you would, of course, contribute back in the same manner with which this project was given.  Right? :)

## Terminology
* Sensor package - A sensor/actuator sub-system run by a microcontroller; input/output conforms to data standards.
* Data standards - TBD, but essentially a way of ensuring that the system remains easy to customize/add to.  e.g. JSON formats for input/output data, keepalive data.  e.g. the format of a submitted sensor package.

## Planned features:
* Node-red building system
* Pluggable architecture (pick the sensor packages you want to use)
* Communication to the outside world
* Dashboard system (Grafana?  something else?)

ThePlantedTank.net thread where I'll post updates: http://www.plantedtank.net/forums/20-diy/1069681-full-tank-automation-system.html

# What we are not
As of now, the project's border stops at MQTT.  Eventually we hope to also provide schematics/BOMs/Arduino code/etc for the sensor packages. 

As a consumer of this system, you would be responsible for:
* Building the sensor packages 
* Ensuring your sensor packages follow the standards laid out here (e.g. JSON format)
* Ensuring your sensor packages can communicate with the core system

# Some systems we'll be working to automate:
* Water change & top-off
* Automated temperature control
* PWM digital control of LED lighting
* Fully automatic CO2 injection
* Automated system shutdown based on sensor input
* Data gathering/analysis
* Alerting/notifying via SMS/email

# Latest diagram...
![Alt text](/drawIO/Aquarium.png?raw=true "Latest diagram...")
