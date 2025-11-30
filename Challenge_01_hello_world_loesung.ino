/*
Challenge: "Hello World" mit dem Arduino - MUSTERLÖSUNG
=======================================================
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
