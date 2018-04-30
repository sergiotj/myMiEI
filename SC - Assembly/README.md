# Sistemas de Computação - Assembly

Sistema Operativo é um programa ou um conjunto de programas cuja função é gerir os recursos do sistema.

## IA-32

Tem uma palavra de 32 bits. As quantidades de 16 bits são referenciadas como palavras W e as quantidades de 32 bits são referenciadas como palavras L.

### 2 operandos

  - addl %eax, %ebx  | %ebx = %ebx + %eax
  - movl %eax, %ebx  | %ebx = %eax
  - subl %eax, %ebx  | %ebx = %ebx - %eax
  - imull %esi, %esp | %esp = %esp * %esi

### 1 operando

  - incl %ecx  | %ecx = %ecx + 1
  - imull %ecx | %edx:%eax = %eax * %ecx

## Modos de endereçamento

addl %eax, 1000(%ebp, %esi, 4)

Significado: somar a %eax, a palavra (4 bytes) cujo endereço começa em %ebp + %esi * 4 + 1000. Resultado guardado em memória.

andl (, %eax, 8), %edx

Significado: AND da palavra (4 bytes) cujo endereço começa em %eax * 8 com o conteúdo de %edx.

subw %ax, 0x70AA

Significado: subtrair à palavra (2 bytes) cujo endereço começa em 0x70AA o valor de %ax.

### Stack

Estrutura de dados mantida em memória, do tipo LIFO (last in, first out).
O stackpointer (%esp) aponta para o topo da stack e esta cresce de endereços mais altos para endereços mais baixos...

pushl -> subtrai 4 ao %esp e carrega uma palavra para a memória.
popl -> tira uma palavra da stack e soma 4 ao %esp.

### Flags
São 4 e variam conforme o resultado da última operação...
  - ZF = 1 se zero;
  - SF = 1 se menor que zero;
  - CF = 1 se transporte;
  - OF = 1 se overflow.

cmp? src1, src2 significa # src2 - src1. O resultado não é guardado.

test? src1, src2 significa # src2 AND src1. O resultado não é guardado.

### Saltos

#### Saltos incondicionais

  - jmp label;
  - jmp *src.

#### Saltos condicionais (testam as flags)

  - je label
  - js label
  - jg label
  - jl label
  - jne label
  - jns label
  - jge label
  - jle label

### Instruções

  - call label -> coloca o endereço de retorno na stack;
  - ret -> lê endereço de retorno da stack;
  - leave -> realiza algumas operações relacionadas com o acesso a variáveis locais e parâmetros.
