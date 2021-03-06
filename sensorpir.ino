    int ledPin = 13;                // Memilih pin untuk LED
    int inputPin = 2;               // Memilih input pin (untuk sensor PIR)
    int pirState = LOW;             // Kita mulai, dengan asumsi tidak ada gerakan terdeteksi
    int val = 0;                    // Variabel untuk membaca status pin
    int pinSpeaker = 10;            // Mengatur pembicara pada pin PWM (digital 9, 10, atau 11)
    void setup() {
      pinMode(ledPin, OUTPUT);      // Mendeklarasikan LED sebagai output
      pinMode(inputPin, INPUT);     // Mendeklarasikan sensor sebagai input
      pinMode(pinSpeaker, OUTPUT);
      Serial.begin(9600);
    }
    void loop(){
      val = digitalRead(inputPin);  // Membaca nilai masukan
      if (val == HIGH) {            // Memeriksa apakah input adalah TINGGI
        digitalWrite(ledPin, HIGH); // Hidupkan LED ON
        playTone(300, 160);
        delay(150);
       
        if (pirState == LOW) {
          // Kita baru saja diaktifkan
          Serial.println("Motion detected!");
          // Kami hanya ingin mencetak pada perubahan output, tidak menyatakan
          pirState = HIGH;
        }
      } else {
          digitalWrite(ledPin, LOW); // turn LED OFF
          playTone(0, 0);
          delay(300);  
          if (pirState == HIGH){
          // Kita baru saja dimatikan
          Serial.println("Motion ended!");
          // Kami hanya ingin mencetak pada perubahan output, tidak menyatakan
          pirState = LOW;
        }
      }
    }
    // Durasi msecs dalam, hertz Frekuensi
    void playTone(long duration, int freq) {
        duration *= 1000;
        int period = (1.0 / freq) * 1000000;
        long elapsed_time = 0;
        while (elapsed_time < duration) {
            digitalWrite(pinSpeaker,HIGH);
            delayMicroseconds(period / 2);
            digitalWrite(pinSpeaker, LOW);
            delayMicroseconds(period / 2);
            elapsed_time += (period);
        }
    }


