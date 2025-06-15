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

////ARRUMAR DAQUI PRA BAIXO
### proc.h:

-   Foi adicionado à estrutura (objeto) do processo um atributo que armazena o próximo processo da fila,

```c
struct proc \*next;
```

-   Acrescentado a struct procpriority é a estrutura das filas de processos cada uma de uma prioridade

```c
struct procpriority {
    struct proc *head;
    struct proc *tail;
    struct spinlock locked;
};
```

### proc.c:

-   Foram adcionadas as seguintes funções referentes a manutenção das filas de processo:

    -   addToQueue: adiciona um novo processo a fila
    -   ret: Pega a fila da classe sorteada e executa o primeiro processo da fila se o mesmo não for nulo e estiver com o status RUNNABLE
    -   roundRobin: Pega o primeiro processo da fila e joga-o para o fim da fila e encontra o primeiro processo RUNNABLE para manter como head da fila, dentro dela é chamado o ret para executar o processo, passando como parametro o head da fila

-   Função alterada
    -   Scheduler: O escalonador em si agora antes de executar o processo o mesmo chama a função de sorteio lottery_select_class() que define qual fila de classe será escolhido o processo e então efetua a chamada do roundRobin para que o processo seja executado

### code.c:

-   programa criado para ocupar cpu com um loop vazio, e ao finalizar apresenta mensgaem hello World

### startcode.c:

-   programa criado para inciar 4 processos do code.c
