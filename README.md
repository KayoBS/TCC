# TCC
## Do que se trata este trabalho?
## Requerimentos de Hardware
## Requerimentos de Software

## Instalação
### Clonar o repositório
Para baixar este repositório, use o comando a seguir:
```git clone https://github.com/kayobs/TCC```

### Configuração das credenciais
É necessário ir para o arquivo ```./code/security_credentials/credentials.h``` e mudar os campos necessários para se conectar à internet e ao ThingSpeak

### Formatação projeto
O avrdude não foi projetado para compilar código em diferentes pastas com arquiteturas de sistema mais complexas. Ao invés disso, ele apenas consegue fazer a "linkagem" dos arquivos quando estão todos em uma única pasta e, por isso, é necessário seguir o procedimento que será mostrado logo a seguir. Um detalhe importante é que esse procedimento foi feito pensando em máquinas Linux.
#### Permitir a execução do arquivo ```make.sh```
```chmod +x make.sh```
#### Execução do comando
```./make.sh```
#### Comando íntegro
```chmod +x make.sh && ./make.sh```
