#include<DHT.h> 	   //precisa incluir essa biblioteca no seu projeto para que o sensor funcione.
#define pinoDHT 23     //Pino onde o sensor está conectado
#define modelo DHT22   //Tipo de sensor DHT22
#define codigoCulturaProdutoSensor 1   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR
#define numeroSerie 1   // Identificação do sensor por cultura e produto definido na tabela TBL_CULTURA_PRODUTO_SENSOR

DHT dht(pinoDHT, modelo);

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    float vlr_medido = dht.readHumidity();   
    if (isnan(vlr_medido)) {
        Serial.println("Falha ao ler do sensor DHT!");
        return;
    }
  

    // Obtem a configuração de valor minimo e maximo para o sensor
    // TBL_CULTURA_PRODUTO_SENSOR_CONFIGURACAO    
    float vlr_maximo =  25.0;
    
    if (vlr_medido > vlr_maximo ) {
        Serial.println("Alerta: Temperatura alta!");    
        Serial.print("Umidade: ");
        Serial.print(vlr_medido);
        Serial.print(" %	");
         
        Serial.print("Valor maximo configurado: ");
        Serial.print(vlr_maximo);
        Serial.print(" %	");  
        // TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,umidade, numeroSerie, getadate() )
        // Gravar os daos medidos na tabela monitoramento/
        Serial.println(" Gravar os valor medido na tabela monitoramento");
        Serial.println(" TBL_MONITORAMENTO (cd_cultura_produto_sensor, vlr_medido, cd_usuario_inclusao, dt_inclusao )  Values(codigoCulturaProdutoSensor,umidade, vlr_medido,numeroSerie, getadate() )");
    } else {
        Serial.println("Temperatura dentro do normal.");
    }

    delay(2000);  		//Aguarda 2 segundos antes de ler novamente
}