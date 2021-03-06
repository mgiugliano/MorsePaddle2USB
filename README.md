# MorsePaddle2USB

## Receiving and transmitting Morse code through the web

I am currently studying CW, a traditional mode of communication in ham radio that employs Morse code. Learning to make sense of Morse coded audio signals is for me the most difficult part, while sending is considerably easier. Exercising daily is considerably boosting my skills. Recently, attending the excellent (free, online) courses by CW Academy, I discovered by chance these websites:

- https://vail.woozle.org (by Neale Pickett)
- https://hamradio.solutions/vband (by Ham Radio Solutions)
(but see also http://morsecode.me by Burak Kanber)

By means of a web browser, they allow a user to practice sending and receiving of Morse code over the internet, in real time and with real people. Receiving is throuhg the computer speakers (or headphones), while sending is implemented through key presses on the computer keyboard. The first website is the most polished and interesting to me, due to its open-source philosophy (https://github.com/nealey/vail/) and high quality of the overall experience. 

I am in debt with Neale for inspiring me and for his kind availability and suggestions.

## Connecting a proper Morse straight key or paddle to the computer

Both websites suggest the ingenious idea of using a simple microcontroller, emulating a HID (human interface device) keyboad, while reacting to the "button presses" of an external real Morse straight key or Morse paddle. Ham Radio Solutions even sells a small interface (https://hamradio.solutions/vband/) and keeps its Arduino source code open (https://hamradio.solutions/vband/digispark_keyboard/digispark_keyboard.ino) but not its hardware schematics.

On the contrary, the creator of Vail.Woozle.org goes full open-source, as he released on GitHub information and code for building a similar interface.


## Building my own USB interface by using a microcontroller

Having no experience (yet) with the fantastic world of microcontrollers, I decided to give it a go and build my own interface to learn and hav fun. I picked up the Digispark ATTiny85 micro USB development board, because it seemed what Ham Radio Solutions used and it looked easily suited for creating a HID. The microcontroller is widely sold online (eBay, Amazon, Ali Express), and it is originally produced by Digispark (http://digistump.com) that maintains a quite extensive online wiki and documentation. 


## Electronic component parts

While my first eBay order of a Digisparc ATTiny85 (from China) never arrived, I finally bought (and quickly received) the following electronic components from an Italian online store ([[https://www.tancredi.it]]):

- Digispark ATTINY85 micro USB (size:  21 x 18 mm),           2.54 eur 
- Carbon film resistors 1/4W 5% 10 KOhm (20 pieces),          0.3 eur
- 6.35mm female stereo panel-mount jack connector,            0.39 eur
- 2-way horizontal dip switch orizzontale,                    0.68 eur
- 70x90mm, double side copper prototype PCB fiberglass plate, 0.9 eur
- small plastic box (35x58x16mm),                             0.63 eur

Note: I ordered a 2-way dip switch but later found out I did not have enough free ATTiny85 pins to use. 
I ended up using it as a single way switch. Moreover the box I bought was not large enough to mount the jack connector. I ended up spending few more euros and purchasing another female (flying) jack and some stereo audio cable. I assembled and wired everything on a small prototype PCB, cut to share exactly the size of the Digispark. The final result was not the best, but it was my first attempt. Please do not judge on the uncovered shielding of the audio cable: I had to remove the plastic insulation to allow it to bend more to fit in the box. I am not proud of it, ok?! :-)

![](https://github.com/mgiugliano/MorsePaddle2USB/blob/main/photo&circuit/Assembly.png)

##   Schematics

![](https://github.com/mgiugliano/MorsePaddle2USB/blob/main/photo&circuit/Schematics.png)

At least two digital inputs (P0 and P1) are required for my application: one for detecting the state of the left paddle lever closing contact and one for the right lever. From the schematics above, simple pull-down 10kOhm resistors make it possible for the microcontroller to detect closing each contacts on my Morse paddle as ON logic state, leaving it to OFF logic states when the paddle levers are left untouched. Below a picture of my first explorations using a breadboard.

![](https://github.com/mgiugliano/MorsePaddle2USB/blob/main/photo&circuit/Breadboard_firstTest.png)

My original idea was to devote two additional pins of the microcontroller to detect the configuration of the dip switches, thereby allowing me to "select" up to 4 distinct operation mode (i.e. depending on the possible combinations of the two switches). Unfortunately, I discovered that not all pins of the Digispark ATTiny85 could be used as digital inputs, if the USB port is needed for programming or communication, as in my case (i.e. see P3 and P4, http://digistump.com/wiki/digispark/tutorials/basics). If a pull-down resistor was connected to P3 or P4 (and P5 too, for unknown reasons), then the board could not be detected by the Arduino IDE and thus could not be programmed or used to relay Morse commands to the web browser. In fact, I wanted to keep programming my final assembled prototype so I decided to stick to P0, P1, and P2 (for only one of the dip switches).

##   Software

As an exercise, I have tried this time to skip looking at others' code. I ended up not using any (software) debouncing routine and no interrupt. My code works and I did not detect any irregularity in the behavior of the interface during my Morse manipulation. 

I have learned how to measure time and used this to change the "operation mode" of the interface (i.e. remapping the keys to work on one or the other website) at run-time. I simply have to hold one of the lever for several seconds and the event will be detected.

I definitely have to learn more and improve my code. I would be happy to get feedback and criticism. 

Have fun!





