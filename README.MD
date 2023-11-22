# Shell project for Pico Pi


* USB Serial Read
* USB Serial Write
* GPIO


Set baud rate for echo
`stty -F /dev/ttyACM0 115200`

`echo -e "Hello, Pico\n" > /dev/ttyACM0`
