/**
 * @file main.cpp
 * @brief Lee el valor de un potenciómetro conectado al pin A0 y lo imprime por el Monitor Serial.
 */

#include <Arduino.h>

// Definimos el pin analógico donde conectamos el pin central del potenciómetro.
const int POT_PIN = A0;

// --- Función setup() ---
void setup()
{
    // Inicia la comunicación serial a 9600 baudios.
    // ¡Asegúrate de configurar el Monitor Serial de PlatformIO a esta misma velocidad!
    Serial.begin(9600);
    Serial.println("--- Lector de Potenciómetro Iniciado (0-1023) ---");
}

// --- Función loop() ---
void loop()
{
    // 1. Lectura: Lee el valor del pin analógico (A0).
    //    El Arduino convierte el voltaje de 0V a 5V en un valor digital de 0 a 1023.
    int valorPotenciometro = analogRead(POT_PIN);

    // 2. Impresión: Envía el valor leído al PC a través del puerto serial.
    Serial.print("Valor del Potenciómetro (A0): ");
    Serial.println(valorPotenciometro);

    // 3. Pausa: Espera un momento antes de volver a leer (para no saturar el Monitor Serial).
    delay(100);
}