# **Máquina de Vendas (C)** 🛒🍫

Este é um programa simples em linguagem **C** que simula uma **máquina de vendas de snacks**. Ele permite ao usuário inserir dinheiro, visualizar produtos disponíveis e realizar compras. Projeto criado com fins **didáticos** e para prática com **GitHub**.

---

## **Funcionalidades** ⚙️

- 💸 Inserção de saldo com notas reais (R$2, R$5, R$10, etc.)
- 📋 Listagem de produtos com nome, preço e estoque
- 🛍️ Compra de múltiplas unidades (caso haja saldo e estoque)
- ❌ Mensagens de erro em caso de saldo insuficiente ou produto esgotado
- 💻 Suporte a Windows e Linux para limpar tela e pausar execução

---

## **Como Executar** ▶️

1. Clone o repositório:
   ```bash
   git clone https://github.com/pedrossoledade/treino-02.git
   cd treino-02
   ```

2. Compile o código:
   ```bash
   gcc vendas.c -o vendas
   ```

3. Execute:
   ```bash
   ./vendas
   ```

> 🪟 No Windows, use:
> ```bash
> gcc vendas.c -o vendas.exe
> vendas.exe
> ```

---

## **Pré-requisitos** 📦

- ✅ Compilador C (como `gcc`, `clang` ou equivalente)
- ✅ Terminal ou prompt de comando compatível

---

## **Estrutura de Produto** 🧱

Cada item é representado por um `struct` com nome, preço e estoque:

```c
typedef struct {
    char nome[20];
    float preco;
    int estoque;
} Produto;
```

---

## **Demonstração** 💻🍬

```bash
********** Máquina de Vendas **********
Saldo: R$6.00
Produtos disponíveis:
1. Refrigerante    - R$6.00 (Em estoque: 10)
2. Chocolate       - R$4.00 (Em estoque: 20)
3. Salgadinho      - R$5.00 (Em estoque: 15)
4. Suco            - R$6.00 (Em estoque: 12)
0. Sair

Escolha o número do produto: 2
Escolha a quantidade do produto: 1
Você comprou: 1 Chocolate(s)
```
