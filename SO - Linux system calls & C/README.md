# Sistemas Operativos
![N|Solid](https://slick.pl/wp-content/uploads/2012/06/linux.png)
Sistema Operativo é um programa ou um conjunto de programas cuja função é gerir os recursos do sistema.

  - Type some Markdown on the left
  - See HTML in the right
  - Magic

## Estrutura
Divide-se em duas componentes: User Mode e Kernel Mode.

### Kernel Mode
É responsável por estabelecer uma ligação simples e user-friendly entre o utilizador da máquina e o hardware desta. Por isso, detêm funções básicas e essenciais ao sistema operativo. Oferece serviços como:
  - IO
  - Execução de programas
  - Agendamento de processos
  - Alocação de recursos
  - etc...

### User Mode
É a camada mais superficial. Tem acesso apenas a um conjunto limitado de instruções às quais damos o nome de system calls e que são disponibilizadas pelo kernel. Além disso, programas e interfaces gráficas fazem, habitualmente, também parte deste modo.
As system calls são assim uma forma de comunicação entre o kernel mode e o user mode. Permitem um maior conforto uma vez que é o próprio SO que se responsabiliza por gerir os recursos mas também mantém o sistema e o hardware da máquina seguros a programas intrusivos e invasivos. Ou seja, uma vez que só o sistema operativo é que tem comunicação direta com os componentes físicos, torna-se impossível que um software maliciosa consiga alterar o comportamento do relógio do processador.

## Processos
Um proceso contém a informação sobre um programa que está em execução (registos, variáveis, etc...) para que este possa ser parado e recuperado sempre que seja necessário o que se torna essencial no escalonamento de processos.

### Criação de Processos

##### Inicialização do Sistema
Quando o sistema operativo arranca, são criados alguns processos (daemons na sua maioria). Estes processos são, geralmente, usados para gerir pedidos ou para configuração de hardware e, são executados em plano de fundo/background e não estão associados a nenhum utilizador.

##### System Calls
Novos processos podem ser criados por outros processos. É algo útil quando existe trabalho que pode ser facilmente executado por processos independentes.

##### Pedido do Utilizador
O utilizador pode criar novos processos utilizando uma linha de comandos ou com uma GUI.

##### Batch
Nos sistemas mais clássicos, uma batch era um computador central que tinha a ele ligado vários terminais e era onde os processos ou jobs eram escalonados por uma simples fila de espera. Geralmente, um processo é criada por uma tarefa.
Em Sistemas UNIX, é possível criar um novo processo através da system call: fork().
Quando é invocada esta função, é criado um processo idêntico ao que invocou a função (memória e descritores)... No entanto, cada um dos processos tem o seu próprio espaço de endereçamento o que quer dier que, após o fork(), as modificações não são partilhadas.

### Terminação de Processos

##### Saída normal e de erro | Saídas voluntárias

##### Erro fatal e "kill" | Saídas involuntárias

### Hierarquia de Processos
