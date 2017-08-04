https://www.ime.usp.br/~pf/algoritmos_para_grafos-2017-04-06/aulas/tarjan.html

## Floresta radicada

*Def:* é um digrafo `topologicamente numerado` sem vértices com grau de entrada maior que 1 (ex: floresta DFS).

Terminologia para falar sobre florestas radicadas:

- Um vértice `u` é ancestral de um vértice `z` se o único caminho que vai de uma raiz até `z` passa por `u`. (um ancestral de `z` é próprio se for diferente de `z`)
- Um vértice `z` é descendente de um vértice `u` se `u` for ancestral de `z`. (um descendente próprio de `u` é próprio se for diferente de `u`)

### Posição relativa dos vértices na floresta DFS

Suponha que pre[] e post[] são as numerações em pré- e pós-ordem de um digrafo G.  Seja F a correspondente floresta DFS de G.  Como já observamos em outra ocasião, se um vértice x é ancestral de um vértice y em F então pre[x] ≤ pre[y].  É claro que se x é ancestral próprio de y então pre[x] < pre[y].  Mas a recíproca dessa afirmação não é verdadeira.  Para completar a caracterização é preciso recorrer à numeração em pós-ordem:

- x é ancestral próprio de y se e somente se pre[x] < pre[y] e post[x] > post[y];
- y é descendente próprio de x se e somente se pre[y] > pre[x] e post[y] < post[x].

Em termos mais informais, x é ancestral próprio de y se e somente se x foi descoberto antes de y durante a busca DFS e morreu depois de x.  Analogamente, y é descendente próprio de x se e somente se y ≡ x ou y foi descoberto depois de x e morreu antes de x.

Dito de outra maneira, x é ancestral próprio de y se o intervalo de tempo durante o qual dfsR(G,x) estava em execução contém propriamente o intervalo durante o qual dfsR(G,y) estava em execução.  Analogamente, y é descendente próprio de x se o intervalo de dfsR(G,y) está propriamente contido no intervalo de dfsR(G,x).

**Primos.**  Uma floresta DFS é mais que uma simples floresta radicada pois além das noções de acima (ancestral) e abaixo (descendente) ela tem as noções de esquerda e direita.  Dados vértices x e y, dizemos que

- x é primo esquerdo de y se pre[x] < pre[y] e post[x] < post[y] e
- y é primo direito de x se pre[y] > pre[x] e post[y] > post[x].

Portanto, x é primo esquerdo de y se x morreu antes de y (e portanto foi descoberto antes de y) durante a busca DFS.  Analogamente, y é primo direito de x se y foi descoberto depois de x (e portanto morreu depois de x).  Dito de outra maneira, x e y são primos se os intervalos de tempo durante os quais dfsR(G,x) e dfsR(G,y) estavam em execução são disjuntos.
