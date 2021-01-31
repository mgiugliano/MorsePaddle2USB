# MorsePaddle2USB

## Receiving and transmitting Morse code through the web

I am currently studying CW, a tradtional mode of communication in ham radio that employs Morse code. Learning to make sense of Morse coded audio signals is for me the most difficult part, while sending is considerably easier. Exercising daily is considerably boosting my skills. Recently, attending the excellent (free, online) courses by CW Academy, I discovered by chance these websites:

- https://vail.woozle.org
- https://hamradio.solutions/vband
(but see also http://morsecode.me)

By means of a web browser, they allow a user to practice sending and receiving of Morse code over the internet, in real time and with real people. Receiving is throuhg the computer speakers (or headphones), while sending is implemented through key presses on the computer keyboard. The first website is the most polished and interesting to me, due to its open-source philosophy ([[https://github.com/nealey/vail/]]) and high quality of the overall experience. 


## Connecting a proper Morse straight key or paddle to the computer

Both websites suggest the ingenious idea of using a simple microcontroller, emulating a HID (human interface device) keyboad, while reacting to the "button presses" of an external real Morse straight key or Morse paddle. Ham Radio Solutions even sells a small interface ([[https://hamradio.solutions/vband/]]) and keeps its Arduino source code open ([[https://hamradio.solutions/vband/digispark_keyboard/digispark_keyboard.ino]]) but not its hardware schematics.

On the contrary, the creator of Vail.Woozle.org goes full open-source, as he released on GitHub information and code for building a similar interface.


## Building my own USB interface by using a microcontroller

Having no experience (yet) with the fantastic world of microcontrollers, I decided to give it a go and build my own interface to learn and hav fun. I picked up the Digispark ATTiny85 micro USB development board, because it seemed what Ham Radio Solutions used and it looked easily suited for creating a HID. The microcontroller is widely sold online (eBay, Amazon, Ali Express), and it is originally produced by Digispark ([[http://digistump.com]]) that maintains a quite extensive online wiki and documentation. 


## Electronic component parts

While my first eBay order of a Digisparc ATTiny 85 (from China) never arrived, I finally bought (and quickly received) the following electronic components from an Italian online store ([[https://www.tancredi.it]]):

- Digispark ATTINY85 micro USB (size:  21 x 18 mm),           2.54 eur 
- Carbon film resistors 1/4W 5% 10 KOhm (20 pieces),          0.3 eur
- 6.35mm female stereo panel-mount jack connector,            0.39 eur
- 2-way horizontal dip switch orizzontale,                    0.68 eur
- 70x90mm, double side copper prototype PCB fiberglass plate, 0.9 eur
- small plastic box (35x58x16mm),                             0.63 eur


##   Schematics

![plot](./photo&schematics/Breadboard_firstTest.png)
![plot](/photo&schematics/Breadboard_firstTest.png)

[alt text](https://github.com/mgiugliano/MorsePaddle2USB/blob/main/photo&circuit/Schematics.png?raw=true)















