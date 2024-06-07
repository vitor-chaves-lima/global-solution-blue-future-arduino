# GLOBAL SOLUTION - BLUE FUTURE (EDGE COMPUTING & COMPUTER SYSTEMS)
## Simulação de controle visual de produtos produzidos/reciclados registrados na Blockchain

### Integrantes:
#### Arthur Cotrick Pagani - RM554510
#### Gabriel Danius Fachetti Barbosa, RM 555747
#### Vitor Chaves de Lima Coelho, RM 557067
#### Profº Flávio Grassi, PF 2013

***

### Componentes utilizados

* 1 Arduino Uno R3
* 1 LCD LiquidCrystal
* 1 Fita de LED Adafruit NeoPixel com 10 LEDs (o tamanho é variável)
* 2 Resistores (330 Ω e 1kΩ)

***

### Detalhes do Projeto

O projeto ReciclaMar visa promover uma maior conscientização das empresas em relação à reciclagem
de seus produtos produzidos em larga escala. Para isso, pensamos em promover um **índice de reciclabilidade**
das empresas, por meio de um sistema de rastreabilidade de resíduos em Blockchain, de forma que, na linha 
de produção de determinada embalagem, um dispositivo IoT é acoplado a tal, este dispositivo possui um token 
armazenado na Blockchain. Depois de finalizado seu ciclo de consumo, quando o produto chega a algum centro 
de reciclagem, por meio da tecnologia de RFID, placas de reconhecimento identificam o token da embalagem, 
que contém suas informações de fabricação e empresa fabricante. Quando estes são identificados, o status 
da embalagem na Blockchain muda para "reciclado" e o **índice de reciclabilidade** da empresa sobe.

Para isso, buscamos desenvolver um sistema ilustrativo simulando o fluxo de controle de
produtos que são produzidos em uma empresa e, posteriormente, reciclados em um centro de
reciclagem.

Assim que um token é digitado no Serial Monitor, ele é "produzido" por uma empresa, representado por um ponto de 
led vermelho na fita de led. Se o usuário digitar um token diferente, produzirá um outro produto, e assim por diante. 

Se o token digitado havia sido produzido anteriormente, isso quer dizer que este foi reconhecido por um centro de reciclagem, 
portanto, seu status muda para "reciclado" e sua cor na fita de led passa a ser verde.

Para contabilizar tudo isso, utilizamos um monitor LCD no projeto, que indica a contagem de quantos produtos foram
produzidos e quantos foram reciclados, indicando também o IRC (Índice de Reciclabilidade) da empresa em questão.

***

### Instruções de uso

1. No TinkerCad, com o código já instalado e todos os circuitos integrados à placa, incie a simulação.
2. Logo que o programa é inicializado, o lcd liga e mostra a quantidade de itens produzidos e reciclados, bem como
o IRC no canto da tela.
3. Digite um token numérico no Serial Monitor, o script identificará o token e o armazerá em um objeto. O lcd indicará
a adição e um led acenderá na cor vermelha representando-o.
4. Caso deseje reciclar esse produto, apenas digite novamente o token do produto criado, o script identificará o objeto que
o possui e mudará seu estado para "reciclado", e o led que o corresponde se tornará verde.
5. Por questões apenas ilustrativas, definimos o limite da criação de produtos para o número de leds da fita, nesse caso, 10,
mas caso haja a necessidade de aumento, apenas trocar o tamanho da fita realizando todas as conexões de fiação corretas, e trocar
a constante NUMPIXELS no começo do código para o número correspondente de leds.

***

### Requisitos
Para o funcionamento de todas as funcionalidades citadas acima, você irá precisar ter as seguintes **bibliotecas**:
* <Adafruit_NeoPixel.h>
* <LiquidCrystal.h>
* <stdlib.h>
* <math.h>
