# Trabalho 2 - Sistemas Operacionais

O trabalho 2 consiste na implementação de um escalonador de processos por passos largos

---

## Comentários

Trabalho foi desenvolvido na linguagem C, para um ambiente Risc-V, utilizando-se do qemu

Desenvolvido por:

-   Carlos Giovane Neu Nogueira
-   Marco Antonio Duz

---

## Comandos de Código

Comando para iniciar o projeto:
Dentro da pasta xv6-riscv, rodar o comando:

```bash
    make qemu
```

Após executar o make qemu, será aberto o terminal do xv6, onde poderá ser executado os comandos abaixo

Comando para iniciar um programa que cria 4 processos, que se mantem em um loop por um tempo para poder observar o comportamento do escalonador, quando o processo finalizar aparecerá na tela a seguinte mensagem "Hello World":

```bash
    startcode
```

Para mostrar o status dos processos utilizar o comando ctrl+P
Para sair do xv6 utilizar o comando ctrl+A X

---

## Alterações efetuadas

### Makefile:

-   neste arquivo foram acrescentadas as linhas abaixo dentro do UPROGS, para que os arquivos de mesmo nome fossem compilados ao rodar o make qemu

```c
    $U/_code\
    $U/_startcode\
```

### proc.h:

-   Foi adicionado à estrutura (objeto) do processo um atributo que armazena o próximo processo da fila,

```c
int ticket;        //Define o limite máximo de unidades de tempo que o processo pode passar na CPU
int tickets_count; //Conta quantas unidades de tempo o processo já passou na CPU (acumulativo)
```
OBS: no momento da criação de um processo é passado um valor inteiro que definrá o seu tempo máximo de execução na CPU, podendo ser diferente de processo para processe. EX: forkwithticket(20)
### proc.c:

-   Foi adicionado a função que efetua a escolha do processo a ser executado (stride_schedulling):

    -   stride_schedulling: Percorre toda a fila de processos analisando os processos que estão prontos para serem executados, p->state == RUNNABLE, e comparando os mesmos selecionando aquele que tiver o menor tickets_count para ser executado, em caso de empate será seleciona o processo com maior pid

-   Função alterada
    -   Scheduler: O escalonador em si agora antes de executar o processo o mesmo chama a função stride_schedulling() que define o processo que será executado.

### code.c:

-   programa criado para ocupar cpu com um loop vazio, e ao finalizar apresenta mensgaem hello World

### startcode.c:

-   programa criado para inciar 4 processos do code.c
