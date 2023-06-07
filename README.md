# X6B-iBus
Basic iBus via UART reader for FlySky iBus protocol (X6B Receiver)

Waits until start bytes are captured after being called and saves the iBus frame to an array.

No timers, call as needed.

Can provided full speed updates if left to run free or scaled down where updates are needed 1 to 2 times a second. Avoid short delays of ~1ms - 50ms, this has caused issues for reasons unknown for now.

Call begin(); in setup then use update(); before getRXChannel(x) or getChannelValue(x) to return values of your controller's channels.

Constructor requires the RX pin, uart number, baud rate and # channel to read.

See included example for usage.
