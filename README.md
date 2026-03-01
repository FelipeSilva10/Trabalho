# Sistema de Rotas Urbanas — UFU Campus Santa Mônica

**Disciplina:** Estrutura de Dados 2
**Professor:** Renato Pimentel

---

## Equipe e Distribuição de Tarefas

| Integrante                     | Responsabilidade               |
| ------------------------------ | ------------------------------ |
| Eduardo Souza Rocha            | Implementação TAD ABB          |
| Patrick Ramos Barbosa          | Implementação TAD Grafo        |
| Ítalo Lorenzo Resende Cappuzzo | Menu Principal e Algoritmos    |
| Felipe da Conceição Silva      | Arquivo de Entrada e Relatório |

---

## 1. Definição das Estruturas de Dados

O sistema modela o campus como um **grafo não-direcionado ponderado** ( G(V, A) ), com:

* |V| = 10 vértices (locais)
* |A| = 25 arestas (conexões)

### Grafo

* Estrutura conexa, sem vértices isolados.
* Representação por **Lista de Adjacências**, adequada à esparsidade da malha.
* Pesos das arestas representam **distâncias reais em metros**.

### Índice de Busca

Para indexação dos locais:

* Estrutura: **Árvore Binária de Busca (ABB)**
* Chave: `Nome do Local`
* Valor: `ID Numérico`

---

## 2. Algoritmos Implementados

As funcionalidades do menu utilizam algoritmos clássicos:

* **Menor Rota:** Algoritmo de Dijkstra (pesos não-negativos).
* **Árvore Geradora Mínima:** Algoritmo de Prim (conexão total com custo mínimo).

---

## 3. Listagem dos Locais

Os vértices são armazenados na ABB e exibidos em **ordem alfabética** (percurso em-ordem).

| ID | Nome (Chave ABB) | Características           |
| -- | ---------------- | ------------------------- |
| 2  | 1B               | FACOM                     |
| 6  | 3Q               | Livraria, Auditório       |
| 4  | Biblioteca       | Repositório Institucional |
| 5  | Centro_Esportivo | Campo de futebol          |
| 9  | Consultoria      | ESAJUP                    |
| 7  | Editora_UFU      | Editora universitária     |
| 3  | LTAD             | Laboratório               |
| 1  | Museu_Mineral    | Cultura                   |
| 0  | Reitoria         | Administração central     |
| 8  | RU               | Provisório, PROAE         |

---

## 4. Representação Visual

### Figura 1 — Grafo G(V, A)

> Estrutura topológica do grafo com pesos nas arestas (distâncias em metros).

![Grafo G(V,A)](ufu%20mapa/grafo_abstrato.png)

---

### Figura 2 — Contexto Geográfico

> Pontos reais do Campus Santa Mônica utilizados como vértices para coleta das distâncias.

![Contexto Geográfico](ufu%20mapa/ufu_mapa.png)
