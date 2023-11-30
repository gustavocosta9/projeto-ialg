# Projeto IALG: Leitura e Escrita de Arquivos Binários em uma Consulta Farmacêutica 💊🔍

****

Nome: Gustavo Costa

Curso: Ciências da Computação

Universidade Federal de Lavras (UFLA)


****

# Objetivo do trabalho 🎯
O projeto de introdução aos algoritmos teve como objetivo colocar os conhecimentos básicos aprendidos durante o período como: laços de repetição, condicionais, recursividade, operações booleanas e outras operações em prática. Ademais, pelo impacto da COVID-19 nas Universidades Federais do Brasil, o calendário letivo foi encurtado e por isso uma das exigências na construção do trabalho foi o aprendizado autodidata sobre a exportação/importação, escrita e leitura de arquivos binários em C++ com o uso de ponteiros de escrita e leitura, fato que na época, trouxe bastante trabalho porém grande aprendizado.



<img src="https://i.ibb.co/smBynG0/cursos-de-programacao-para-iniciantes.jpg">


****

## Visão Geral do Código 👀

O pensamento foi - modularizar o código para manter as boas práticas - portanto, foram criadas diversas funções cada uma com o seu objetivo para o bom funcionamento do programa. Vale ressaltar que, nessa época o conceito de modularizar entre diferentes arquivos .cpp e .hpp em C++ ainda não tinham sido introduzidos, levando a manter todas as funções no mesmo arquivo 'main.cpp'.

<img src="https://i.ibb.co/r5XjyhR/Captura-de-tela-2023-11-29-201943.png">


## Função por Função 📃

### binarioInicio

Consiste na leitura do arquivo .csv (planilha) e escrita diretamente dos dados no arquivo binário, foi necessário realizar o tratamento de linha por linha utilizando a biblioteca stringstream que permitiu trabalhar melhor com a partição das linhas.

<img src="https://i.ibb.co/nCRrX43/Captura-de-tela-2023-11-29-202659.png">

### adicionarNovo

Essa função é a responsável pela adição de um novo medicamento (produto) na base de dados e, ao final, a utilização do ponteiro de escrita para inserir no arquivo binário já existente.

<img src="https://i.ibb.co/fx3ZnC6/Captura-de-tela-2023-11-29-203023.png">

### buscaID

Função responsável pela busca de um ID pertencente à um produto na base de dados, foi utilizado o ponteiro de leitura do arquivo binário que salta o número de bytes do tamanho da base, assim é possível realizar a busca diretamente no arquivo pelo ID procurado.

<img src="https://i.ibb.co/YWZc5j9/Captura-de-tela-2023-11-29-203254.png">

### buscaCusto

Função responsável pela busca de um produto pelo preço de custo, é similar à função buscaID. Lembrando que também é necessário a verificação da flag de um produto se ele está disponível ou não.

<img src="https://i.ibb.co/4PRhCGL/Captura-de-tela-2023-11-29-203902.png">

### busca

Função responsável por imprimir na tela o menu que fornece ao usuário duas opções de busca: busca pelo ID ou busca pelo preço de custo.

<img src="https://i.ibb.co/q99B1wc/Captura-de-tela-2023-11-29-204432.png">

### deletaProduto

A função deletaProduto é utilizada para 'deletar' um produto do arquivo binário, entretanto, no trabalho não era para deletar de fato. Era necessário ter uma espécie de 'backup'. Logo, pensei em realizar uma flag, caso seja True o produto existe, caso contrário, o produto está deletado.

<img src="https://i.ibb.co/hm4MwVN/Captura-de-tela-2023-11-29-204512.png">

### intercala_codigo

O intercala_codigo faz parte do processo de mergeSort_codigo, algoritmo de ordenação.

<img src="https://i.ibb.co/3c0ZwMP/Captura-de-tela-2023-11-29-204927.png">

### intercala_preco

O intercala_preco faz parte do processo de mergeSort_preco, algoritmo de ordenação.

<img src="https://i.ibb.co/6PjQBcj/Captura-de-tela-2023-11-29-205127.png">

### mergesort_codigo

O mergeSort_codigo é a função responsável pela ordenação dos códigos dos produtos.

<img src="https://i.ibb.co/R36K63C/Captura-de-tela-2023-11-29-205210.png">

### mergesort_preco

O mergeSort_preco é a função responsável pela ordenação dos preços dos produtos.

<img src="https://i.ibb.co/vqnbV1F/Captura-de-tela-2023-11-29-205438.png">

### ordenacao

A função ordenacao tem como objetivo realizar a opção do usuário escolher o tipo de ordenação desejada dos dados (preço ou código) e, logo após isso, o arquivo binário é reescrito de forma ordenada

<img src="https://i.ibb.co/whQc1BD/Captura-de-tela-2023-11-29-205526.png">

### impressao

Função que oferece ao usuário a oportunidade de imprimir um trecho específico do conjunto de dados ou imprimir todos.

<img src="https://i.ibb.co/tLYyWKt/Captura-de-tela-2023-11-29-205737.png">

### exportacao

Função responsável por exportar diretamente do arquivo binário os dados para uma planilha .csv

<img src="https://i.ibb.co/4FK9mJr/Captura-de-tela-2023-11-29-210004.png">

### main

Parte principal do programa, que chama as funções e as executa dependendo da escolha do usuário no menu interativo.

<img src="https://i.ibb.co/9NfqFvQ/Captura-de-tela-2023-11-29-210119.png">

****
# Conclusão
O trabalho foi bem interessante, principalmente por me fazer desenvolver um senso crítico de procurar soluções para o problema proposto, além de aprimorar minhas habilidades no auto aprendizado com a busca pelos ensinamentos de escritas em arquivos binários com a utilização de ponteiros em C++. 
***
