# Sistemas Operativos
![N|Solid](https://slick.pl/wp-content/uploads/2012/06/linux.png)

Sistema Operativo é um programa ou um conjunto de programas cuja função é gerir os recursos do sistema.

## Estrutura
Divide-se em duas componentes: User Mode e Kernel Mode.

### Kernel Mode
É responsável por estabelecer uma ligação simples e user-friendly entre o utilizador da máquina e o hardware desta. Por isso, detêm funções básicas e essenciais ao sistema operativo. Oferece serviços como:
  - IO;
  - Execução de programas;
  - Agendamento de processos;
  - Alocação de recursos;
  - etc...

### User Mode
É a camada mais superficial. Tem acesso apenas a um conjunto limitado de instruções às quais damos o nome de system calls e que são disponibilizadas pelo kernel. Além disso, programas e interfaces gráficas fazem, habitualmente, também parte deste modo.
As system calls são assim uma forma de comunicação entre o kernel mode e o user mode. Permitem um maior conforto uma vez que é o próprio SO que se responsabiliza por gerir os recursos mas também mantém o sistema e o hardware da máquina seguros a programas intrusivos e invasivos. Ou seja, uma vez que só o sistema operativo é que tem comunicação direta com os componentes físicos, torna-se impossível que um software maliciosa consiga alterar o comportamento do relógio do processador.

## Processos
Um proceso contém a informação sobre um programa que está em execução (registos, variáveis, etc...) para que este possa ser parado e recuperado sempre que seja necessário o que se torna essencial no escalonamento de processos.
Para armazenar a informação sobre os processos, o SO utiliza uma tabela de processos com uma entrada por processo. Cada entrada tem o nome de "Bloco de controlo de processo" e é uma estrutura necessária para o tal escalonamento uma vez que guarda toda a informação para recuperar a execução de um programa como os valores dos registos, stack pointers, pid, etc...

### Criação de Processos
#### Inicialização do Sistema
Quando o sistema operativo arranca, são criados alguns processos (daemons na sua maioria). Estes processos são, geralmente, usados para gerir pedidos ou para configuração de hardware e, são executados em plano de fundo/background e não estão associados a nenhum utilizador.

#### System Calls
Novos processos podem ser criados por outros processos. É algo útil quando existe trabalho que pode ser facilmente executado por processos independentes.

#### Pedido do Utilizador
O utilizador pode criar novos processos utilizando uma linha de comandos ou com uma GUI.

#### Batch
Nos sistemas mais clássicos, uma batch era um computador central que tinha a ele ligado vários terminais e era onde os processos ou jobs eram escalonados por uma simples fila de espera. Geralmente, um processo é criada por uma tarefa.
Em Sistemas UNIX, é possível criar um novo processo através da system call: fork().
Quando é invocada esta função, é criado um processo idêntico ao que invocou a função (memória e descritores)... No entanto, cada um dos processos tem o seu próprio espaço de endereçamento o que quer dier que, após o fork(), as modificações não são partilhadas.

### Terminação de Processos

#### Saída normal e de erro | Saídas voluntárias
Um processo termina com invocação da system call exit(...). Esta recebe um inteiro como argumento... Por convenção, quando um processo termina bem e normalmente, deve ser passado o 0 nesse parâmetro. De outro modo, na ocorrência de algum erro durante a execução do processo, deve ser devolvido qualquer outro número diferente de 0 para que possa ser recebido e tratado pelo processo pai.

#### Erro fatal e "kill" | Saídas involuntárias
Este tipo de saída sugere o uso de sinais. No caso de erro fatal, os sinais são enviados pelo sistema ao processo normalmente devido a erros e bugs no programa (SiGSEGV -> segmentation fault; SIGFPE -> operação aritmética inválida...). No caso das saídas involuntárias, um sinal pode ser enviado a um processo invocando explicitamente a system call kill(...). Esta recebe dois parâmetros: o pid do processo a matar e o sinal a enviar (ex: SIGKILL).


Apesar de serem essencialmente utilizados para matar processos, a maioria dos sinais podem também ser utilizados como meio de comunicação entre processos.

### Hierarquia de Processos
Em sistemas UNIX existe uma hierarquia de processos. Todos os processos pertencem a uma mesma árvore e cada processo forma um grupo com os processos filho criados e estes ficam sempre associados ao processo pai.
Quando processo pai morre antes dos filhos, estes são herdados pelo processo com pid = 1, init.

#### Estados
**Running** - Quando um processo se encontra neste estado, significa que está a utilizar o CPU;

**Ready** - Neste estado, o processo está à espera que os restantes processos acabem de correr para fazer uso do CPU;

**Blocked** - O processo encontra-se à espera que algo aconteça para poder avançar (ex: esperando input do utilizador).


Para cada estado existe uma fila de espera na qual os processos são colocados à medida que o estado vai alterando. A seleção destes é posteriormente feita pela parte do escalonamento de processos.

### Escalonamento de Processos
Um processo é executado até ter de esperar (normalmente request de I/O).
Num sistema simples, o CPU fica numa espera ativa sem fazer nada e, portanto, desperdiça tempo.
Por exemplo, num sistema de monoprogramação, um processo tem direito ao CPU enquantos os seguintes ficam em espera ativa ou seja, testam consecutivamente se o CPU se encontra livre (o chamado polling)....
A ideia é introduzir multiprogramação, ou seja, utilizar este tempo de forma produtiva. Portanto, vários processos são mantidos na memória ao mesmo tempo e quando um tem de esperar (ex: I/O), o SO tira o CPU desse processo e dá a outro. Isto torna-se contínuo: de cada ve que um processo tem de esperar, o CPU é atribuído a outro processo.

#### Burst-Cycle
Se os processos estão constantemente à espera de I/O, então nesse período não estão a ser feitos cálculos importantes. Porém, quando o processo trata de fazer cálculos, então é mantido a níveis muito reduzidos.
Portanto, o tempo é dividido em bursts de I/O ou de CPU.
O processo faz cálculos (%CPU elevada), precisa de IO (%CPU baixa e a %IO aumenta(, volta aos cálculos...
Os processos com vários burst cycles (mais longos) de CPU chamam-se processos CPU bound enquanto que os processos mais burst cycles (mais longos) de I/O denominam-se I/O bound.

#### Escalonamento
O escalonamento é necessário em quatro situações:
  - Quando um processo muda de running para waiting (ex: request de I/O);
  - Quando um processo muda de running para ready (ex: interrupção);
  - Quando um processo muda de waiting para ready (ex: completou I/O);
  - Quando um processo termina.

No primeiro caso e no último, o escalonamento que é necessário é cooperativo já que não são precisas técnicas adicionais, além do algoritmo de escolhe do próximo processo ao qual será atribuído o CPU. Nos restantes, estes só acontecem se o escalonamento for preemptive.

##### Escalonamento cooperativo vs preemptive
Que decisões é preciso tomar?
  - Qual o próximo processo a executar?
  - Quando começa a executar?
  - Durante quanto tempo executa?

A primeira questão depende única e exclusivamente do algoritmo usado pelo escalonador. No entanto, as restantes dependem se o escalonamento é cooperativo ou preemptive.

Escalonamento preemptive é quando um processo possui o CPU mas este é-lhe retirado pelo sistema operativo para dar a outro processo, sem que o primeiro o tenha explicitamente libertado. A isto chama-se desafetação forçada.

Escalonamento cooperativo permite que um processo execute até, deliberadamente, libertar o CPU (situação 1 e 4). Existem algumas plataformas de hardware que apenas funcionam com este tipo de escalonamento uma vez que não têm CPU timer que é necessário para preemptive.

Por outro lado, o escalonamento cooperativo traz menos custos de manutençào (overhead) já que não é necessário tratar da troca de processos nem de guardar o estado de um processo e portanto, a complexidade do escalonador é assim reduzida.

###### **Vantagens e Desvantagens**

Vantagem do preemptive - podemos manter a correr vários processos e interagir com eles todos...
Desvantagem do preemptive - há um overhead adicional dado que para trocar de processo é preciso preservar o estado. Aumenta também a complexidade do scheduler e do hardware já que é preciso um timer...

Contudo, se o escalonamento não for preemptive, é impossível ter mais do que um processo a correr simultaneamente. Num sistema de janelas como o Windows em que a cada janela está associado um processo seria impossível, por exemplo, manter o Google Chrome aberto e o Spotify.
O MS-DOS, até ao Windows 95, usava escalonamento cooperativo. Nessa altura foi então introduzido o preemptive.

##### Critérios de Escalonamento
Os critérios utilizados são os seguintes:
 - Utilização do CPU (ideal entre 40%-90%);
 - Throughput -> número de processos por unidade de tempo... faz a medição de quantos processos consegue concluir;
 - Turnaround time -> tempo desde um processo entra na fila de espera até que sai;
 - Waiting time -> tempo que um processo está na fila de espera de ready;
 - Response time -> tempo desde que o processo é submetido até obtermos a primeira resposta.

##### Algoritmos de Escalonamento

###### First Come, First Served (FIFO)
 - Fácil de codificar;
 - Tempo de espera muito elevado;
 - Favorece os processos CPU bound.
 - Escalonamento cooperativo

###### Shortest-Job-First (SJF)
  - Associam a cada processo uma estimativa do próximo CPU burst;
  - Atribui ao CPU o processo com menor CPU burst. Se for igual, usa-se FCFS;
  - É praticamente ótimo mas é difícil saber a duração do próximo CPU burst;
  - Para longa duração, pode-se usar o process limit que o user submete (os users são convidados a estimar o limite de tempo - se o processo demorar mais que isso tem de ser resubmetido);
  - Não pode ser implementado em short-term CPU scheduling (quando cada burst dura milissegundos) porque não há maneira de saber a duração de bursts muito pequenos;
  - Pode ser cooperativo ou preemptive. No caso de ser o último, é interrompido quando chega um processo com mais prioridade;
  - Conduz a **Starvation**.

###### Preemptive Priority
  - Caso mais geral do SJF;
  - Inteiro atribuído ao processo;
  - Pode ser preemptive ou cooperativo;
  - Tal como o SJF conduz a **Starvation**. Ou seja, um processo com prioridade reduzida pode demorar demasiado tempo a ser corrido. Por exemplo, quando desmontaram o IBM 7094 no MIT em 1973 descobriram um processo de baixa prioridade que ainda não tinha sido corrido e tinha sido submetido 6 anos antes;
  - A solução é atribuir prioridade aos processos mais antigos à medida que o tempo passa.

###### Round Robin
  - Feito para sistemas de partilha de tempo;
  - É semelhante ao FCFS só que tem preemption;
  - É gerado um time quantum (de 10 a 100 milisegundos) e a ready queue torna-se circular. O CPU roda por todos os processos e dá a todos um tempo correspondente a um quantum;

Pode acontecer um de dois casos:
  - O processo acaba antes do fim do quantum sendo que ele próprio liberta o CPU e o escalonador segue para o próximo processo;
  - O quantum chega ao fim e é gerada uma interrupção sendo que o estado do processo é guardado e este é colocado no final da waiting queue;

Se o quantum for elevado, comporta-se como FCFS. Se o quantum for reduzido, o overhead correspondente à troca de processos acaba por tomar conta do CPU e cada processo passa pouco tempo no CPU.
O SJF requer alguns cálculos e, por isso, o tempo de resposta do Round Robin é normalmente melhor.

###### Multilevel Feedback-Queue
  - Há várias queues de ready com diferentes níveis de prioridade;

Se um processo usa demasiado CPU, então este é movido para uma queue com menos prioridade; Pelo contrário, processos que usam muito I/O e que são interativos, são movidos para a queue 0.
Em relação ao escalonador, só quando todos os processos da queue 0 terminam é que este avança para a queue 1.
Para evitar starvation, os processos que estão numa queue com menos prioridade há mais tempo, passam para queues com mais prioridade.
Importante frisar também que se um processo da queue 1 estiver a executar e se entretanto chega um da queue 0, há desafetação forçada.
Na prática, um processo ready é colocado na queue 0 e é-lhe dado um certo quantum. Se ele não termina dentro desse quantum, é movido para a queue 1 com um quantum maior e assim sucessivamente até chegar à queue 2 (tipicamente aqui é FCFS).
Assim, na queue 0 e na queue 1, temos um misto de Round Robin com SJF (RR dentro da própria queue e SJF quando está a ser executada a queue 1 e chega um da queue 0).

##### Níveis de Escalonamento
**Nível 0** - despacha o que está na ram;
**Nível 1** - decide que processos são multiprogramados;
**Nível 2** - não deixa criar processos.

À medida que o CPU fica sobrecarregado, o nível de escalonamento aumena.

### Sincronização de Processos
#### Race Condition
Race Condition é quando vários processos alteram os mesmos dados concorrentemente. Por exemplo, imaginemos dois processos: um altera o valor da variável x para 1 e outro altera o valor da variável x para 0. Então, se os processos forem executados concorrentemente, o valor final da variável x irá depender da ordem pela qual executamos os processos.
Apresentam-se, de seguida, algumas soluções para o problema.

#### Problema da Região Crítica

#### Semáforos

## DeadLocks

## Memória Central
## Memória Virtual
