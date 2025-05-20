# FIAP - Faculdade de Informática e Administração Paulista 

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# 🌾Projeto Cap 1 - Construindo uma máquina agrícola🌾

---

## 👨‍🎓 Integrantes e Responsabilidades:

| Nome Completo                     | RM        |
|----------------------------------|-----------|
| Daniele Antonieta Garisto Dias  | RM565106  |
| Leandro Augusto Jardim da Cunha | RM561395  |
| Luiz Eduardo da Silva           | RM561701  | 
| Vanessa Teles Paulino           | RM565180  | 
| João Victor Viana de Sousa      | RM565136  |

---

## 👩‍🏫 Professores:
### Tutor(a) 
- <a>Leonardo Ruiz Orabona</a>
### Coordenador(a)
- <a>Andre Godoi Chiovato</a>

---

## 🎯 Introdução e Objetivo

Funcionamento de sensores agrícolas em um sistema montado na plataforma Wokwi.com.
O controle geral do sistema será realizado por um microcontrolador ESP32, responsável por receber os dados dos sensores e controlar a bomba de irrigação, representada por um relé. O relé poderá ser ligado ou desligado automaticamente de acordo com a lógica criada pelo grupo, e seu status será indicado por um LED embutido (ligado = irrigação ativa, desligado = inativa

- Sensor umidade
![Logo do Projeto](SensorUmidade/assets/imagem.png)

- Sensor potássio
![Logo do Projeto](SensorPotassio/assets/imagem.png)

- Sensor fosforo
![Logo do Projeto](SensorFosforo/assets/imagem.png)

- Sensor de luminosidade
![Logo do Projeto](SensorLuminosidade/assets/imagem.png)

### Regras de Negócio

-   Sensores registram leituras a cada 15 minutos, armazenadas em `TBL_MONITORAMENTO`.
-   O sistema compara leituras com valores mínimo/máximo definidos em `TBL_CULTURA_PRODUTO_SENSOR_CONFIGURACAO` para sugerir ajustes.
-   Aplicações de água ou nutrientes são registradas em `TBL_APLICACAO_MONITORAMENTO` apenas quando as leituras estão fora dos limites ideais.

---

## 🔗 Link para o Repositório

https://github.com/LandoAugusto/Fiap_Fase_3_Maquina_Agricola_SENSORES.git
