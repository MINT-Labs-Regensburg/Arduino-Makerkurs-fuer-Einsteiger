/*
Challenge 01: "Hello World" mit dem Arduino - MUSTERLÖSUNG
==========================================================
Ziel: Schreibe ein Programm, das jede Sekunde "Hello, World!" an den Computer sendet.
*/

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello, World!");
    delay(1000);
}