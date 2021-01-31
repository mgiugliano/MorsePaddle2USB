# MorsePaddle2USB

## Training receiving and transmitting Morse code through the web

I am currently studying CW, that is a tradtional mode of communication in ham radio that employs Morse code. Learning to make sense of Morse coded audio signals is for me the most difficult part, while sending is considerably easier. While attending the excellent (free, online) courses by CW Academy, I discovered by chance these websites:

- https://vail.woozle.org
- https://hamradio.solutions/vband
(but see also http://morsecode.me)

By means of the web browser, they allow a user to practice sending and receiving of Morse code over the internet, in real time and with real people. Receiving is throuhg the computer loudspeakers (or headphone), while sending is implemented through key presses on the computer keyboard. The first website is the most interesting to me, due to its open-source philosophy ([[https://github.com/nealey/vail/]]) and high quality of the experience. 


## Connecting a proper Morse straight key or paddle to the computer

Both the first and the second website suggests the ingenious idea of using a simple microcontroller emulating a HID (human interface device) while reacting to the "button presses" of an external Morse straight key or Morse paddle. Ham Radio Solutions even sells a small interface ([[https://hamradio.solutions/vband/]]) and keeps open their Arduino source code, presumably based on Digispark ([[https://hamradio.solutions/vband/digispark_keyboard/digispark_keyboard.ino]]).
The creator of Vail.Woozle.org also released open information and code for building a similar interface.


## Building my own USB interface by using a microcontroller

Having no experience (yet) with the fantastic world of microcontrollers, I decided to give it a go and build my own interface. I have picked up the Digispark ATTiny85 micro USB development board, because it seemed to be easily suited to act as a HID and widely sold online (eBay, Amazon, Ali Express), and originally produced by Digispark ([[http://digistump.com]]). 


## Electronic component parts

While my earlier eBay order from China never arrived, I bought and received the following components from an Italian online store ([[https://www.tancredi.it]]) of electronic components:

- Digispark ATTINY85 micro USB (size:  21 x 18 mm), 2.54 eur 
- Carbon film resistors 1/4W 5% 10 KOhm (20 pieces), 0.3 eur
- 6.35mm female stereo panel-mount jack connector, 0.39 eur
- 2-way horizontal dip switch orizzontale, 0.68 eur
- 70x90mm, double side copper prototype PCB fiberglass plate, 0.9 eur
- small plastic box (35x58x16mm), 0.63 eur


















