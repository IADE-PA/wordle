# Programação e Algoritmos - IADE UE <!-- omit in toc -->

# Wordle <!-- omit in toc -->

## Objetivos

Pretende-se recriar o jogo Wordle, disponível em <https://www.nytimes.com/games/wordle/index.html>.

No jogo, o objetivo é adivinhar uma palavra alvo com 5 letras. Existem 6 tentativas para adivinhar a palavra e, em cada uma, é necessário indicar uma palavra de 5 letras válida. O jogo deve informar, para cada letra da palavra utilizada na tentativa, se existe na palavra alvo e, se existir, se está na posição correta.

## Tarefas

- [x] Definir instruções do programa;
- [x] Obter listagem de palavras para um ficheiro `.txt`;
- [x] Ler as palavras para um array;
- [x] Escolher uma palavra alvo, aleatoriamente;
- [x] Ler tentativas do utilizador
  - [ ] Verificar se palavra existe na listagem;
  - [ ] verificar correção de cada letra face à palavra alvo;
  - [ ] Informar sobre o resultado da tentativa;
  - [ ] Incrementar o número de tentativas;
  - [ ] Verificar condições de jogo, e continuar/terminar.

### Tarefas extra

- [ ] Adicionar instrução para listas letras ausentes;
- [ ] Adicionar instrução para listas letras ainda não testadas.

## Instruções

1. Permitir escrever palavras assim que o programa inicia

- Indicar número de tentativas atuais
- Indicar com underscore que a letra não existe na palavra alvo
- Indicar com minúscula que a letra existe, mas não está na posição correta
- Indicar com maiúscula que a letra está na posição correta

E.g.:

4 __bdE

- inicia com o número de tentativas atuais
- `_` significa que a letra não existe na palavra;
- minuscula significa que a letra existe na palavra, mas está na posição errada;
- maiuscula significa que a letra está na posição correta.

1. Indicar `Palavra inválida.` se a tentativa não corresponder a uma palavra do dicionário, ou não tiver 5 letras.
2. No caso de sucesso, indicar `Ganhou!`
3. No caso de insucesso, indicar `Perdeu!`
