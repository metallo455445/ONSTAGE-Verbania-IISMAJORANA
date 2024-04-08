/*  Player
* You can play a sound from an SD card using the Player class.
* The sound file need to be 8bit, uncompressed WAV. Follow this
* tutorial to record and prepare your sound correctly:
* http://web.archive.org/web/20150731231913/http://cuartielles.com/verkstad/en/Reference/PrepareWavSound
*
* Or use one of the .wav files in the BoomBox example.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

Player player=Player();

void setup(){
  //Initialize the sound player
  player.begin();
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(7, INPUT);            //ex b = 4
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

bool ascolto()
{
  bool trovato = false;
  bool a, b, c, d;
  a = false;
  b = false;
  c = false;
  d = false;
  while(a == false && b == false && c == false && d == false){
    if(digitalRead(3) == HIGH)
    {
      a = true;
      Serial.println("check a");
      break;
    }
    if(digitalRead(7) == HIGH)            //ex b = 4
    {
      b = true;
      Serial.println("check b");
      break;
    }
    if(digitalRead(5) == HIGH)
    {
      c = true;
      Serial.println("check c");
      break;
    }
    if(digitalRead(6) == HIGH)
    {
      d = true;
      Serial.println("check d");
      break;
    }
    }
    if(a == true){
       player.play("C.wav");
       Serial.println("a");
    }
    if(b == true){
       player.play("G.wav");
       Serial.println("b");
    }
    if(c == true){
      player.play("E.wav");
      Serial.println("c");
    }
    if(d == true){
      player.play("M.wav");
      Serial.println("d");
    }
    return d;
  }
 bool rip = false;
void loop(){
  //play(filename)
  //  filename: filename of the sound stored in SD card
  //        must be a .wav file
  //
  //Play the file named "0.wav" on SD card
  bool t = false;
  if(rip == false)
  {
   
  if(t == false)
  {
    t = ascolto();
    Serial.println("ASCOLTO T: ");
    Serial.print(t);
    }
  if(t == true)
  {
    Serial.println("ARRIVO");
    player.play("1p.wav");
    player.play("2p.wav");
    player.play("3p.wav");
    player.play("4p.wav");
    player.play("N1.wav");
    player.play("risp1.wav");
    player.play("N2.wav");
    player.play("risp2.wav");
    player.play("N3.wav");
    rip = true;
    }
}
}






  
