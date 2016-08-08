# aquariumAutomation
The goal of this repo is to be home for both the technical documents (diagrams/schematics/bill-of-materials) and the Arduino code to run a fully automatic freshwater aquarium.
ThePlantedTank.net thread where I'll post updates: http://www.plantedtank.net/forums/20-diy/1069681-full-tank-automation-system.html

## Some systems we'll be working to automate:
* Water change & top-off
* Automated temperature control
* PWM digital control of LED lighting
* Fully automatic CO2 injection
* Automated system shutdown based on sensor input
* Data gathering/analysis
* Alerting/notifying via SMS/email

## Latest diagram...
![Alt text](/drawIO/Aquarium.png?raw=true "Latest diagram...")

## Some benefits
* Obviously cost (to a degree) is always a problem.  Any existing systems that give this level of reliability/featureset cost many thousands.
* This system will be designed to be modular/growable/optionally-redundant
* The DIY crowd can have a ton of fun with this - it's open source, community-grown (well, that's the idea)
* This can be as baller or spartan as you want
* I am hoping that we can generate a library of sensor calibration code so in future it'll be a more plug-n-play build process

## Some drawbacks
* I have no idea what I'm doing
* It will be a LOT of work to build this on your own
* Won't be as polished as stuff like Neptune and whatnot
* One of the key tenets is 'use cheap stuff, but make it redundant', so we'll have to make it easy to maintain

# Diagrams
Systems diagrams (draw.io)

# Schematics
Electrial system schematic.

# Bill of Materials
Sensors, relays, controller pieces, etc.

# Controller code
Arduino code (read up on this, seems Arduino is preferred for analog sensor/mechanical systems).
