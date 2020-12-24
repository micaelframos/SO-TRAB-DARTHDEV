# SO-TRAB2-DARTHDEV

Este repositório possui os códigos desenvolvido pelo grupo "Darth Dev" cujo membros são os alunos Micael Ferreira Ramos e Rudson Henrique Rocha.
Desenvolvemos um programa de envio de mensagens de um ponto A para o B através de um pombo correio. O envio dessas mensagens acontece quando existir 20 mensagens aguardando o envio, a implementação foi realizada com a utilização de threads e semáforos para gestão dos processos.
No arquivo "pombo.c" temos todo o código implementado pelos integrantes, o processo de execução e compilação desse código é simples, basta acessar o diretório /trabProg e executar, informando o nome desejado para o programa:
```
$ gcc main.c -o "nome programa" -pthread
```
```
$ ./"nome programa"
```
Será solicitada a quantidade de usuários que digitará as mensagens, após o preenchimento basta confirmar para que o programa seiga com a compilação.
Além disso, nesse repositório existe duas chaves de acesso para conexão com nossa instância. O arquivo .ppk é para conexões efetuadas via app putty do windows, já o arquivo .pem é a chave gerada pela própria AWS.
