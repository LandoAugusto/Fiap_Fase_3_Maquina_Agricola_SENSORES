#include <Arduino.h>
#include "DHT.h"
#define buttonPin 22  // Pino GPIO conectado ao push button
#define ledPin 17      // Pino GPIO conectado ao LED (ou outro dispositivo)
#define codigoCulturaProdutoSensor 15   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR
#define numeroSerie 19   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // Configura o pino do botão como entrada com pull-up interno
    pinMode(ledPin, OUTPUT);           // Configura o pino do LED como saída
    Serial.begin(9600);                // Inicia a comunicação serial
}

void loop() {
    int buttonState = digitalRead(buttonPin);  // Lê o estado do botão
    if (buttonState == LOW) {  // O botão está pressionado (pino conectado ao GND)
        digitalWrite(ledPin, HIGH);  // Liga o LED
        Serial.println("Botão pressionado!");
         // TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,umidade, numeroSerie, getadate() )
        // Gravar os daos medidos na tabela monitoramento/
        Serial.println(" Gravar os daos medidos na tabela monitoramento");
        Serial.println("TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,vlr_medido, dt_medicao, numeroSerie, getadate() )");        
    } else {  // O botão não está pressionado (pino em estado HIGH)
        digitalWrite(ledPin, LOW);   // Desliga o LED
    }   

    delay(50);  // Pequeno atraso para evitar ruído de contato (debounce)
}