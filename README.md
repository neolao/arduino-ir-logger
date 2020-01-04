Blink
=====

Install Arduino CLI
-------------------

[https://github.com/arduino/arduino-cli](https://github.com/arduino/arduino-cli)

Install core
------------

Check your connected board:
```bash
arduino-cli board list
```
```
Port         Type              Board Name    FQBN              Core
/dev/ttyACM0 Serial Port (USB) Arduino Micro arduino:avr:micro arduino:avr
```

Install the core:
```bash
arduino-cli core install arduino:avr
```

Install dependencies
--------------------

```bash
arduino-cli lib install IRremote
```

Compilation
-----------

```bash
./compile.sh
```

Upload
------

Run the following command and press the reset button:
```bash
./upload.sh /dev/ttyACM0
```

Print serial communication
--------------------------

```bash
./enable-communication.sh /dev/ttyACM0
cat /dev/ttyACM0
```
