# Media_Temperaturas
Projeto em C que calcula as temperaturas máximas, mínimas e médias de um mês em vários anos.

Definição do Projeto:

1 Definição

Considere que um arquivo cont´em dados hist´oricos sobre temperaturas em uma
certa regi˜ao. Esses dados est˜ao arranjados em conjuntos de cinco valores, correspondendo ao ano e mˆes (dois inteiros), temperatura m´ınima naquele mˆes,
temperatura m´edia naquele ano e temperatura m´axima (trˆes valores reais).
Com esses dados determine valores m´edios hist´oricos de temperatura para
essa regi˜ao.

2 O que deve ser feito

Escreva um programa que leia o arquivo de entrada, denominado “temps.dat”,
e escreva um segundo arquivo, denominado “medias.dat” contendo doze linhas,
uma para cada mˆes do ano, contendo o n´umero do mˆes, a m´edias das m´ınimas, a
m´ınima recorde, a m´edia das m´edias, a m´edia das m´aximas e a m´axima recorde,
sendo os valores de recorde escritos entre parˆenteses.
Use fun¸c˜oes para determinar os valores recorde e tamb´em os valores de m´edia.

3 Entrada de dados

Seu programa deve executar considerando que o arquivo de entrada cont´em um
conjunto de linhas compostas por dados relativos a um certo ano e mˆes, sem
qualquer tipo de ordena¸c˜ao entre as linhas. Cada linha est´a organizada na forma
“ano mˆes m´ınima m´edia m´axima”, como vemos a seguir:
1978 3 23,4 27,5 38,9
1825 2 22,1 23,0 24,2
2008 12 11,8 18,3 20,9
E garantido que exista pelo menos uma medida para cada mês do ano.

4 Saída de dados

Seu programa deve produzir o arquivo “medias.dat”, com doze linhas contendo mˆes, m´edia de m´ınimas, (recorde m´ınima), m´edia das m´edias, m´edia
das m´aximas, (recorde m´aximo), como visto a seguir:
1 23,2 (18,7) 26,8 30,1 (34,3)
2 22,2 (15,8) 27,1 31,5 (37,3)
3 23,2 (23) 27,4 35,0 (38,9)
