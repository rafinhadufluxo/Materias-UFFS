# INTRODUÇÃO DO PROJETO

Desenvolver uma aplicação de determinização e minimização (eliminação de mortos 
e inalcançáveis) de autômatos finitos.

## Objetivo

Compreender o processo de determinização/minimização de AFND’s. Implementar funcionalidade 
a ser utilizada na disciplina de compiladores para implementação de analisador léxico.

## Descrição

Entrada: arquivo com a relação de tokens e/ou GRs dos tokens de uma linguagem hipotética.
Saída: Autômato Finito Determinístico (AFD) e livre de estados mortos e inalcançáveis.

A aplicação executa a carga de tokens (palavras reservadas, operadores, símbolos especiais, ...) e Gramáticas Regulares (GR) a partir de um arquivo fonte (texto). 

Exemplo de arquivo de entrada:

            se
            entao
            senao
            <S> ::= a<A> | e<A> | i<A> | o<A> | u<A>
            <A> ::= a<A> | e<A> | i<A> | o<A> | u<A> | ε




Para cada token e gramática, a aplicação gera o conjunto de transições rotuladas em um único AF durante o procedimento de carga. No AF, apenas o estado inicial é compartilhado entre diferentes tokens/gramáticas. Os demais estados são exclusivos para as transições dos demais símbolos dos tokens e/ou estados das GRs. O AF será indeterminístico quando ocorrer uma ou mais situações em que dois tokens ou sentenças definidas por GR iniciam pelo mesmo símbolo.

