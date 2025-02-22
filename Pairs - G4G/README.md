problem: https://www.hackerrank.com/contests/prepareforfinalexam/challenges/pairs-g4g/problem

Имате магически масив от числа, този масив може да го разбивате по ваш избор на групи от по 1 елемент или от по 2 елемента. Например: [2,3,4] => може да го разбиете на (2,3),(4) или (2),(3),(4) или (2,4),(3) и т.н

Знае се също че след крайното разбиване на групи, умножаваме всички елементи които са в една група и накрая сумираме произведенията на групите. Например: имаме масив [2,3,4] ако разбием масива на (2,3), 4, то получаваме (2*3),(4) => 6 + 4 => 10

Ако разбием масива на (2),(3),(4) то получаваме 2 + 3 + 4 => 9

Може би забелязвате че при различни видове групиране получавате понякога различен отговор, това което се иска от вас е да върнете максималната сума на групи която може да се получи ако използваме оптимална стратегия на групиране.

Input Format

На вход ще получите число T - брой на тестовете

За всеки тест на нов ред ще получите число N ( размер на масива ), следват N числа разделени с интервал.

Constraints

Броят на тестовете е <= 200
Ограничения: N <= 63
Всяко число е между -2222 и 2222 включително.
Output Format

За всеки тест да се изведе максималната сума която може да получите чрез оптимално групиране

Sample Input 0

2

5

3 4 5 2 1

3

3 2 1

Sample Output 0

27

7

Explanation 0

За тест #1: Оптималната стратегия е: 1 + (2*3) + (4*5) => 27

За тест #2: Оптималната стратегия е: 1 + (2*3) => 7
