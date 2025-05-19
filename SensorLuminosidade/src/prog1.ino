#include<DHT.h> 	   //precisa incluir essa biblioteca no seu projeto para que o sensor funcione.
#define pinoLDR 34  		// Pino ADC conectado ao LDR
#define codigoCulturaProdutoSensor 1   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR
#define numeroSerie 11   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR   //precisa incluir essa biblioteca no seu projeto para que o sensor funcione.
void setup() {
    Serial.begin(9600);  	// Inicia a comunicação serial
}

void loop() {
    int vlr_medido = analogRead(pinoLDR);  // Lê o valor analógico do LDR

    // Obtem a configuração de valor minimo e maximo para o sensor
    // TBL_CULTURA_PRODUTO_SENSOR_CONFIGURACAO    
    float vlr_minimo =  10.0;
    float vlr_maximo =  30.0;
     if (vlr_medido < vlr_minimo || vlr_medido > vlr_maximo ) {
        Serial.println("Alerta: Nível de Luz fora dos padrões !");
        Serial.print("Nível de Luz: ");
        Serial.print(vlr_medido);
        Serial.print(" %	");
         
        Serial.print("Valor minimo configurado: ");
        Serial.print(vlr_minimo);
        Serial.print(" %	"); 

        Serial.print("Valor maximo configurado: ");
        Serial.print(vlr_maximo);
        Serial.print(" %	");
        // TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,umidade, numeroSerie, getadate() )
        // Gravar os daos medidos na tabela monitoramento/
        Serial.println(" Gravar os daos medidos na tabela monitoramento");
        Serial.println("TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,umidade, numeroSerie, getadate() )");     
    } else {
        Serial.println("Nível de Luz dentro do normal.");
    }

    delay(500);  // Pequeno atraso para a próxima leitura
}